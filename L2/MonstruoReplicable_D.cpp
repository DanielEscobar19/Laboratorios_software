#include "MonstruoReplicable_D.h"
#include <sstream>

MonstruoReplicable_D::MonstruoReplicable_D(Monstruos& monstruos, bool esReplicable, int qtyCopias) : monstruos {monstruos} , esReplicable {esReplicable} , copias {qtyCopias}{}

MonstruoReplicable_D::~MonstruoReplicable_D(){}

string MonstruoReplicable_D::toString()
{ 
  string result = this->monstruos.toString();
  if (this->esReplicable) {
    result += " Es replicable y tiene " + to_string(this->copias) + " copias."; 
  } else {
    result += " No es replicable.";
  }
  return result;
}

void MonstruoReplicable_D::activarReplicabilidad(int qtyCopias)
{ 
  this->esReplicable = true;
  this->copias = qtyCopias;
}

void MonstruoReplicable_D::desactivarReplicabilidad()
{ 
  this->esReplicable = false;
  this->copias = 0;
}
