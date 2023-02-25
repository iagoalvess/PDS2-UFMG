#include "avaliacao_basica_playlist.hpp"

int main() {
    string nome;
    string artista;
    string album;
    float duracao;

    Musica* music = new Musica(0, "N0", "A0","B1", 1.5);

    Playlist playlist;

    char opcao;

    while (cin >> opcao){

        switch (opcao){

            case 'a':
                cin >> nome;
                cin >> artista;
                cin >> album;
                cin >> duracao;

                playlist.adicionar_musica(nome, artista, album, duracao);

                break;

            case 's':
                cin >> nome;
                cin >> artista;

                music = playlist.buscar_musica(nome, artista);
                music->imprimir_dados();

                break;

            case 'r':
                cin >> nome;
                cin >> artista;

                music = playlist.buscar_musica(nome, artista);

                playlist.remover_musica(music->_id);

                break;

            case 'f':
                cin >> nome;
                cin >> artista;

                music = playlist.buscar_musica(nome, artista);

                playlist.favoritar_musica(music->_id);

                break;

            case 'd':
                cin >> nome;
                cin >> artista;

                music = playlist.buscar_musica(nome, artista);

                playlist.desfavoritar_musica(music->_id);

                break;

            case 'p':
                playlist.imprimir();

                break;

            case 'b':
                avaliacao_basica();

                break;
        }
    }
    
    return 0;   
}