#ifndef CARRINHO_H
#define CARRINHO_H

#include "Produto.hpp"
#include "Pedido.hpp"

#include <iostream>
#include <vector>
#include <iomanip>

class Carrinho {
  private:
    std::vector<Pedido*> _pedidos;
    float valor_total = 0;

  public:
    void adicionar_pedido(Produto* produto, int quantidade);
    void imprimir_resumo();

    std::vector<Pedido*> get_pedidos();
};

#endif