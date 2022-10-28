#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;

int main() {

    RenderWindow win(VideoMode(858, 525), "Pong");

    win.setFramerateLimit(60);

    RectangleShape leftPaddle;

    const int leftPaddleX = 0;

    int leftPaddleY = 200;

    leftPaddle.setSize(Vector2f(25, 125));

    leftPaddle.setFillColor(Color::White);

    RectangleShape rightPaddle;

    const int rightPaddleX = 833;

    int rightPaddleY = 200;

    rightPaddle.setSize(Vector2f(25, 125));

    rightPaddle.setFillColor(Color::White);

    RectangleShape ball;

    int x = 404, y = 237;
    
    int speedX = 3, speedY = 3;

    ball.setSize(Vector2f(25, 25));

    ball.setFillColor(Color::White);

    while (win.isOpen())
    {
        Event e;

        while (win.pollEvent(e))
        {
            if (e.type == Event::Closed) win.close();

            if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                win.close();

            }
            else if (Keyboard::isKeyPressed(Keyboard::W) && leftPaddleY - 20 >= 0)
            {
                leftPaddleY -= 20;

            } 
            else if (Keyboard::isKeyPressed(Keyboard::S) && leftPaddleY < 400)
            {
                leftPaddleY += 20;

            }
            else if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                rightPaddleY -= 20;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Down))
            {
                rightPaddleY += 20;
            }

        }

        if (y < 0 || y > 500)
        {
            speedY *= -1;

        }
        else if ((y > rightPaddleY && y < rightPaddleY + 125) && x > 808)
        {
            if (y >= rightPaddleY && y <= rightPaddleY + 125)
            {
                speedX += 0.5;
                speedX *= -1;
            }

        }
        else if ((x >= leftPaddleX && x <= leftPaddleX + 25) && x < 25)
        {
            if (y >= leftPaddleY && y <= leftPaddleY + 125)
            {
                speedX += 0.5;
                speedX *= -1;
            }
            
        }
        else if (x < 0)
        {
            x = 404, y = 237;

            speedX = 3;
        }

        x += speedX;

        y += speedY;

        ball.setPosition(Vector2f(x, y));

        leftPaddle.setPosition(Vector2f(leftPaddleX, leftPaddleY));

        rightPaddle.setPosition(Vector2f(rightPaddleX, rightPaddleY));

        win.clear();

        win.draw(leftPaddle);

        win.draw(rightPaddle);

        win.draw(ball);

        win.display();
        
    }
    
}