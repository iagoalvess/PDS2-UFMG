#include "polvo.hpp"

Polvo::Polvo(double qi) : Criatura("Polvo"), _qi(qi) {

  cout << "Polvo: " << _subtipo << endl;

}

Polvo::~Polvo() {

  cout << "~Polvo: " << _subtipo << endl;

}

void Polvo::print_info() {
  Criatura::print_info();

  cout << "\t" << "QI: " << _qi << endl;
}

double Polvo::get_qi() {

  return(_qi);

}

list<unique_ptr<Criatura>> Polvo::acasalar(shared_ptr<Criatura> c) {
  shared_ptr<Polvo> p = dynamic_pointer_cast<Polvo>(c);

  list<unique_ptr<Criatura>> lista{};

  double qi_medio = (p->_qi + this->_qi) / 2;

  if (p->_subtipo == "Polvo") {

    lista.push_back(unique_ptr<Criatura>(new Polvo(qi_medio)));

    return(lista);
  } 
  else {
    return(lista);
  }
}