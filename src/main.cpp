#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <ctime>
#include <vector>
#include "planet.hpp"

#define PLUS 1
#define MINUS -1

struct Planet_name{
    std::string name;
    sf::Color color;
};

void updateDelta(double *delta, double *scale, int sens){
    if(sens == PLUS){
        *delta *= 2;
        *scale /= 2;
    }else if(sens == MINUS){
        if (*scale < 960){
            *delta /= 2;
            *scale *= 2;
        }
    }
}

int main(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(desktop.width, desktop.height), "Solar System");
    window.setFramerateLimit(60);

    const int n = 500;
    const float radius = 1.f;
    const sf::Color color = sf::Color::White;
    std::vector<sf::Vector2f> points(n);
    for (int i = 0; i < n; i++)
    {
        const float x = static_cast<float>(std::rand() % window.getSize().x);
        const float y = static_cast<float>(std::rand() % window.getSize().y);

        points[i] = sf::Vector2f(x, y);
    }

    sf::CircleShape sun;
    sun.setRadius(30);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(sf::Vector2f(desktop.width / 2 - sun.getRadius(), desktop.height / 2 - sun.getRadius() - 50));

    Planet planets[PLANET_COUNT] = {
        Planet((long int) 57.91 * SCALE, (desktop.height / 2 - 100) / 8 * 1, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 1 - 10, desktop.height / 2 - 10 - 50), -1), //Mercury
        Planet((long int) 108.2 * SCALE, (desktop.height / 2 - 100) / 8 * 2, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 2 - 10, desktop.height / 2 - 10 - 50), -1), //Venus
        Planet((long int) 149.6 * SCALE, (desktop.height / 2 - 100) / 8 * 3, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 3 - 10, desktop.height / 2 - 10 - 50), -1), //Earth
        Planet((long int) 227.9 * SCALE, (desktop.height / 2 - 100) / 8 * 4, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 4 - 10, desktop.height / 2 - 10 - 50), -1), //Mars
        Planet((long int) 778.5 * SCALE, (desktop.height / 2 - 100) / 8 * 5, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 5 - 10, desktop.height / 2 - 10 - 50), 1), //Jupiter
        Planet((long int) 1400 * SCALE, (desktop.height / 2 - 100) / 8 * 6, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 6 - 10, desktop.height / 2 - 10 - 50), 1), //Saturn
        Planet((long int) 2900 * SCALE, (desktop.height / 2 - 100) / 8 * 7, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 7 - 10, desktop.height / 2 - 10 - 50), 1), //Uranus
        Planet((long int) 4500 * SCALE, (desktop.height / 2 - 100) / 8 * 8, 10, sf::Vector2f(desktop.width / 2 + (desktop.height / 2 - 100) / 8 * 8 - 10, desktop.height / 2 - 10 - 50), 1) //Neptune
    };

    planets[0].setFillColor(sf::Color(128, 128, 128, 255));
    planets[1].setFillColor(sf::Color(255, 165, 0, 255));
    planets[2].setFillColor(sf::Color(0, 0, 255, 255));
    planets[3].setFillColor(sf::Color(255, 0, 0, 255));
    planets[4].setFillColor(sf::Color(255, 255, 150, 255));
    planets[5].setFillColor(sf::Color(218, 165, 32, 255));
    planets[6].setFillColor(sf::Color(0, 191, 255, 255));
    planets[7].setFillColor(sf::Color(104, 0, 250, 255));

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
        circles[i].setOutlineThickness(1.f);
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
        {"Neptune", sf::Color(104, 0, 250, 255)}
    };

    sf::Font font;
    if (!font.loadFromFile("src/arial.ttf")) {
        std::cerr << "Impossible to charge the arial.ttf font" << std::endl;
        return EXIT_FAILURE;
    }

    sf::RectangleShape buttonPlus(sf::Vector2f(75, 75));
    buttonPlus.setFillColor(sf::Color(0, 135, 0, 255));
    buttonPlus.setPosition(window.getSize().x - 100, 10);

    sf::RectangleShape buttonMinus(sf::Vector2f(75, 75));
    buttonMinus.setFillColor(sf::Color(135, 0, 0, 255));
    buttonMinus.setPosition(window.getSize().x - 195, 10);

    sf::RectangleShape rectScale(sf::Vector2f(170, 75));
    rectScale.setFillColor(sf::Color(100, 100, 200, 255));
    rectScale.setPosition(window.getSize().x - 195, 100);

    sf::RectangleShape trajectory(sf::Vector2f(170, 75));
    trajectory.setFillColor(sf::Color(0, 135, 0, 255));
    trajectory.setPosition(window.getSize().x - 195, 190);

    sf::Text textPlus("+", font, 50);
    textPlus.setFillColor(sf::Color::White);
    textPlus.setPosition(buttonPlus.getPosition().x + 10, buttonPlus.getPosition().y + 10);

    sf::Text textMinus("-", font, 50);
    textMinus.setFillColor(sf::Color::White);
    textMinus.setPosition(buttonMinus.getPosition().x + 10, buttonMinus.getPosition().y + 10);

    sf::Text textScale("30s/year", font, 20);
    textScale.setFillColor(sf::Color::White);
    textScale.setPosition(rectScale.getPosition().x + 10, rectScale.getPosition().y + 10);

    sf::Text textTrajectory("Trajectory", font, 20);
    textTrajectory.setFillColor(sf::Color::White);
    textTrajectory.setPosition(trajectory.getPosition().x + 10, trajectory.getPosition().y + 10);

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    text.setPosition(50.f, 10.f);

    double time = 0;
    double delta = (double) 17 / 365 * 12; // 30s = 1 year
    double scale = 30;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (buttonPlus.getGlobalBounds().contains(mousePosition))
                {
                    updateDelta(&delta, &scale, PLUS);
                    textScale.setString(std::to_string((float)scale) + "s/year");
                }

                if (buttonMinus.getGlobalBounds().contains(mousePosition))
                {
                    updateDelta(&delta, &scale, MINUS);
                    textScale.setString(std::to_string((float)scale) + "s/year");
                }

                if (trajectory.getGlobalBounds().contains(mousePosition))
                {
                    if (circles[0].getOutlineThickness() == 1.f){
                        for (int i = 0; i < PLANET_COUNT; i++) circles[i].setOutlineThickness(0.f);
                        textTrajectory.setString("No trajectory");
                        trajectory.setFillColor(sf::Color(135, 0, 0, 255));
                    } else {
                        for (int i = 0; i < PLANET_COUNT; i++) circles[i].setOutlineThickness(1.f);
                        textTrajectory.setString("Trajectory");
                        trajectory.setFillColor(sf::Color(0, 135, 0, 255));
                    }
                }
            }            
        }
        window.clear();

        time += delta;

        for (const auto& point : points)
        {
            sf::CircleShape circle(radius);
            circle.setFillColor(color);
            circle.setPosition(point);
            window.draw(circle);
        }
        
        window.draw(sun);
        for (int i = 0; i < PLANET_COUNT; i++){
            window.draw(circles[i]);
            planets[i].update(time, desktop.width, desktop.height);
            planets[i].draw(window);
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

        window.draw(buttonPlus);
        window.draw(textPlus);
        window.draw(buttonMinus);
        window.draw(textMinus);
        window.draw(rectScale);
        window.draw(textScale);
        window.draw(trajectory);
        window.draw(textTrajectory);

        window.display();
    }
    return 0;
}