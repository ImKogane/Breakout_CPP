#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include "Ball.h"
#include "Math.h"
#include "Level.h"
#include "Constants.h"

Level* level = new Level(3, 5);
std::list<Brick*> levelBricks;


int main()
{


    bool move = false;
    bool canshoot = true;

 
    sf::FloatRect ballBoundingBox;
    sf::FloatRect brickBoundingBox;
    sf::Vector2i localPosition;
    
    sf::Vector2f direction;

    levelBricks = level->GenerateLevel();

    sf::RenderWindow window(sf::VideoMode(Constants::screenWidth, Constants::screenHeight), "Ultimate Breakout");

    Ball* ball = new Ball(20);
    Constants::BallPositionRatio(ball, 0.5, 1);

    Brick* brick = new Brick(100, 50, 5);
    Constants::BrickPositionRatio(brick, 0.5, 0.5);
    brickBoundingBox = brick->GetBrickBoundingBox();
    brick->SetBrickColor();


    float x = ball->GetShape().getPosition().x;
    float y = ball->GetShape().getPosition().y;

    Constants::BallOriginByRatio(ball, 0.5, 1);
    ballBoundingBox = ball->GetBallBoundingBox();

    while (window.isOpen())
    {
        sf::Event event;
        


        /*std::cout << ballBoundingBox.left << std::endl;
        std::cout << ballBoundingBox.top << std::endl;
        std::cout << brickBoundingBox.left << std::endl;
        std::cout << brickBoundingBox.top << std::endl;*/

        ballBoundingBox = ball->GetBallBoundingBox();
        if (ballBoundingBox.intersects(brickBoundingBox))
        {
            //std::cout << "ça touche" << std::endl;
            float Dtop = abs(ballBoundingBox.top - brickBoundingBox.top - brickBoundingBox.height);
            float Dleft = abs(ballBoundingBox.left - brickBoundingBox.left - brickBoundingBox.width);
            float Dbottom = abs(ballBoundingBox.top - brickBoundingBox.top + ballBoundingBox.height);
            float Dright = abs(ballBoundingBox.left - brickBoundingBox.left + ballBoundingBox.width);
            float mini= Dtop;
            float tab[] = { Dleft, Dbottom,Dright };
            
            for (size_t i = 0; i < 3; i++)
            {
                if (tab[i] < mini)
                {
                    mini = x;
                }
            }

            if (Dtop <= Dleft && Dtop <= Dright && Dtop <= Dbottom )
            {
                direction.y = -direction.y;
                std::cout << "bas" << std::endl;
            }
            else if (Dleft <= Dright && Dleft <= Dbottom && Dleft <= Dtop)
            {
                direction.x = -direction.x;
                std::cout << "droite" << std::endl;
            }
            else if (Dright <= Dbottom && Dright <= Dleft && Dright <= Dtop)
            {
                direction.x = -direction.x;
                //std::cout << "gauche" << std::endl;
            }
            else if (Dbottom <= Dleft && Dbottom <= Dtop && Dbottom <= Dright)
            
            {
                direction.y = -direction.y;
                std::cout << "haut" << std::endl;
            }

        }

        //Ball movement
        if (move) {
            x += 0.1f * direction.x;
            y += 0.1f * direction.y;

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
                    std::cout << canshoot;
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
        
        
        /*
        * Pour chaque brick dans la liste recu apres la generation, dessiner le forme à la position en fonction du nombre de brick par ligne
        for each (vector c in MyString)
        {

        }
        
        */

        
        window.clear();
        window.draw(ball->GetShape());
        window.draw(brick->GetBrickShape());
        window.display();
    }

    return 0;
}