// Rol decorador por herencia (dinámico) de replicabilidad

#ifndef MONSTRUO_REPLICABLE_D_H
#define MONSTRUO_REPLICABLE_D_H

#include "Monstruos.h"
#include <iostream>
#include <string>
using namespace std;

class MonstruoReplicable_D : public Monstruos
{
private:
  Monstruos& monstruos;
  bool esReplicable = false;
  int copias = 0;

public:
  MonstruoReplicable_D(Monstruos& monstruos, bool esReplicable, int qtyCopias);
  ~MonstruoReplicable_D();
  void desactivarReplicabilidad();
  void activarReplicabilidad(int qtyCopias);

  string toString();
};

#endif  // MONSTRUO_REPLICABLE_D_H
