#ifndef AREST_H
#define AREST_H

#include "Point.h"
#include <GLFW/glfw3.h>
#include <string>

class Arest {
private:
    Point p1;
    Point p2;
    float _length;
    std::string color;

public:
    Arest(const std::string& color = "", const Point& p1 = Point(), const Point& p2 = Point()); //lenght precisa ser calculado, não passado
    Arest(Point p1, Point p2);


    // Métodos auxiliares

    Point getP1() const;
    void setP1(const Point& p1);

    Point getP2() const;
    void setP2(const Point& p2);

    std::string getColor() const;
    void setColor(const std::string& color);

    void printArest() const;
    void drawArest(float s1, float s2) const;

    void length(const Point& p1, const Point& p2);
};

#endif
