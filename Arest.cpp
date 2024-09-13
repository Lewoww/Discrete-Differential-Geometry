#include "Arest.h"



Arest::Arest(const std::string& color, const Point& p1, const Point& p2)
    : color(""), p1(p1), p2(p2) {
    length(p1, p2);
}

Arest::Arest(const Point p1, const Point p2) : color(""), p1(p1), p2(p2) {
    length(p1, p2);
}

Point Arest::getP1() const { return p1; }

void Arest::setP1(const Point& p1) { this->p1 = p1; }

Point Arest::getP2() const { return p2; }

void Arest::setP2(const Point& p2) { this->p2 = p2; }


std::string Arest::getColor() const { return color; }

void Arest::setColor(const std::string& color) { this->color = color; }

void Arest::printArest() const {
    std::cout << "Arest:" << std::endl;
    p1.printPoint();
    p2.printPoint();
    std::cout << "Color: " << color << std::endl;
}

void Arest::drawArest(float s1, float s2) const {
    float x1 = p1.getX() / s1;
    float y1 = p1.getY() / s2;
    float x2 = p2.getX() / s1;
    float y2 = p2.getY() / s2;

    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);  // Cor verde
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}


void Arest::length(const Point& p1, const Point& p2)
{
    _length = sqrt((p1.getX() - p2.getX()) + (p1.getY() - p2.getY()));
}
