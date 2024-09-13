#ifndef DIVIDING_H
#define DIVIDING_H

class dividing
{
private:
    float x; 
    float y; 

public:
    dividing(float x = 0, float y = 1);

    // Sobrecarga dos operadores
    dividing operator + (const dividing& other) const; 
    dividing operator - (const dividing& other) const; 
    dividing operator * (const dividing& other) const;
    dividing operator / (const dividing& other) const;
    dividing& operator = (const dividing& other);

    // Métodos auxiliares
    float getX() const;
    float getY() const;
    float calculate() const;
};

#endif
