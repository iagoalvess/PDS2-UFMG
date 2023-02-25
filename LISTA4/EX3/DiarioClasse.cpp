#include "DiarioClasse.hpp"

bool DiarioClasse::determinarAprovacao(double notaSemestre, double notaEspecial, double frequencia) {

  if (notaSemestre < 0 || notaSemestre > 100) {
    throw ExcecaoNotaSemestreInvalida();
  }

  else if (notaEspecial < 0 || notaEspecial > 100) {
    throw ExcecaoNotaEspecialInvalida();
  }

  else if (frequencia > 1 || frequencia < 0) {
    throw ExcecaoFrequenciaInvalida();
  }

  else if (frequencia < 0.75) {
    return false;
  }

  else if (notaSemestre < 40) {
    return false;
  }

  else if (notaSemestre >= 60) {
    return true;
  }

  else if (notaSemestre >= 40 && notaEspecial >= 60) {
    return true;
  }

  else return false;

}