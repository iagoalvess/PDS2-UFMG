#include "veiculo.hpp"

int Veiculo::_next_id = 1;

Veiculo::Veiculo(std::string subtipo, int velo_max, int n_passageiros) :
  _subtipo(subtipo), _velo_max(velo_max), _n_passageiros(n_passageiros) {
  this->_id = _next_id;
  _next_id ++;
}

Veiculo::~Veiculo() {
  std::cout << "Destrutor Veiculo" << std::endl;
}

int Veiculo::get_id() {
  return(_id);
}

void Veiculo::print_info() {
  std::cout << "Info: Veiculo " << _id << std::endl;

  std::cout << "Preco estimado: RS " << estima_preco() << ",00" << std::endl;

  std::cout << "\t" << "Subtipo: " << _subtipo << std::endl;

  std::cout << "\t" << "Velocidade maxima: " << _velo_max << " km/h" << std::endl;

  std::cout << "\t" << "Capacidade de passageiros: " << _n_passageiros << std::endl;
}