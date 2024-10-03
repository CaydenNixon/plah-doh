#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::Vector2u windowSize (1280, 720);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "plah doh");
    sf::Vector2f size(100, 100);

    window.setFramerateLimit(120);

    sf::Vector2f position(1, 1);

    sf::Texture texture;
    texture.loadFromFile("FetPest.jfif");
    sf::Sprite sprite;
    sprite.setScale(size.x / texture.getSize().x, size.y / texture.getSize().y);
    sprite.setTexture(texture);

    int XD = 1;
    int YD = 1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        int count = 0;

        if (position.x > windowSize.x - size.x)
        {
            XD = -1;
            count++;
        }
        if (position.x <= 0)
        {
            XD = 1;
            count++;
        }
        if (position.y > windowSize.y - size.y)
        {
            YD = -1;
            count++;
        }
        if (position.y <= 0)
        {
            YD = 1;
            count++;
        }

        if (count >= 2)
        {
            XD = 0;
            YD = 0;
        }

        position.x = position.x + XD;

        position.y = position.y + YD;

        sprite.setPosition(position);

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}