#include "MonstruoInvisible_D.h"
MonstruoInvisible_D::MonstruoInvisible_D(Monstruos & monstruos, bool invisibilidad) : monstruos{monstruos}, invisibilidad {invisibilidad} {}

MonstruoInvisible_D::~MonstruoInvisible_D() {}

string MonstruoInvisible_D::toString() {
    string resultado = this->monstruos.toString();
    this->invisibilidad == true? resultado += " Es invisible." : resultado += " No es invisible.";
    return resultado;
}

void MonstruoInvisible_D::activarInvisibilidad() {
    this->invisibilidad = true;
}

void MonstruoInvisible_D::desActivarInvisibilidad() {
    this->invisibilidad = false;
}

