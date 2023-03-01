#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "planet.hpp"

#define PLANET_COUNT 8
#define SCALE 0.001

int main(){
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "Solar System");
    window.setFramerateLimit(60);

    sf::CircleShape sun;
    sun.setRadius(30);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(sf::Vector2f(desktop.width / 2 - sun.getRadius(), desktop.height / 2 - sun.getRadius()));

    Planet planets[PLANET_COUNT] = {
        Planet(2439 * SCALE, 100, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 100 - 10)), //Mercury
        Planet(6051 * SCALE, 150, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 150 - 10)), //Venus
        Planet(6378 * SCALE, 200, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 200 - 10)), //Earth
        Planet(3393 * SCALE, 250, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 250 - 10)), //Mars
        Planet(71492 * SCALE, 300, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 300 - 10)), //Jupiter
        Planet(60268 * SCALE, 350, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 350 - 10)), //Saturn
        Planet(25559 * SCALE, 400, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 400 - 10)), //Uranus
        Planet(24764 * SCALE, 500, sf::Vector2f(desktop.width / 2 - 10, desktop.height / 2 + 500 - 10)) //Neptune
    };

    for (int i = 0; i < PLANET_COUNT; i++){
        planets[i].setShapeRadius(10);
    }

    planets[0].setFillColor(sf::Color::Green);
    planets[1].setFillColor(sf::Color::Blue);
    planets[2].setFillColor(sf::Color::Green);
    planets[3].setFillColor(sf::Color::Blue);
    planets[4].setFillColor(sf::Color::Green);
    planets[5].setFillColor(sf::Color::Blue);
    planets[6].setFillColor(sf::Color::Green);
    planets[7].setFillColor(sf::Color::Red);

    float time = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        time += 0.00001;
        window.clear();
        window.draw(sun);
        for (int i = 0; i < PLANET_COUNT; i++){
            planets[i].update(time, desktop.width, desktop.height);
            planets[i].draw(window);
        }
        window.display();
    }

    return 0;
}