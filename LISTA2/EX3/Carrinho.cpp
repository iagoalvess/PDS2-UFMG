#include "Carrinho.hpp"

void Carrinho::adicionar_pedido(Produto* produto, int quantidade) {
  Pedido* pedido = new Pedido(produto, quantidade);

  _pedidos.push_back(pedido);
}

void Carrinho::imprimir_resumo() {
  for (Pedido* p : _pedidos) {
    p->get_produto()->imprimir_info();

    valor_total += p->get_valor_total();

    std::cout << "Qtde: " << p->get_quantidade() << "\t" << 
    "Total produto: R$ " << p->get_valor_total() << std::endl;
  }

  std::cout << "Total carrinho: R$ " << std::fixed << 
  std::setprecision(2) << valor_total << std::endl;
}

std::vector<Pedido*> Carrinho::get_pedidos() {
  return(_pedidos);
}