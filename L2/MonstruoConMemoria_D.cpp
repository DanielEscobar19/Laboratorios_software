#include "MonstruoConMemoria_D.h"

MonstruoConMemoria_D::MonstruoConMemoria_D(Monstruos& monstruos, bool tieneMemoria) : monstruos {monstruos}{
  this->tieneMemoria = tieneMemoria;
 }
 
MonstruoConMemoria_D::~MonstruoConMemoria_D(){
	
}

void MonstruoConMemoria_D::activarMemoria(){
  this->tieneMemoria = true;
}

void MonstruoConMemoria_D::desactivarMemoria(){
  this->tieneMemoria = false;
}

void MonstruoConMemoria_D::guardarEnMemoria(int ataque){
  if(tieneMemoria){
    this->ataquesRealizados.push_back(ataque);
  }
}

int MonstruoConMemoria_D::buscarEnMemoria(int ataqueNumero){
  if(ataqueNumero > -1 && ataqueNumero < this->ataquesRealizados.size()){
    return this->ataquesRealizados[ataqueNumero];
  }
  return -1;
}

string MonstruoConMemoria_D::toString(){
  string resultado = this->monstruos.toString();
  this->tieneMemoria == true ? resultado += " T" : resultado += " No t";
  resultado += "iene la memoria activada y a guardado en ella " + to_string(this->ataquesRealizados.size()) + " registros. ";
  return resultado;
}

int MonstruoConMemoria_D::atacar(Agente * agente) {
  int danyo = monstruos.atacar(agente);
  guardarEnMemoria(danyo);
  return danyo;
}