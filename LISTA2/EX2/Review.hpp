#ifndef REVIEW_H
#define REVIEW_H

#include <iomanip>
#include <string>

class Filme;

class Review {
private:
  Filme *_filme;
  std::string _comentario;
  float _nota;

public:
  Review();

  Review(Filme *filme, std::string comentario, float nota);

  void imprimir_reviews();

  float conseguir_nota();
};

#endif
