#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

struct Musica {
    int _id; 

    std::string _nome; 
    std::string _artista; 
    std::string _album; 

    float _duracao; 
    bool _favorita;

    Musica *next = nullptr;

    Musica();
    Musica(int id, string nome, string artista, string album, float duracao);

    void imprimir_dados();
};

#endif