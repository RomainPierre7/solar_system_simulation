#include "planet.hpp"

Planet::Planet(long long int distance, int distance_shape, int radius_shape, sf::Vector2f position){
    this->distance = distance;
    this->distance_shape = distance_shape;
    this->radius_shape = radius_shape;
    this->position = position;
    shape.setRadius(radius_shape);
    shape.setPosition(position);
}

void Planet::update(double time, int width, int height){
    float angular = angular_velocity * time;
    sf::Vector2f newPosition = sf::Vector2f(width / 2 - 10 + distance_shape * cos(angular),height / 2 - 10 - 50 + distance_shape * sin(angular));
    shape.setPosition(newPosition);
    setPosition(newPosition);
}

void Planet::draw(sf::RenderWindow &window){
    window.draw(shape);
}

void Planet::setDistance(long long int distance){
    this->distance = distance;
}

void Planet::setDistanceShape(int distance_shape){
    this->distance_shape = distance_shape;
}

void Planet::setRadiusShape(int radius_shape){
    this->radius_shape = radius_shape;
}

void Planet::setFillColor(sf::Color color){
    shape.setFillColor(color);
}

void Planet::setPosition(sf::Vector2f position){
    this->position = position;
}

void Planet::setAngularVelocity(double angular_velocity){
    this->angular_velocity = angular_velocity;
}

long long int Planet::getDistance(){
    return distance;
}

int Planet::getDistanceShape(){
    return distance_shape;
}

int Planet::getRadiusShape(){
    return radius_shape;
}

void Planet::getFillColor(){
    shape.getFillColor();
}

sf::Vector2f Planet::getPosition(){
    return position;
}

double Planet::getAngularVelocity(){
    return angular_velocity;
}