#include "Monstruo.h"  /* Agente / MM / string */

using namespace std;

// Public methods =================================
Monstruo::Monstruo(int id = 0, MM * manada = nullptr) { }

int Monstruo::atacar(Agente * agente) {  // default
    agente->setVida(agente->getVida() - DANYO_OMISION);
}

void Monstruo::setManada(MM * manada) {
    // verifica que existe el ptr e invoca a quitarMiembro de la clase MM.
    this->unsetManada();
    this->manada = manada;
    this->manada->agregarMiembro(this);
}

void Monstruo::unsetManada() {
    if (this->manada) 
        this->manada->quitarMiembro(this);
    this->manada = nullptr;
}

void Monstruo::setAtrapado() {
    this->atrapado = true;
}

int Monstruo::getCurrentID() {
    return this->id;
}

// Protected methods =================================
string Monstruo::pertenencia() {
    string tipo = string(typeid(*this).name());
    tipo = tipo.substr(1,tipo.length());
    return tipo;
}