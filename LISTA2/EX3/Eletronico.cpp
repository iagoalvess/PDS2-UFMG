#include "Eletronico.hpp"

Eletronico::Eletronico(int id, float valor, std::string marca, std::string modelo) :
  Produto(id, valor), _marca(marca), _modelo(modelo) {}

Eletronico::~Eletronico() {}

void Eletronico::imprimir_info() {
  std::cout << get_id() << "\t" << "Eletronico" << "\t" << this->_marca << "\t"
  << this->_modelo << "\t" << "R$ " << std::fixed << std::setprecision(2) 
  << get_valor_unitario() << std::endl;
}