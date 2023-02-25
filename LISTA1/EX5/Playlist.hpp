#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Musica.hpp"

#include <iostream>

using namespace std;

struct Playlist {
    Musica* head = nullptr;
    Musica* tail = nullptr;

    void adicionar_musica(string nome, string artista, string album, float duracao);

    Musica* buscar_musica(string nome, string artista);

    void remover_musica(int id);

    void favoritar_musica(int id);

    void desfavoritar_musica(int id);

    void imprimir();
};

#endif