#include "Pedido.hpp"

Pedido::Pedido(Produto* produto, int quantidade) : 
  _produto(produto), _quantidade(quantidade) {}

int Pedido::get_quantidade() {
  return(this->_quantidade);
}

double Pedido::get_valor_total() {
  float valor_total_pedido = _produto->get_valor_unitario() * _quantidade;
  
  return(valor_total_pedido);
}

Produto* Pedido::get_produto() {
  return(this->_produto);
}