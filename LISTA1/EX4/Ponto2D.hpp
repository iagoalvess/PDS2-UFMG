#ifndef PONTO2D_H
#define PONTO2D_H

#include <iostream>
#include <cmath>

struct Ponto2D {
    double _x;
    double _y;

    Ponto2D(double x = 0, double y = 0);

    double calcularDistancia(Ponto2D* p2);
};

#endif