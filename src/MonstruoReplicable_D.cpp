#include "MonstruoReplicable_D.h"
#include <sstream>

MonstruoReplicable_D::MonstruoReplicable_D(Monstruos& monstruos, bool esReplicable, int qtyCopias) : monstruos {monstruos} , esReplicable {esReplicable} , copias {qtyCopias}
{ }

MonstruoReplicable_D::~MonstruoReplicable_D()
{ 
  cout << "Destruye MonstruoReplicable_D de " << monstruos.toString() << endl;
  // solo se crea en memoria dinámica entonces no se ocupa destruir
}

string MonstruoReplicable_D::toString()
{ 
  string result = this->monstruos.toString();
  if (this->esReplicable) {
    result += " es replicable y tiene " + to_string(this->copias) + " copias"; 
  } else {
    result += " no es replicable";
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
