#ifndef AGENTE_H
#define AGENTE_H


class Agente
{
public:
  void moverse(Nodo * nuevaPosicion);

protected:
  int vida;
  Nodo * nodoActual;

};

#endif // AGENTE_H
