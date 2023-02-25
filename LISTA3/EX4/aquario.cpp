#include "aquario.hpp"

Aquario::Aquario(const Aquario &orig) {
  for (auto it : orig._criaturas) {

    if (it->get_subtipo() == "Peixe") {

      shared_ptr<Peixe> px = dynamic_pointer_cast<Peixe>(it);

      Peixe* copia_px = new Peixe(*px);

      this->_criaturas.push_back(shared_ptr<Criatura>(copia_px));

    }
    else if (it->get_subtipo() == "Polvo") {

      shared_ptr<Polvo> po = dynamic_pointer_cast<Polvo>(it);

      Polvo* copia_po = new Polvo(*po);

      this->_criaturas.push_back(shared_ptr<Criatura>(copia_po));

    }

  } 
}

void Aquario::add_peixe(double peso, char sexo) {

  _criaturas.push_back(shared_ptr<Criatura>(new Peixe(peso, sexo)));

}

void Aquario::add_polvo(double qi) {

  _criaturas.push_back(shared_ptr<Criatura>(new Polvo(qi)));

}

void Aquario::acasalamento(int id1, int id2) {
  list<unique_ptr<Criatura>> lista_teste;

  int sz = this->_criaturas.size();

  if (id1 < sz && id2 < sz) {

     if (_criaturas[id1]->get_subtipo() == _criaturas[id2]->get_subtipo()) {

      lista_teste = _criaturas[id1]->acasalar(_criaturas[id2]);
      
    }

  }
  
  shared_ptr<Criatura> t;

  for (auto i = lista_teste.begin(); i != lista_teste.end(); ++i) {

    t = move(*i);

    _criaturas.push_back(t);

  }
}

void Aquario::print() {
  cout << "=============" << endl;

  cout << "Aquario Info:" << endl;

  for (auto it : _criaturas) {

    it->print_info();

  }

  cout << "=============" << endl;
}