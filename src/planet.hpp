#include <SFML/Graphics.hpp>
#include <math.h>

#define G 6.67408 * pow(10, -11)
#define SUN_MASS 1.989 * pow(10, 30)

class Planet
{
private:
    /* char name[20]; */
    int radius;
    int distance;
    sf::CircleShape shape;
    sf::Vector2f position;
    double angular_velocity = sqrt((G * SUN_MASS) / (pow(distance, 3)));

public:
    void update(float time, int width, int height);
    /* void setName(char name[20]); */
    void setRadius(int radius);
    void setPosition(sf::Vector2f position);
    void setDistance(int distance);
    void setFillColor(sf::Color color);
    void setShapeRadius(int shapeRadius);
    /* char *getName(); */
    int getRadius();
    int getDistance();
    void getFillColor();
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow &window);

    Planet(/* char *name,  */int radius, int distance, sf::Vector2f position);
};
