#include "Playlist.hpp"

void Playlist::adicionar_musica(string nome, string artista, string album, float duracao){
    Musica *aux = new Musica;
    aux->_id = 0;
    aux->_nome = nome;
    aux->_artista = artista;
    aux->_album = album;
    aux->_duracao = duracao;

    if (head == nullptr) {
        head = aux;
        tail = aux;
        aux->_id = 1;
    } else {
        aux->_id = tail->_id + 1;
        tail->next = aux;
        tail = aux;
    }
};

Musica* Playlist::buscar_musica(string nome, string artista){
    Musica *aux = head;

    while (aux != nullptr) {
        if(aux->_nome == nome && aux->_artista == artista) return(aux);
        aux = aux->next;
    }
    return(nullptr);
};

void Playlist::remover_musica(int id){
    Musica *atual = head;
    Musica *proxima = nullptr;

    while (atual != nullptr){
        if (atual->_id == id){
            if (proxima == nullptr) {
                head = atual->next;
            } else if (atual->next == nullptr) {
                proxima->next = nullptr;
                tail = proxima;
            } else {
                proxima->next = atual->next;
            }
            delete atual;
            return;
        }

        proxima = atual;
        atual = atual->next;
    }
};

void Playlist::favoritar_musica(int id){
    Musica *atual = head;
    Musica *proxima = nullptr;

    while (atual != nullptr){
        if (atual->_id == id && atual->_favorita == false){
            if (proxima == nullptr) {
                head = atual->next;
            } else if (atual->next == nullptr) {
                proxima->next = nullptr;
                tail = proxima;
            } else {
                proxima->next = atual->next;
            }
            atual->next = head;
            head = atual;
            atual->_favorita = true;
            return;
        }
        proxima = atual;
        atual = atual->next;
    }
};

void Playlist::desfavoritar_musica(int id){
    Musica *atual = this->head;
    Musica *anterior;

    while (atual != nullptr){
        if (atual != nullptr){
            if (atual->_id == id && atual->_favorita == true){
                if (atual != head){
                    anterior->next = atual->next;
                    tail->next = atual;
                    atual->next = nullptr;
                    atual->_favorita = false;
                } else {
                    this->head = atual->next;
                    tail->next = atual;
                    atual->next = nullptr;
                    tail = atual;
                    atual->_favorita = false;
                }
                }
        }
        anterior = atual;
        atual = atual->next;
    }
};

void Playlist::imprimir(){
    Musica *aux = head;
    float tempototal = 0;

    while (aux != nullptr){
        aux->imprimir_dados();
        tempototal += aux->_duracao;
        aux = aux->next;
    }

    int horas = tempototal/60;
    int minutos;
    if (tempototal >= 60) minutos = tempototal - 60;
    else minutos = tempototal;
    int segundos = ((round(((tempototal - minutos)*100)))/100*60);
    int resto = segundos%3600;
    segundos = resto%60;

    cout << "Tempo total: " << setw(2) << setfill('0') << horas << ":" << setw(2) << setfill('0') << minutos << ":" << setw(2) << setfill('0') << segundos << endl;
};