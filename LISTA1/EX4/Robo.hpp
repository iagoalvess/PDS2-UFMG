#ifndef ROBO_H
#define ROBO_H

#include "Ponto2D.hpp"
#include <iostream>

using namespace std;

struct Robo {
    double _energia = 100;

    bool _com_bola;

    int _id;

    Ponto2D _pR;

    Robo(int id, Ponto2D pR, bool com_bola);

    void mover(double v, double th, double t); 

    double calcular_distancia(Robo* robo);

    Robo* determinar_robo_mais_proximo(Robo** naves, int n);

    void passar_bola(Robo** time, int n);

    void imprimir_status(); 
};

#endif


