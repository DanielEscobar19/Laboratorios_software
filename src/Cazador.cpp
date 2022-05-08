#include "Cazador.h"
#include <stdlib.h>
#include <time.h>

Cazador::Cazador(){
  vida = 100;
}
void Cazador::atraparMonstruo(Monstruo * monstruo){
  srand (time(NULL));
  monstruo->setAtrapado((rand() % 2) == 2);
}

bool Cazador::estaMuerto(){
  return vida < 1;
}
