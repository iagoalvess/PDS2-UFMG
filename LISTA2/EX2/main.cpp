#include "avaliacao_basica_cinereview.hpp"

int main() {
  std::string login, nome_usuario;
  std::string nome_filme, genero, comentario;
  int duracao, id;
  float nota;

  RegistroAvaliacoes registro;

  char opcao;

  while (cin >> opcao) {
    switch (opcao) {
    case 'u':
      cin >> login;
      cin >> nome_usuario;

      registro.adicionar_usuario(login, nome_usuario);

      break;

    case 'f':
      cin >> nome_filme;
      cin >> genero;
      cin >> duracao;

      registro.adicionar_filme(nome_filme, genero, duracao);

      break;

    case 'r':
      cin >> id;
      cin >> login;
      cin >> comentario;
      cin >> nota;

      registro.adicionar_review(id, login, comentario, nota);

      break;
    
    case 'p':
      registro.imprimir_registro_geral();


      break;

    case 's':
      registro.imprimir_estatisticas_usuarios();

      break;

    case 'l':
      cin >> login;

      registro.imprimir_reviews_usuario(login);

      break;

    case 'b':
      avaliacao_basica();

      break;
    }
  }
  return 0;
}