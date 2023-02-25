#include "Catalogo.hpp"

void Catalogo::adicionar_produto(std::string nome, int idade_minima, float valor) {
  int id = _produtos.size() + 1;

  Produto* produto = new Brinquedo(id, valor, nome, idade_minima);

  _produtos.push_back(produto);
}

void Catalogo::adicionar_produto(std::string titulo, std::string autor, int ano, float valor) {
  int id = _produtos.size() + 1;

  Produto* produto = new Livro(id, valor, titulo, autor, ano);
  _produtos.push_back(produto);
}

void Catalogo::adicionar_produto(std::string marca, std::string modelo, float valor) {
  int id = _produtos.size() + 1;

  Produto* produto = new Eletronico(id, valor, marca, modelo);
  _produtos.push_back(produto);
}

Produto* Catalogo::buscar_produto(int id) {
  for (Produto* produto : _produtos) {
    if (produto->get_id() == id) return(produto);
  }

  std::cout << "Produto não encontrado!" << std::endl;
  return(nullptr);
}

void Catalogo::imprimir() {
  for (Produto* produto : _produtos) {
    produto->imprimir_info();
  }
}

std::vector<Produto*> Catalogo::get_produtos() {
  return(_produtos);
}