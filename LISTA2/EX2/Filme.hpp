#ifndef FILME_H
#define FILME_H

#include "Review.hpp"

#include <iostream>
#include <vector>

class Filme {
private:
  int _id;
  int _duracao;

  std::string _nome;
  std::string _genero;

  std::vector<Review> _reviews;

public:
  Filme();

  Filme(int id, std::string nome, std::string genero, int duracao);

  Review* adicionar_review(std::string comentario, float nota);

  float nota_media();

  void imprimir_nota_consolidada();

  std::string conseguir_nome();
};

#endif