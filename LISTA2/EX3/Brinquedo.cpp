#include "Brinquedo.hpp"

Brinquedo::Brinquedo(int id, float valor, std::string nome, int idade_minima) : 
  Produto(id, valor), _nome(nome), _idade_minima(idade_minima) {}
  
Brinquedo::~Brinquedo() {}

void Brinquedo::imprimir_info() {
  std::cout << get_id() << "\t" << "Brinquedo" << "\t" << this->_nome << 
  "\t" << this->_idade_minima << "\t" << "R$ " << std::fixed << 
  std::setprecision(2) << get_valor_unitario() << std::endl;
}


