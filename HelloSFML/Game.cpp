#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Balls.h"
#include "Canon.h"
#include "Math.h"
#include "Level.h"
#include "Constants.h"
#include "ScoreManager.h"


std::list<Brick*> levelBricks;
ScoreManager* SManager = new ScoreManager();

int main()
{
    sf::Clock clock;
    srand(time(NULL));
    bool move = false;
    bool canshoot = true;
    bool HasCollision = true;
    float NextXPos;
    float NextYPos;

    int ballDamage = 1;
    int index;
 
    sf::FloatRect ballBoundingBox;
    sf::FloatRect brickBoundingBox;
    sf::Vector2i localPosition;
    


    sf::RenderWindow window(sf::VideoMode(Constants::screenWidth, Constants::screenHeight), "Ultimate Breakout");

    //Level generation
    Level* level = new Level(6, 8);
    levelBricks = level->GenerateLevel();
    level->GenerateLevel();

    //Canon generation
    Canon* canon = new Canon(0.5f, 1, 50, 100);

    //Ball generation
    Balls* balls = new Balls(3, ballDamage);
    levelBricks = level->GetBrickList();

    //Score text
    sf::Font font;
    sf::Text text;
    font.loadFromFile("Facon.ttf");
    text.setFont(font); 
    text.setCharacterSize(30);
    text.setPosition(10, Constants::screenHeight-40);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);



        

    
    while (window.isOpen())
    {
        float DeltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        

        text.setString(std::to_string(SManager->GetScore()));

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

        std::list<Ball*>& BallList = balls->GetBallList();
        HasCollision = false;
        std::list<Ball*>::iterator itBall = BallList.begin();
        while (itBall != BallList.end())
        //for (Ball* ball : balls->GetBallList())
        {   
            Ball* ball = *itBall;
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
                brick->RemoveLife(ballDamage);
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

                /*Simple power-up system
                index = (rand() % 3) + 1;

                switch (index)
                {
                case 1:
                    std::cout << "Boost" << std::endl;
                    ballCount++
                    break;

                case 2:
                    std::cout << "De-Boost" << std::endl;
                    ballDamage = 1;
                    break;

                default:
                    break;
                }
                //END of powerup
                */

                //Destroy the brick object
                SManager->AddScore(brick->GetBrickScore());
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

                }

            }
            
            if (ballBoundingBox.top >= Constants::screenHeight + ballBoundingBox.height) {
                canshoot = true;
                

                
                itBall = BallList.erase(itBall);
                delete ball;
                balls->RemoveBall();
                

            }
            else
            {
                ball->SetBallPosition(NextXPos, NextYPos);
                itBall++;
                
            }
        }
     
    
        window.clear();
        for (Ball* ball : BallList)
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