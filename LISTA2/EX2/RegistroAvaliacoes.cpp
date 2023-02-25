#include "RegistroAvaliacoes.hpp"

void RegistroAvaliacoes::adicionar_usuario(std::string login, std::string nome) {
  _usuarios.insert(std::pair<std::string, Usuario>(login, Usuario(login, nome)));
}

void RegistroAvaliacoes::adicionar_filme(
  std::string nome, 
  std::string genero, 
  int duracao) {
  
  int id_filme = _filmes.size() + 1;

  _filmes.insert(std::pair<int, Filme>(id_filme, Filme(id_filme, nome, genero, duracao)));
}

void RegistroAvaliacoes::adicionar_review(
  int id_filme, 
  std::string login_usuario, 
  std::string comentario, 
  float nota) {

  auto it = _filmes.find(id_filme);
  it->second.adicionar_review(comentario, nota);

  Review* review = new Review(&it->second, comentario, nota);

  auto it_2 = _usuarios.find(login_usuario);
  it_2->second.associar_review(review);

  delete(review);
}

void RegistroAvaliacoes::imprimir_estatisticas_usuarios() {
  std::map<std::string, Usuario>::iterator it;
  for (it = _usuarios.begin(); it != _usuarios.end(); it++)
  {
    it->second.imprimir_info();
  }
}

void RegistroAvaliacoes::imprimir_registro_geral() {
  std::map<int, Filme>::iterator it;
  for (it = _filmes.begin(); it != _filmes.end(); it++)
  {
    it->second.imprimir_nota_consolidada();
  }
}

void RegistroAvaliacoes::imprimir_reviews_usuario(std::string login) {
  auto it = _usuarios.find(login);
  it->second.imprimir_reviews();
}