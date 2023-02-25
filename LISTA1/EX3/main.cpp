#include <iostream>

using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    
    int a;
    cin >> a;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    
    int* b = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com os dados passados
    
    int tam;
    cin >> tam;
    int c[tam];
    for (int i = 0; i < tam; i++){
        cin >> c[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    
    cout << &a << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    
    cout << a << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    
    cout << &b << endl;

    // 7) Imprima o VALOR da variável declarada em (2)
    
    cout << b << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    
    cout << &c << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    
    cout << &c[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    
    cout << c[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    
    b = &a;

    // 12) Imprima o VALOR da variável declarada em (2)
    
    cout << b << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
    cout << *b << endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    
    if (&a == b) cout << true << endl;
    else cout << false << endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    
    *b = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    
    cout << a << endl;

    // 17) Atribua o VALOR da variável (3) à variável declarada em (2)
    
    b = new int[tam];
    for (int i = 0; i < tam; i++){
        b[i] = c[i];
    }

    // 18) Imprima o VALOR da variável declarada em (2)
    
    cout << b << endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
    cout << *b << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    
    b = &c[0];

    // 21) Imprima o VALOR da variável declarada em (2)
    
    cout << b << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
    cout << *b << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    
    for (int i = 0; i < tam; i++){                 
        b[i] *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    
    for (int i = 0; i < tam; i++){
        if (i == (tam-1)) cout << c[i] << endl;  
        else cout << c[i] << " ";       
    } 

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    
    for (int i = 0; i < tam; ++i){
        if (i == (tam-1)) cout << *(c + i) << endl;
        else cout << *(c + i) << " "; 
    }

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    
    for (int i = 0; i < tam; ++i){
        if (i == (tam-1)) cout << *(b + i) << endl;
        else cout << *(b + i) << " "; 
    }

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    
    b = &c[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    
    cout << b << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    
    cout << *b << endl;

    // 30) Imprima o VALOR que é obtido quando acessamos o ENDEREÇO do ponteiro (2) decrementado de 4
    
    cout << b[-4] << endl;

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    
    int** e = &b;

    // 32) Imprima o VALOR da variável declarada em (31)
    
    cout << e << endl;

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    
    cout << &e << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    
    cout << *e << endl;

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    
    cout << **e << endl;

    return 0;
}