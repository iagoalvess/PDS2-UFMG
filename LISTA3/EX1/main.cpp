#include "veiculo.hpp"
#include "caminhao.hpp"
#include "caminhao_autonomo.hpp"

#include <list>

void rm_id(std::list<Veiculo*> &l, int id) {
  std::list<Veiculo *>::iterator i = l.begin();

  while (i != l.end())
  {
    if ((*i)->get_id() == id)
    {
      delete(*i);
      l.remove(*i++);
    }
    else
    {
      ++i;
    }
  }
}

void print_list(std::list<Veiculo*> l) {
  std::list<Veiculo*>::iterator i = l.begin();

  while (i != l.end())
  {
    (*i)->print_info();
    ++i;
  }
}

int main() {

  std::list<Veiculo*> veiculos;

  std::string opcao;
  std::string fabricante;
  int velocidade;
  int passageiros;
  int carga;
  int id;

  while (std::cin >> opcao) {

    int valor_opcao;

    if (opcao == "add_c") valor_opcao = 1;
    else if (opcao == "add_ca") valor_opcao = 2;
    else if (opcao == "rm") valor_opcao = 3;
    else if (opcao == "print") valor_opcao = 4;

    switch (valor_opcao) {
    case 1: 
      {
        std::cin >> velocidade >> passageiros >> carga;

        Veiculo* v_c = new Caminhao(velocidade, passageiros, carga);
        veiculos.push_back(v_c);
      }
      break;
    
    case 2:
      {
        std::cin >> velocidade >> passageiros >> carga >> fabricante;

        Veiculo* v_ca = new CaminhaoAutonomo(velocidade, passageiros, carga, fabricante);
        veiculos.push_back(v_ca);
      }
      break;

    case 3:
      {
        std::cin >> id;
        rm_id(veiculos, id);
      }
      break;

    case 4:
      {
        print_list(veiculos);
      }
      break;

    default:
      break;
    }
  }

  return(0);
}