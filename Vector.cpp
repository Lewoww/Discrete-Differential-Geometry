#include "Vector.h"
#include "Point.h"

//Construtor padrão
Vector::Vector() : p(Point()), _length(0.0f) {}

// Construtor que recebe dois pontos
Vector::Vector(const Point& point1, const Point& point2) {
    //diferença entre os dois pontos
    p = Point(point2.getX() - point1.getX(), point2.getY() - point1.getY());
    //comprimento do vetor resultante
    length();
}

// Construtor que recebe um ponto
Vector::Vector(const Point& point) : p(point), _length(0.0f) {
    length();
}

Point Vector::getVector() const
{
	return p;
}

float Vector::getLength() const
{
    return _length;
}

void Vector::length()
{
    _length = sqrt(p.getX() * p.getX() + p.getY() * p.getY());
}

float Vector::dotProduct(const Vector& other) const
{
    Point v1 = getVector();
    Point v2 = other.getVector();
    return v2.getX() * v1.getX() + v2.getY() * v1.getY();
}

Vector Vector::unitVector() const
{
    if (_length == 0) {
        std::cerr << "Vetor não pode ser normalizado." << std::endl;
        return Vector();
    }
    Point unitPoint(p.getX() / _length, p.getY() / _length);
    return Vector(unitPoint);
}
