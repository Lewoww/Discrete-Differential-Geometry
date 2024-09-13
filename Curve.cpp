#include "Curve.h"


Curve::Curve() : scale1(1), scale2(1) {}


void Curve::addArest(const Arest& arest) {
    arestas.push_back(arest);
}

void Curve::printCurve() const {
    std::cout << "Curve:" << std::endl;
    for (const auto& arest : arestas) {
        arest.printArest();
    }
}

void Curve::setScale(float x, float y) {
    scale1 = x;
    scale2 = y;
}

void Curve::drawCurve() const {
    for (const auto& arest : arestas) {
        arest.drawArest(scale1, scale2);
    }
}

size_t Curve::getNumArestas() const {
    return arestas.size();
}
