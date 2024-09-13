#include "Point.h"
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <cmath>

class Vector {
private:
    Point p;
    float _length;

    void length();
public:
    Vector();                                           // Construtor padrão
    Vector(const Point& point1,  const Point& point2);   // Construtor que recebe dois pontos
    Vector(const Point& point);                         // Construtor que recebe um ponto

    Point getVector() const;

    float getLength() const;

    float dotProduct(const Vector& other) const;

    Vector unitVector() const;
};
