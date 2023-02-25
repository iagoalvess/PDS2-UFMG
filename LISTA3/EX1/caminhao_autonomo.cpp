#include "caminhao_autonomo.hpp"

CaminhaoAutonomo::CaminhaoAutonomo(
  int velo_max, int n_passageiros, int carga_max, std::string fabricante) :
  Caminhao("CaminhaoAutonomo", velo_max, n_passageiros, carga_max), 
  _fabricante(fabricante) {}

CaminhaoAutonomo::~CaminhaoAutonomo() {
  std::cout << "Destrutor CaminhaoAutonomo" << std::endl;
} 

int CaminhaoAutonomo::estima_preco() {
  int preco = 0;

  if (_fabricante == "Tesla") {
    preco = 500000 + (100*_carga_max) + (10*_velo_max);
  } 

  if (_fabricante == "Waymo") {
    preco = 400000 + (100*_carga_max) + (10*_velo_max);
  }

  return(preco);
}

void CaminhaoAutonomo::print_info() {
  Caminhao::print_info();
  
  std::cout << "\t"<< "Fabricante: " << _fabricante << std::endl;
}