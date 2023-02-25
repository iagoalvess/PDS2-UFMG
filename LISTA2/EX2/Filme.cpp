#include "Filme.hpp"

Filme::Filme() {}

Filme::Filme(int id, std::string nome, std::string genero, int duracao) : 
  _id(id), _nome(nome), _genero(genero), _duracao(duracao) {}

Review * Filme::adicionar_review(std::string comentario, float nota) {
  Review* r = new Review(this, comentario, nota);
  this->_reviews.push_back(*r);

  return(r);
}

float Filme::nota_media() { 
  float num_reviews = _reviews.size();
  float nota_total = 0;

  for (Review r : this->_reviews) {
    nota_total += r.conseguir_nota();
  }

  if (num_reviews == 0) return(0);
  
  return (nota_total/num_reviews);
}

void Filme::imprimir_nota_consolidada() {
  std::cout << this->_nome << "\t" << "Reviews: " << _reviews.size() << "\t" 
  << "Nota media: " << std::fixed << std::setprecision(1) << nota_media() 
  << std::endl;
}

std::string Filme::conseguir_nome() {
  return this->_nome;
}