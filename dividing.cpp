#include "dividing.h"

dividing::dividing(float x, float y) : x(x), y(y) {}

//SObrecarga dos operadores
dividing dividing::operator + (const dividing& other) const {
    float newX = this->x * other.y + other.x * this->y;
    float newY = this->y * other.y;
    return dividing(newX, newY);
}

dividing dividing::operator - (const dividing& other) const {
    float newX = this->x * other.y - other.x * this->y;
    float newY = this->y * other.y;
    return dividing(newX, newY); 
}

dividing dividing::operator * (const dividing& other) const {
    float newX = this->x * other.x;
    float newY = this->y * other.y;
    return dividing(newX, newY);
}

dividing dividing::operator / (const dividing& other) const {
    float newX = this->x * other.y;
    float newY = this->y * other.x;
    return dividing(newX, newY);
}

dividing& dividing::operator = (const dividing& other) {
    if (this != &other) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

// Métodos auxiliares
float dividing::getX() const {
    return x;
}

float dividing::getY() const {
    return y;
}

float dividing::calculate() const {
    if (y != 0) {
        return x / y;
    }
    else {
        return 0;
    }
}
