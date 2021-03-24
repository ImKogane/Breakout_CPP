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
    sf::Vector2i localPosition;
    
    sf::Vector2f direction;

    levelBricks = level->GenerateLevel();

    sf::RenderWindow window(sf::VideoMode(Constants::screenWidth, Constants::screenHeight), "Ultimate Breakout");

    Ball* ball = new Ball(20);
    Constants::BallPositionRatio(ball, 0.5, 1);

    /* Tentative de création d'une brique à afficher par la suite
    Brick* brick = new Brick(10, 5, 1);
    Constants::BrickPositionRatio(brick, 0.5, 0.5);
    brick->SetBrickColor(sf::Color::Green);
    */

    float x = ball->GetShape().getPosition().x;
    float y = ball->GetShape().getPosition().y;

    sf::CircleShape* ballShape = new sf::CircleShape(ball->GetShape());
    Constants::BallOriginByRatio(ball, 0.5, 1);
    ballBoundingBox = ball->GetBallBoundingBox();

    while (window.isOpen())
    {
        sf::Event event;

        if (move) {
            x += 0.1f * direction.x;
            y += 0.1f * direction.y;

            if (y - ballBoundingBox.height <= 0 || x - ballBoundingBox.width/2  <= 0  || x >= Constants::screenWidth - ballBoundingBox.width/2 || y>= Constants::screenHeight+ ballBoundingBox.height) //If the ball out of the screen
            {    
                if(y - ballBoundingBox.height <= 0  )
                 {
                    direction.y = -direction.y;

                 }
                if(x - ballBoundingBox.width/2  <= 0 ||x >= Constants::screenWidth - ballBoundingBox.width/2)
                 {
                    direction.x = -direction.x;

                 }
                if (y >= Constants::screenHeight+ ballBoundingBox.height) {
                    canshoot = true;
                    move = false;
                    x = Constants::screenWidth/2;
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

        ballBoundingBox = ball->GetBallBoundingBox();
        window.clear();
        window.draw(ball->GetShape());
        //Test d'affichage d'une brique  : window.draw(brick->GetBrickShape());
        window.display();
    }

    return 0;
}