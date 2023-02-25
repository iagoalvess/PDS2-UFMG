#include "Livro.hpp"

Livro::Livro(int id, float valor, std::string titulo, std::string autor, int ano) :
  Produto(id, valor), _titulo(titulo), _autor(autor), _ano(ano) {}

Livro::~Livro() {}

void Livro::imprimir_info() {
  std::cout << get_id() << "\t" << "Livro" << "\t" << this->_titulo << "\t"
  << this->_autor << "\t" << this->_ano << "\t" << "R$ " << std::fixed 
  << std::setprecision(2) << get_valor_unitario() << std::endl;
}

