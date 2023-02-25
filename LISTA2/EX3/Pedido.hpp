#ifndef PEDIDO_H
#define PEDIDO_H

#include "Produto.hpp"

class Pedido {
  private:
    Produto* _produto;
    int _quantidade;
  
  public:
    Pedido(Produto* produto, int quantidade);

    Produto* get_produto();
    
    int get_quantidade();
    double get_valor_total();
};

#endif