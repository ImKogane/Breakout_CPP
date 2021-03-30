#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include "Ball.h"
#include "Math.h"
#include "Level.h"
#include "Constants.h"


std::list<Brick*> levelBricks;


int main()
{


    bool move = false;
    bool canshoot = true;

 
    sf::FloatRect ballBoundingBox;
    sf::FloatRect brickBoundingBox;
    sf::Vector2i localPosition;
    
    sf::Vector2f direction;

    Level* level = new Level(5, 7);
    levelBricks = level->GenerateLevel();

    sf::RenderWindow window(sf::VideoMode(Constants::screenWidth, Constants::screenHeight), "Ultimate Breakout");

    level->GenerateLevel();

    //Ball generation
    Ball* ball = new Ball(10);
    Constants::BallPositionRatio(ball, 0.5, 1);
    level->GenerateLevel();
    //Get the ball position
    float x = ball->GetShape().getPosition().x; 
    float y = ball->GetShape().getPosition().y;
    Constants::BallOriginByRatio(ball, 0.5, 1);
    ballBoundingBox = ball->GetBallBoundingBox();
    

    while (window.isOpen())
    {
        sf::Event event;
        levelBricks = level->GetBrickList();

        ballBoundingBox = ball->GetBallBoundingBox();

        
        //For each brick in level
        for (Brick* brick : levelBricks)

        {
            brickBoundingBox = brick->GetBrickBoundingBox();
            if (brick->GetBrickLife() > 0)
            {
                //When the ball collide with a brick
                if (ballBoundingBox.intersects(brickBoundingBox))
                {

                    brick->RemoveLife(1);
                    float Dtop = abs(ballBoundingBox.top - brickBoundingBox.top - brickBoundingBox.height);
                    float Dleft = abs(ballBoundingBox.left - brickBoundingBox.left - brickBoundingBox.width);
                    float Dbottom = abs(ballBoundingBox.top - brickBoundingBox.top + ballBoundingBox.height);
                    float Dright = abs(ballBoundingBox.left - brickBoundingBox.left + ballBoundingBox.width);

                    if (Dtop <= Dleft && Dtop <= Dright && Dtop <= Dbottom)
                    {
                        direction.y = -direction.y;
                        std::cout << "Bottom collision." << std::endl;
                    }
                    else if (Dleft <= Dright && Dleft <= Dbottom && Dleft <= Dtop)
                    {
                        direction.x = -direction.x;
                        std::cout << "Right collision." << std::endl;
                    }
                    else if (Dright <= Dbottom && Dright <= Dleft && Dright <= Dtop)
                    {
                        direction.x = -direction.x;
                        std::cout << "Left collision." << std::endl;
                    }
                    else if (Dbottom <= Dleft && Dbottom <= Dtop && Dbottom <= Dright)
                    {
                        direction.y = -direction.y;
                        std::cout << "Top collision." << std::endl;
                    }

                    //Destroy the brick object
                    if (brick->GetBrickLife() <= 0)
                    {
                        brick->~Brick();
                    }

                }
            }
        }

        //Ball movement
        if (move) {
            x += 0.2f * direction.x;
            y += 0.2f * direction.y;

            if (ballBoundingBox.top <= 0 || ballBoundingBox.left <= 0 || ballBoundingBox.left + ballBoundingBox.width >= Constants::screenWidth || ballBoundingBox.top >= Constants::screenHeight + ballBoundingBox.height) //If the ball out of the screen
            {
                if (ballBoundingBox.top <= 0 && direction.y < 0)
                {
                    direction.y = -direction.y;


                }
                if (ballBoundingBox.left + ballBoundingBox.width >= Constants::screenWidth && direction.x > 0)
                {
                    direction.x = -direction.x;
                }
                if (ballBoundingBox.left <= 0 && direction.x < 0)
                {
                    direction.x = -direction.x;

                }
                if (ballBoundingBox.top >= Constants::screenHeight + ballBoundingBox.height) {
                    canshoot = true;
                    move = false;
                    x = Constants::screenWidth / 2;
                    y = Constants::screenHeight;
                }
            }

        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //Mouse left click event
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (canshoot)
                      {
                         localPosition = sf::Mouse::getPosition(window);
                         direction.x = (float)localPosition.x-ball->GetBallXPosition();
                         direction.y = (float)localPosition.y-ball->GetBallYPosition();
                         Math::normalize(direction);
                         move = true;
                         canshoot = false;
                        }
                }
            }
        }
        ball->SetBallPosition(x, y);
        


        
        window.clear();
        window.draw(ball->GetShape());
        for (Brick* brick : levelBricks)
        {
            window.draw(brick->GetBrickShape());
        }
        window.display();
    }

    return 0;
}