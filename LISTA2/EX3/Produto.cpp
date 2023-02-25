#include "Produto.hpp"

Produto::Produto(int id, float valor_unitario) : 
  _id(id), _valor_unitario(valor_unitario) {}

Produto::~Produto() {}

int Produto::get_id() {
  return(this->_id);
}

float Produto::get_valor_unitario() {
  return(_valor_unitario);
}