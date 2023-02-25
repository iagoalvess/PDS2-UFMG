#include "peixe.hpp"

Peixe::Peixe(double peso, char sexo) : Criatura("Peixe"), _peso(peso), _sexo(sexo) {

  cout << "Peixe: " << _subtipo << endl;

}

Peixe::~Peixe() {

  cout << "~Peixe: " << _subtipo << endl;

}

double Peixe::get_peso() {

  return(this->_peso);

}

char Peixe::get_sexo() {

  return(this->_sexo);

}

void Peixe::print_info() {
  Criatura::print_info();

  cout << "\t" << "Peso: " << _peso << " kg" << endl;

  cout << "\t" << "Sexo: " << _sexo << endl;
}

list<unique_ptr<Criatura>> Peixe::acasalar(shared_ptr<Criatura> c) {
  shared_ptr<Peixe> p = dynamic_pointer_cast<Peixe>(c);

  list<unique_ptr<Criatura>> lista{};

  if (p->_subtipo == "Peixe" && p->get_sexo() != this->get_sexo()) {
    
    double peso_filhos = (p->get_peso() + this->get_peso()) / 2;

    lista.push_back(unique_ptr<Criatura>(new Peixe(peso_filhos, 'F')));
    lista.push_back(unique_ptr<Criatura>(new Peixe(peso_filhos, 'M')));

    return(lista);
  }
  else {
    return(lista);
  }
}