#ifndef PRODUTO_H
#define PRODUTO_H

class Produto {
  private:
    int _id;
    float _valor_unitario;

  public:
    Produto(int id, float valor_unitario);
    virtual ~Produto();

    float get_valor_unitario();
    int get_id();
  
    virtual void imprimir_info() = 0;
};

#endif