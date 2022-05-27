#include "Monstruo.h"  /* MM / string */

using namespace std;

int Monstruo::atacar(Agente * agente) {  // default
    agente->setVida(agente->getVida() - DANYO_OMISION);
    return DANYO_OMISION;
}

void Monstruo::setManada(MM * manada) {
  // verifica que existe el ptr e invoca a quitarMiembro de la clase MM.
  if(this->manada != NULL){
    this->manada->quitarMiembro(this);
  }
  this->unsetManada();
  this->manada = manada;
  this->manada->agregarMiembro(this);
}

void Monstruo::nullManada() {
    this->manada = nullptr;
}

void Monstruo::setPtrManada(MM * manada) {
    this->manada = manada;
}

void Monstruo::unsetManada() {
    if (this->manada) {
        this->manada->quitarMiembro(this);
    }
    this->manada = nullptr;
}

void Monstruo::setAtrapado() {
    this->atrapado = true;
    this->unsetManada();
    // cout << "setAtrapado: " << this->toString() << endl;
}

int Monstruo::getDanyo() {
    return this->danyo;
}
string Monstruo::pertenencia() {
    string tipo = string(typeid(*this).name());
    tipo = tipo.substr(1,tipo.length());
    return tipo;
}
void Monstruo::enviarMensaje(string mensaje) {
    if (manada) {
        manada->entregarMensaje(mensaje, this->id);
    } else {
        cout << "El monstruo #" << this->id << " no puede enviar mensajes porque no pertenece a ninguna manada" << endl;
    }
}

void Monstruo::recibirMensaje(string mensaje) {
    cout << "El monstruo #" << this->id << " recibio el mensaje: " << mensaje << endl;
}