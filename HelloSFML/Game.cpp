#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"
#include "Math.h"


int main()
{
    float x = 300;
    float y = 900;
    bool move = false;
    bool canshoot = true;
    sf::Vector2i localPosition;
    
    sf::Vector2f direction;
    

    sf::RenderWindow window(sf::VideoMode(600, 900), "SFML works!");
    Ball* ball = new Ball(50, x, y);
    sf::CircleShape* ballShape = new sf::CircleShape(ball->GetShape());
    ball->SetBallOrigin(50.0f, 100.0f);

    while (window.isOpen())
    {
        sf::Event event;

        if (move) {
            x += 0.1f * direction.x;
            y += 0.1f * direction.y;

            if (y <= 0) //If the ball out of the screen
            {
                canshoot = true;
                move = false;
                x = 300; 
                y =  900;
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
        window.display();
    }

    return 0;
}