#include "Usuario.hpp"

Usuario::Usuario() {}

Usuario::Usuario(std::string login, std::string nome) : _login(login), _nome(nome) {}

void Usuario::associar_review(Review *review) {
  this->_reviews.push_back(*review);
}

void Usuario::imprimir_info() {
  std::cout << this->_nome << "\t" << "Reviews: " << this->_reviews.size() << std::endl;
}

void Usuario::imprimir_reviews() {
  int num_reviews = this->_reviews.size();

  if (num_reviews == 0) {
    std::cout << "Usuario " << this->_nome << " nao possui reviews!" << std::endl;
  }
  else {
    std::cout << this->_nome << "\t" << "Reviews: " << num_reviews << std::endl;
    
    for (Review r : this->_reviews) {
      r.imprimir_reviews();
    }
  }
}