#ifndef AGENTE_H
#define AGENTE_H

#include "Nodo.h"

class Agente{
public:
  Agente(int vida = 0, Nodo * nodo = nullptr);
  void moverse(Nodo * nuevaPosicion);
  int getVida();
  int setVida(int vida);

protected:
  int vida;
  Nodo * nodoActual;

};

#endif // AGENTE_H
