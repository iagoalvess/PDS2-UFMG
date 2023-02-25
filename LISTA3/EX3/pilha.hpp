#ifndef PILHA_H
#define PILHA_H

#include "iostream"

template<class T>
class Pilha {
private:
  T* _arr;

  int _max_tam;
  int _top;

public:
  Pilha(int max_tam);
  ~Pilha();

  bool push(const T& novo_e);
  bool pop(T& valor);
  bool get_maior(T& valor);
  bool vazia();

  void print();
};

template<class T>
Pilha<T>::Pilha(int max_tam) : _max_tam(max_tam) {
  _arr = new T[max_tam];

  _top = 0;
}

template<class T>
Pilha<T>::~Pilha() {
  delete(_arr);
}

template<class T>
bool Pilha<T>::push(const T& novo_e) {
  if (_top < _max_tam) {
    _arr[_top] = novo_e;
    _top++;
      
    return(true);
  }

  return(false);
}

template<class T>
bool Pilha<T>::pop(T& valor) {
  if (vazia() == false) {
    valor = _arr[_top-1];

    _top--;
    return(true);
  } else return(false);
}

template<class T>
bool Pilha<T>::get_maior(T& valor) {
  valor = _arr[0];

  for (int i = 0; i < _top; i++) {

    if (_arr[i] > valor) {
      valor = _arr[i]; 
    }

  }
  return(!vazia());
}

template<class T>
bool Pilha<T>::vazia() {
  if (_top == 0) return(true);

  else return(false);
}

template<class T>
void Pilha<T>::print() {
  for (int i = 0; i < _top; i++) {

    std::cout << _arr[i] << std::endl;

  } 
}

#endif