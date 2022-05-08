#include "Agente.h"

Agente::Agente(int vida = 0, Nodo * nodo = nullptr){
  this->vida = vida;
  this->nodo = nodo;
}

void Agente::moverse(Nodo * nuevaPosicion){
  this->nodoActual = nuevaPosicion;
}

int Agente::getVida(){
  return vida;
}

int setVida(int vida){
  this->vida = vida;
}
