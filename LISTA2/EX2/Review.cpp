#include "Review.hpp"
#include "Filme.hpp"

Review::Review() {}

Review::Review(Filme *filme, std::string comentario, float nota) : 
  _filme(filme), _comentario(comentario), _nota(nota) {}

void Review::imprimir_reviews() {
  std::cout << _filme->conseguir_nome() << "\t" << this->_comentario << "\t" 
  << std::fixed << std::setprecision(1) << this->_nota << std::endl;
}

float Review::conseguir_nota() {
  return this->_nota;
} 