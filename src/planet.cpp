#include "planet.hpp"

Planet::Planet(/* char name[],  */int radius, int distance, sf::Vector2f position){
    /* this->name = name; */
    this->radius = radius;
    this->distance = distance;
    this->position = position;
    shape.setRadius(radius);
    shape.setPosition(position);
}

void Planet::update(float time, int width, int height){
    double angular = angular_velocity * time;
    sf::Vector2f newPosition = sf::Vector2f(width / 2 + distance * cos(angular),height / 2 + distance * sin(angular));
    shape.setPosition(newPosition);
}

/* void Planet::setName(char name[20]){
    this->name = name;
} */

void Planet::setRadius(int radius){
    this->radius = radius;
}

void Planet::setPosition(sf::Vector2f position){
    this->position = position;
}

void Planet::setDistance(int distance){
    this->distance = distance;
}

void Planet::setFillColor(sf::Color color){
    shape.setFillColor(color);
}

void Planet::setShapeRadius(int shapeRadius){
    shape.setRadius(shapeRadius);
}

/* char *Planet::getName(){
    return name;
} */

int Planet::getRadius(){
    return radius;
}

int Planet::getDistance(){
    return distance;
}

void Planet::getFillColor(){
    shape.getFillColor();
}

sf::Vector2f Planet::getPosition(){
    return position;
}

void Planet::draw(sf::RenderWindow &window){
    window.draw(shape);
}