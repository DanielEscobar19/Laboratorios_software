#include "Cazador.h"
#include <stdlib.h>
#include <time.h>

Cazador::Cazador(){
  this->vida = 100;
}
void Cazador::atraparMonstruo(Monstruo * monstruo){
  srand (time(NULL));
  if ((rand() % 2) == 2) {
    monstruo->setAtrapado();
    ++this->monstruosCazados;
  }
}

bool Cazador::estaMuerto(){
  return this->vida < 1;
}
