#include "avaliacao_basica_ecommerce.hpp"

int main() {
  std::string nome, titulo, marca, modelo, autor;
  int idade, ano, id, quantidade;
  float valor;

  Catalogo catalogo;
  Carrinho carrinho;

  char opcao;

  while (std::cin >> opcao) {
    switch (opcao) {

      case 'q':
        cin >> nome;
        cin >> idade;
        cin >> valor;

        catalogo.adicionar_produto(nome, idade, valor);

        break;

      case 'l':
        cin >> titulo;
        cin >> autor;
        cin >> ano;
        cin >> valor;

        catalogo.adicionar_produto(titulo, autor, ano, valor);

        break;

      case 'e':
        cin >> marca;
        cin >> modelo;
        cin >> valor;

        catalogo.adicionar_produto(marca, modelo, valor);

        break;

      case 'c':
        catalogo.imprimir();

        break;

      case 'p':
        cin >> id;
        cin >> quantidade;

        if (catalogo.buscar_produto(id) != nullptr) {
          carrinho.adicionar_pedido(catalogo.buscar_produto(id), quantidade);
        }

        break;

      case 'r':
        carrinho.imprimir_resumo();

        break;

      case 'b':
        avaliacao_basica();

        break;
    }
  }

  for (Pedido* p : carrinho.get_pedidos()) {
    delete(p);
  }
  for (Produto *p : catalogo.get_produtos()){
    delete(p);
  }

  return(0);
}