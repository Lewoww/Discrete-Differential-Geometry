#include "Point.h"

//Construtores
Point::Point(float x, float y) : color(""), x(x), y(y) {}
Point::Point(const std::string& color, float x, float y) : color(color), x(x), y(y) {}

//Métodos auxiliares
std::string Point::getColor() const { 
    return color; 
}

void Point::setColor(const std::string& color) { 
    this->color = color;
}

float Point::getX() const { 
    return x; 
}

void Point::setX(float x) { 
    this->x = x; 
}

float Point::getY() const { 
    return y; 
}

void Point::setY(float y) {
    this->y = y; 
}

void Point::printPoint() const {
    std::cout << "Color: " << color << "\n" << "X: " << x << "\n" << "Y: " << y << std::endl;
}

bool Point::isEqual(const Point a, const Point b)
{
    if ((a.getX() == b.getX()) && (a.getY() == b.getY()))
        return true;
    else
        return false;
}
