#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "planet.hpp"

struct Planet_name{
    std::string name;
    sf::Color color;
};

int main(){
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "Solar System");
    window.setFramerateLimit(60);

    sf::CircleShape sun;
    sun.setRadius(30);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(sf::Vector2f(desktop.width / 2 - sun.getRadius(), desktop.height / 2 - sun.getRadius() - 50));

    Planet planets[PLANET_COUNT] = {
        Planet(57.91 * SCALE, (desktop.height / 2 - 100) / 8 * 1, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 1 - 10, desktop.height / 2 - 10 - 50)), //Mercury
        Planet(108.2 * SCALE, (desktop.height / 2 - 100) / 8 * 2, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 2 - 10, desktop.height / 2 - 10 - 50)), //Venus
        Planet(149.6 * SCALE, (desktop.height / 2 - 100) / 8 * 3, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 3 - 10, desktop.height / 2 - 10 - 50)), //Earth
        Planet(227.9 * SCALE, (desktop.height / 2 - 100) / 8 * 4, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 4 - 10, desktop.height / 2 - 10 - 50)), //Mars
        Planet(778.5 * SCALE, (desktop.height / 2 - 100) / 8 * 5, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 5 - 10, desktop.height / 2 - 10 - 50)), //Jupiter
        Planet(1400 * SCALE, (desktop.height / 2 - 100) / 8 * 6, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 6 - 10, desktop.height / 2 - 10 - 50)), //Saturn
        Planet(2900 * SCALE, (desktop.height / 2 - 100) / 8 * 7, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 7 - 10, desktop.height / 2 - 10 - 50)), //Uranus
        Planet(4500 * SCALE, (desktop.height / 2 - 100) / 8 * 8, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 8 - 10, desktop.height / 2 - 10 - 50)) //Neptune
    };

    planets[0].setFillColor(sf::Color(128, 128, 128, 255));
    planets[1].setFillColor(sf::Color(255, 165, 0, 255));
    planets[2].setFillColor(sf::Color(0, 0, 255, 255));
    planets[3].setFillColor(sf::Color(255, 0, 0, 255));
    planets[4].setFillColor(sf::Color(255, 255, 150, 255));
    planets[5].setFillColor(sf::Color(218, 165, 32, 255));
    planets[6].setFillColor(sf::Color(0, 191, 255, 255));
    planets[7].setFillColor(sf::Color(0, 0, 139, 255));

    for (int i = 0; i < PLANET_COUNT; i++){
        planets[i].setAngularVelocity(sqrt((G * SUN_MASS) / (pow(planets[i].getDistance(), 3))));
    }

    sf::CircleShape circles[PLANET_COUNT] = {
        sf::CircleShape(planets[0].getDistanceShape()),
        sf::CircleShape(planets[1].getDistanceShape()),
        sf::CircleShape(planets[2].getDistanceShape()),
        sf::CircleShape(planets[3].getDistanceShape()),
        sf::CircleShape(planets[4].getDistanceShape()),
        sf::CircleShape(planets[5].getDistanceShape()),
        sf::CircleShape(planets[6].getDistanceShape()),
        sf::CircleShape(planets[7].getDistanceShape())
    };

    for (int i = 0; i < PLANET_COUNT; i++){
        circles[i].setPointCount(100);
        circles[i].setFillColor(sf::Color::Transparent);
        circles[i].setOutlineColor(sf::Color::White);
        circles[i].setOutlineThickness(1);
        circles[i].setPosition(desktop.width / 2 - planets[i].getDistanceShape(), desktop.height / 2 - planets[i].getDistanceShape() - 50);
    }

    std::vector<Planet_name> planets_name = {
        {"Sun", sf::Color::Yellow},
        {"Mercury", sf::Color(128, 128, 128, 255)},
        {"Venus", sf::Color(255, 165, 0, 255)},
        {"Earth", sf::Color(0, 0, 255, 255)},
        {"Mars", sf::Color(255, 0, 0, 255)},
        {"Jupiter", sf::Color(255, 255, 150, 255)},
        {"Saturn", sf::Color(218, 165, 32, 255)},
        {"Uranus", sf::Color(0, 191, 255, 255)},
        {"Neptune", sf::Color(0, 0, 139, 255)}
    };

    sf::Font font;
    if (!font.loadFromFile("src/arial.ttf")) {
        std::cerr << "Impossible to charge the arial.ttf font" << std::endl;
        return EXIT_FAILURE;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    text.setPosition(50.f, 10.f);

    double time = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        time += 0.1;
        window.draw(sun);
        for (int i = 0; i < PLANET_COUNT; i++){
            planets[i].update(time, desktop.width, desktop.height);
            planets[i].draw(window);
            window.draw(circles[i]);
        }

        for (int i = 0; i < planets_name.size(); i++) {
            text.setString(planets_name[i].name);
            text.move(0.f, i * 55.f);

            sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
            rect.setFillColor(planets_name[i].color);
            rect.setPosition(text.getPosition().x - 60, text.getPosition().y);

            window.draw(text);
            window.draw(rect);

            text.move(0.f, -i * 55.f);
        }

        window.display();
    }
    return 0;
}