#ifndef CAZADOR_H
#define CAZADOR_H

#include "Agente.h"
#include "Monstruo.h"

class Cazador : public Agente
{
public:
  Cazador();
  void atraparMonstruo(Monstruo * monstruo);
  bool estaMuerto();

private:
  int monstruosCazados;

};

#endif // CAZADOR_H
