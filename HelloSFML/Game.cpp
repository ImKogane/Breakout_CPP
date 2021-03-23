#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"


int main()
{
    float x = 300;
    float y = 900;
    bool move = false;

    sf::RenderWindow window(sf::VideoMode(600, 900), "SFML works!");
    Ball* ball = new Ball(50, x, y);
    sf::CircleShape* ballShape = new sf::CircleShape(ball->GetShape());
    ball->SetBallOrigin(50.0f, 100.0f);

    while (window.isOpen())
    {
        sf::Event event;

        if (move) {
            y -= 0.1f;

            if (y <= 0) //If the ball out of the screen
            {
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
                    ball->SetBallPosition(x, y);
                    move = true;
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