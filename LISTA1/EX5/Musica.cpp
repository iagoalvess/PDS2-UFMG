#include "Musica.hpp"

Musica::Musica() {};

Musica::Musica(int id, string nome, string artista, string album, float duracao){
    this->_id = id;
    this->_nome = nome;
    this->_artista = artista;
    this->_album = album;
    this->_duracao = duracao;
};

void Musica::imprimir_dados(){
    int minutos = _duracao;
    int segundos = ((round(((_duracao - minutos)*100)))/100*60);
    int resto = segundos%3600;
    segundos = resto%60;

    cout << _id << "\t" << _album << "\t" << _artista << "\t" << _nome << "\t" << setw(2) << setfill('0') << minutos << ":" << setfill('0') << setw(2) << segundos << "\t" << _favorita << endl;
}