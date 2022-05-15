#ifndef MONSTRUO_CON_MEMORIA_E
#define MONSTRUO_CON_MEMORIA_E

#include "Monstruos.h"
#include <vector>
#include <string>

using namespace std;

template < typename T >
class MonstruoConMemoria_E : public T{
  static_assert(is_base_of<Monstruos, T>::value, "Template tiene que ser de la clase Monstruos");

private:
  bool tieneMemoria = false;
  vector<int> ataquesRealizados;

public:
  template < typename ...Args >
  MonstruoConMemoria_E(bool tieneMemoria, Args ... args) : T(forward<Args>(args)...) , tieneMemoria{tieneMemoria}{ 
  };
 
  ~MonstruoConMemoria_E(){};

  void activarMemoria(){
    this->tieneMemoria = true;
  };

  void desactivarMemoria(){
    this->tieneMemoria = false;
  }

  void guardarEnMemoria(int ataque){
    if(tieneMemoria){
      this->ataquesRealizados.push_back(ataque);
    }
  };

  int buscarEnMemoria(int ataqueNumero){
    if(ataqueNumero > -1 && ataqueNumero < this->ataquesRealizados.size()){
      return this->ataquesRealizados[ataqueNumero];
    }
    return -1;
  };

  string toString(){
    string resultado = T::toString();
	this->tieneMemoria == true ? resultado += " T" : resultado += " No t";
    resultado += "iene la memoria activada y a guardado en ella " + to_string(this->ataquesRealizados.size()) + " registros. ";
    return resultado;
  };
};

#endif  // MONSTRUO_CON_MEMORIA_E