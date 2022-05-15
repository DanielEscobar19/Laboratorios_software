#ifndef MONSTRUO_CON_MEMORIA_D
#define MONSTRUO_CON_MEMORIA_D

#include "Monstruos.h"
#include <vector>
#include <string>

using namespace std;

class MonstruoConMemoria_D : public Monstruos{
private:
  Monstruos& monstruos;
  bool tieneMemoria = false;
  vector<int> ataquesRealizados;

public:
  MonstruoConMemoria_D(Monstruos& monstruos, bool tieneMemoria);
  ~MonstruoConMemoria_D();
  void activarMemoria();
  void desactivarMemoria();
  void guardarEnMemoria(int);
  int buscarEnMemoria(int);
  int atacar(Agente * agente);
  
  string toString();
};

#endif  // MONSTRUO_CON_MEMORIA_D