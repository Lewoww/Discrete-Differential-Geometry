#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>

class Point {
private:
    std::string color;
    float x;
    float y;
public:
    Point(float x = 0.0f, float y = 0.0f);
    Point(const std::string& color, float x, float y);
    

    // Métodos auxiliares

    std::string getColor() const;
    void setColor(const std::string& color);
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    void printPoint() const;

    bool isEqual(const Point a, const Point b);

};

#endif
