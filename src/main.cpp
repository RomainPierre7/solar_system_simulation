#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <math.h>

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "Space Gravity");
    window.setFramerateLimit(60);
    sf::CircleShape main_planet(50.f);
    main_planet.setFillColor(sf::Color::Green);
    main_planet.setPosition(desktop.width/2 - 100, desktop.height/2 - 200);
    sf::CircleShape moon(10.f);
    moon.setFillColor(sf::Color::White);
    moon.setPosition(main_planet.getPosition().x + 500, main_planet.getPosition().y);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Gravity
        sf::Vector2f gravity = main_planet.getPosition() - moon.getPosition();
        float distance = sqrt(pow(gravity.x, 2) + pow(gravity.y, 2)) * 50000000000;
        float force = (6.67408 * pow(10, -11) * 5.972 * pow(10, 24) * 7.348 * pow(10, 22)) / pow(distance, 2);
        gravity.x = gravity.x / distance;
        gravity.y = gravity.y / distance;
        gravity.x = gravity.x * force;
        gravity.y = gravity.y * force;
        moon.move(gravity);

        window.clear();
        window.draw(main_planet);
        window.draw(moon);
        window.display();
        }

    return 0;
}