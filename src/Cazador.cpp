#include "Cazador.h"
#include <stdlib.h>
#include <time.h>

Cazador::Cazador(){
  this->vida = 100;
}
void Cazador::atraparMonstruo(Monstruo * monstruo){
  monstruo->setAtrapado();
  ++this->monstruosCazados;
  cout << "Cazador atrapando " << monstruo->pertenencia() <<  " {" << monstruo->getCurrentID() << "}" << endl;
}

bool Cazador::estaMuerto(){
  return this->vida < 1;
}
