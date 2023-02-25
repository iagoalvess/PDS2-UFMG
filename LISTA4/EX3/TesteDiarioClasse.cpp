#include "doctest.h"
#include "DiarioClasse.hpp"

TEST_CASE("Teste 01 - Exececao NotaEspecial") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(60, -1, 0.9), ExcecaoNotaEspecialInvalida);
}

TEST_CASE("Teste 02 - Exececao NotaEspecial") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(60, 150, 0.9), ExcecaoNotaEspecialInvalida);
}

TEST_CASE("Teste 03 - Excecao NotaSemestre") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(-30, 0, 1), ExcecaoNotaSemestreInvalida);
}

TEST_CASE("Teste 04 - Excecao Frequencia") {
  DiarioClasse diario;
  CHECK_THROWS_AS(diario.determinarAprovacao(100, 0, -0.5), ExcecaoFrequenciaInvalida);
}

TEST_CASE("Teste 05 - Aprovacao simples") {
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(100, 0, 0.78);
  CHECK(aprovado);
}

TEST_CASE("Teste 06 - Aprovacao simples") {
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(60, 0, 0.9);
  CHECK(aprovado);
}

TEST_CASE("Teste 07 - Aprovacao ExameEspecial") {
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(40, 60, 0.78);
  CHECK(aprovado);
}

TEST_CASE("Teste 08 - Reprovacao por frequencia") {
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(70, 0, 0.69);
  CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 09 - Reprovacao ExameEspecial"){
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(50, 50, 0.8);
  CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 10 - Reprovacao sem possibilidade de ExameEspecial"){
  DiarioClasse diario;
  bool aprovado = diario.determinarAprovacao(30, 0, 0.8);
  CHECK_FALSE(aprovado);
}