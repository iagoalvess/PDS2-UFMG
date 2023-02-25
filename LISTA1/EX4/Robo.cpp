#include "Robo.hpp"

Robo::Robo(int id, Ponto2D pR, bool com_bola){
    this->_id = id;
    this->_pR = pR;
    this->_com_bola = com_bola;
};

void Robo::mover(double v, double th, double t){
    double vx = v * cos(th);
    double vy = v * sin(th);

    double dx = vx * t;
    double dy = vy * t;

    this->_pR._x += dx;
    this->_pR._y += dy;

    double totalpercorrido = v * t;
    _energia -= totalpercorrido;
};

double Robo::calcular_distancia(Robo* robo){

    return this->_pR.calcularDistancia(&robo->_pR);

};

Robo* Robo::determinar_robo_mais_proximo(Robo** naves, int n){
    int robomaisproximo = 0;
    double menordistancia = 5000;

    for(int i = 0; i < n; i++){
        if (menordistancia > calcular_distancia(naves[i]) && 
            ((naves[i])->_pR._x != this->_pR._x || (naves[i])->_pR._y != this->_pR._y))
        {
            menordistancia = calcular_distancia(naves[i]);
            robomaisproximo = i;
        }
    }

    return naves[robomaisproximo];
};

void Robo::passar_bola(Robo** time, int n){
    Robo *proximo = this->determinar_robo_mais_proximo(time, n);
    Robo *aux = proximo->determinar_robo_mais_proximo(time, n);

    if(aux->_com_bola == 0){
        cout << "Estou sem a bola!" << endl;
    }
    else{
        proximo->_com_bola = 1;
        aux->_com_bola = 0;
    }
};

void Robo::imprimir_status(){

    cout << _id << "\t" << _pR._x <<  "\t" << _pR._y <<  "\t" << _com_bola << "\t" << _energia << endl;

};



