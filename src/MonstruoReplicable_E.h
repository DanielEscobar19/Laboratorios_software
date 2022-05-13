// Rol decorador por plantilla (estático) de replicabilidad

#ifndef MONSTRUO_REPLICABLE_E_H
#define MONSTRUO_REPLICABLE_E_H

#include "Monstruos.h"  // rol abstracto
#include <iostream>
#include <string>
using namespace std;

template < typename T >
class MonstruoReplicable_E : public T
{
    // Impide que se use MonstruoReplicable_E con un tipo T que NO herede de Monstruos!!!
    static_assert(is_base_of<Monstruos, T>::value, "Template argument must be a Monstruos");

private:
  bool esReplicable = false;
  int copias = 0;

public:
  template < typename ...Args >
  MonstruoReplicable_E(bool esReplicable, int qtyCopias, Args ... args) : T(std::forward<Args>(args)...) , esReplicable{esReplicable}, copias {qtyCopias} 
  { };

  ~MonstruoReplicable_E() {};
  
  string toString() {
    string resultado = T::toString();
    if (this->esReplicable) {
      resultado += " Es replicable y tiene " + to_string(this->copias) + " copias."; 
    } else {
      resultado += " No es replicable.";
    }
    return resultado;
  }

  void desactivarReplicabilidad() {
    this->esReplicable = false;
    this->copias = 0;
    cout << "Replicabilidad desactivada" << endl;
  }

  void activarReplicabilidad(int qtyCopias) {
    this->esReplicable = true;
    this->copias = qtyCopias;
    cout << "Replicabilidad activada" << endl;
  }
};

#endif  // MONSTRUO_REPLICABLE_E_H
