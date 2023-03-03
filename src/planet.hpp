#include <SFML/Graphics.hpp>
#include <math.h>

#define G 6.67408 * pow(10, -11)
#define SUN_MASS 1.989 * pow(10, 30)
#define PLANET_COUNT 8
#define SCALE 100000

class Planet
{
private:
    long long int distance;
    int distance_shape;
    int radius_shape;
    sf::CircleShape shape;
    sf::Vector2f position;
    double angular_velocity;

public:
    void update(double time, int width, int height);
    void draw(sf::RenderWindow &window);
    void setDistance(long long int distance);
    void setDistanceShape(int distance_shape);
    void setRadiusShape(int radius_shape);
    void setFillColor(sf::Color color);
    void setPosition(sf::Vector2f position);
    void setAngularVelocity(double angular_velocity);
    long long int getDistance();
    int getDistanceShape();
    int getRadiusShape();
    void getFillColor();
    sf::Vector2f getPosition();
    double getAngularVelocity();

    Planet(long long int distance, int distance_shape, int radius_shape, sf::Vector2f position);
};
