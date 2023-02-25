#ifndef BRINQUEDO_H
#define BRINQUEDO_H

#include "Produto.hpp"

#include <iomanip>
#include <iostream>

class Brinquedo : public Produto {
  private:
    std::string _nome;
    int _idade_minima;
  
  public:
    Brinquedo(int id, float valor, std::string nome, int idade_minima);
    ~Brinquedo();

    void imprimir_info() override;
};

#endif