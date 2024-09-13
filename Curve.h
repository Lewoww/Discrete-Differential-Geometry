#ifndef CURVE_H
#define CURVE_H

#include "Arest.h"
#include <vector>

class Curve {
private:
    std::vector<Arest> arestas;
    float scale1=1;
    float scale2=1;

public:
    //Construtores
    Curve();

    //Métodos auxiliares
    void addArest(const Arest& arest);
    void printCurve() const;
    void setScale(float x, float y);
    void drawCurve() const;
    size_t getNumArestas() const;
};

#endif
