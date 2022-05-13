#include "MonstruoInvisible.h"
MonstruoInvisible::MonstruoInvisible(Monstruos & monstruos, bool invisibilidad) : monstruos{monstruos},invisibilidad {invisibilidad} {}

MonstruoInvisible::~MonstruoInvisible() {}

string MonstruoInvisible::toString() {
    string resultado = this->monstruos.toString();
    this->invisibilidad == true? resultado += " Es invisible." : resultado += " No es invisible.";
    return resultado;
}

void MonstruoInvisible::activarInvisibilidad() {
    this->invisibilidad = true;
}

void MonstruoInvisible::desActivarInvisibilidad() {
    this->invisibilidad = false;
}

