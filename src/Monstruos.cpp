#include "Monstruos.h"  /* Agente / string / typeinfo*/
using namespace std;

int Monstruos::getCurrentID() {
    return this->id;
}

string Monstruos::pertenencia() {
    string tipo = string(typeid(*this).name());
    tipo = tipo.substr(1,tipo.length());
    return tipo;
}

int Monstruos::atacar(Agente * agente) {
    return 0;
}

string  Monstruos::toString() {
    return string("");
}

void  Monstruos::setAtrapado() {
    this->atrapado = true;
}
