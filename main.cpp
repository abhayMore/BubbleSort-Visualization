#include "SFML/Graphics.hpp"
#include <iostream>
#define WIDTH 400
#define HEIGHT 300

void swap(sf::RectangleShape &a, sf::RectangleShape &b)
{
    float temp = a.getSize().y;
    a.setSize(sf::Vector2f(1, b.getSize().y));
    b.setSize(sf::Vector2f(1, temp));
}

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "BubbleSort");
    sf::RectangleShape Lines[WIDTH / 2];

   // window.setFramerateLimit(480);
    float x = 0, y = 0;

    bool flag = true;
    for (auto &shape : Lines)
    {

        y = -(rand() % (290) + 2);
        shape.setSize(sf::Vector2f(1, y));
        shape.setPosition(x, HEIGHT);
        x += 2;
    }

    int i = 0;
    int j = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if (Lines[j].getSize().y < Lines[j + 1].getSize().y)
        {
            swap(Lines[j], Lines[j+1]);
        }

        for (int i = 0; i < WIDTH / 2; i++)
        {
            window.draw(Lines[i]);
        }

        if (i < WIDTH / 2 - 1)
        {
            j++;
            if (j >= WIDTH / 2 - i -1 )
            {
                j = 0;
                i++;
            }
        }
        else
        {
            
            window.close();
        }

        window.display();
    }
    
}
