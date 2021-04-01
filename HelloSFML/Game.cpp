#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include "Balls.h"
#include "Canon.h"
#include "Math.h"
#include "Level.h"
#include "Constants.h"
#include "GameManager.h"


std::list<Brick*> levelBricks;
GameManager* GManager = new GameManager();

int main()
{
    sf::Clock clock;
    srand(time(NULL));
    bool move = false;
    bool canshoot = true;
    bool HasCollision = true;
    float NextXPos;
    float NextYPos;
 
    sf::FloatRect ballBoundingBox;
    sf::FloatRect brickBoundingBox;
    sf::Vector2i localPosition;
    
    //sf::Vector2f direction;

    Level* level = new Level(6, 8);
    levelBricks = level->GenerateLevel();

    sf::RenderWindow window(sf::VideoMode(Constants::screenWidth, Constants::screenHeight), "Ultimate Breakout");

    level->GenerateLevel();

    //Canon generation
    Canon* canon = new Canon(0.5f, 1, 50, 100);

    //Ball generation
    //Ball* ball = new Ball(10);
    Balls* balls = new Balls(3);
    /*Constants::BallPositionRatio(ball, 0.5, 1);
    //Get the ball position
    float x = ball->GetShape().getPosition().x; 
    float y = ball->GetShape().getPosition().y;
    Constants::BallOriginByRatio(ball, 0.5, 1);
    ballBoundingBox = ball->GetBallBoundingBox();*/
    levelBricks = level->GetBrickList();


    sf::Font font;
    sf::Text text;
    font.loadFromFile("Facon.ttf");
    // choix de la police à utiliser
    text.setFont(font); // font est un sf::Font

    // choix de la chaîne de caractères à afficher
    // choix de la taille des caractères
    text.setCharacterSize(30); // exprimée en pixels, pas en points !
    text.setPosition(10, Constants::screenHeight-40);

    // choix de la couleur du texte
    text.setFillColor(sf::Color::White);

    // choix du style du texte
    text.setStyle(sf::Text::Bold);



        


    while (window.isOpen())
    {
        float DeltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        

        text.setString(std::to_string(GManager->GetScore()));

        //For each brick in level
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //Mouse left click event
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    
                    if (balls->GetCurrentBallCount()< balls->GetBallsSize())
                    {   
                            Ball* ball = balls->AddBall();
                            localPosition = sf::Mouse::getPosition(window);
                            //direction.x = (float)localPosition.x - ball->GetBallXPosition();
                            //direction.y = (float)localPosition.y - ball->GetBallYPosition();
                            ball->SetDirection((float)localPosition.x - ball->GetBallXPosition(), (float)localPosition.y - ball->GetBallYPosition());
                            //Math::Normalize(direction);
                            move = true;
                            canshoot = false;
                    }

                    
                }
            }
        }

        HasCollision = false;
        for (Ball* ball : balls->GetBallList())
        {
            ballBoundingBox = ball->GetBallBoundingBox();
            std::list<Brick*>::iterator it = levelBricks.begin();

            while (it != levelBricks.end())
            //for (Brick* brick : levelBricks)
            {
                Brick* brick = *it;
                brickBoundingBox = brick->GetBrickBoundingBox();
                if (Math::ContainsBrick(ball->GetCollisionBrickList(), brick) )
                {
                    ++it;
                    continue;
                }

                if (ballBoundingBox.intersects(brickBoundingBox) == false ) 
                {
                    ++it;
                    continue;
                }
                

                //When the ball collide with a brick
                if(HasCollision == false )
                {
                    ball->ResetCollisionBrickList();
                }

                ball->AddBrick(brick);
                brick->RemoveLife(1);
                float Dtop = abs(ballBoundingBox.top - brickBoundingBox.top - brickBoundingBox.height);
                float Dleft = abs(ballBoundingBox.left - brickBoundingBox.left - brickBoundingBox.width);
                float Dbottom = abs(ballBoundingBox.top - brickBoundingBox.top + ballBoundingBox.height);
                float Dright = abs(ballBoundingBox.left - brickBoundingBox.left + ballBoundingBox.width);

                if (HasCollision == false )
                {
                    if (Dtop <= Dleft && Dtop <= Dright && Dtop <= Dbottom)
                    {
                        ball->YOppositeDirection();
                        //std::cout << "Bottom collision." << std::endl;
                    }
                    else if (Dleft <= Dright && Dleft <= Dbottom && Dleft <= Dtop)
                    {
                        ball->XOppositeDirection();
                        std::cout << "Right collision." << std::endl;
                    }
                    else if (Dright <= Dbottom && Dright <= Dleft && Dright <= Dtop)
                    {
                        ball->XOppositeDirection();
                        std::cout << "Left collision." << std::endl;
                    }
                    else if (Dbottom <= Dleft && Dbottom <= Dtop && Dbottom <= Dright)
                    {
                        ball->YOppositeDirection();
                        std::cout << "Top collision." << std::endl;
                    }
                }

                HasCollision = true;

                if (brick->GetBrickLife() >  0) 
                {
                    ++it;
                    continue;
                }

                //Destroy the brick object
                GManager->AddScore(brick->GetBrickScore());
                it = levelBricks.erase(it);
                delete brick;
            }

            //Ball movement
            if (move) {
                NextXPos =ball->GetBallXPosition() +1000 * DeltaTime * ball->GetDirection().x;
                NextYPos = ball->GetBallYPosition() +1000 * DeltaTime * ball->GetDirection().y;

                if (ballBoundingBox.top <= 0 || ballBoundingBox.left <= 0 || ballBoundingBox.left + ballBoundingBox.width >= Constants::screenWidth || ballBoundingBox.top >= Constants::screenHeight + ballBoundingBox.height) //If the ball out of the screen
                {
                    ball->ResetCollisionBrickList();
                    if (ballBoundingBox.top <= 0 && ball->GetDirection().y < 0)
                    {
                        ball->YOppositeDirection();


                    }
                    if (ballBoundingBox.left + ballBoundingBox.width >= Constants::screenWidth && ball->GetDirection().x > 0)
                    {
                        ball->XOppositeDirection();
                    }
                    if (ballBoundingBox.left <= 0 && ball->GetDirection().x < 0)
                    {
                        ball->XOppositeDirection();

                    }
                    if (ballBoundingBox.top >= Constants::screenHeight + ballBoundingBox.height) {
                        canshoot = true;
                        
                        balls->RemoveBall(ball);
                        
                    }
                }

            }
            ball->SetBallPosition(NextXPos, NextYPos);
        }
     
    
        window.clear();
        for (Ball* ball : balls->GetBallList())
        {
            window.draw(ball->GetShape());
        }
        
        window.draw(canon->GetCanonShape());
        for (Brick* brick : levelBricks)
        {
            window.draw(brick->GetBrickShape());
        }

        // puis, dans la boucle de dessin, entre window.clear() et window.display()
        window.draw(text);
        window.display();
    }

    return 0;
}