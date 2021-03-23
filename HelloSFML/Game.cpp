#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Math.h"
#include "Constants.h"


int main()
{

    const int screenWidth = Constants::screenWidth;
    const int screenHeight = Constants::screenHeight;


    bool move = false;
    bool canshoot = true;

 
    sf::FloatRect ballBoundingBox;
    sf::Vector2i localPosition;
    
    sf::Vector2f direction;
    

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");
    Ball* ball = new Ball(100);
    Constants::BallPositionRatio(ball, 0.5, 1);

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

            if (y - ballBoundingBox.height <= 0 || x - ballBoundingBox.width/2  <= 0  || x >= screenWidth - ballBoundingBox.width/2 || y>= screenHeight+ ballBoundingBox.height) //If the ball out of the screen
            {    
                if(y - ballBoundingBox.height <= 0  )
                 {
                    direction.y = -direction.y;

                 }
                if(x - ballBoundingBox.width/2  <= 0 ||x >= screenWidth - ballBoundingBox.width/2)
                 {
                    direction.x = -direction.x;

                 }
                if (y >= screenHeight+ ballBoundingBox.height) {
                    canshoot = true;
                    move = false;
                    x = screenWidth/2;
                        y = screenHeight;
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
        ballBoundingBox = ball->GetBallBoundingBox();
        window.clear();
        window.draw(ball->GetShape());
        window.display();
    }

    return 0;
}