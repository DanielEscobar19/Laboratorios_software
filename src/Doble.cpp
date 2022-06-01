#include "Doble.h"
Doble::Doble() {
  this->valor = 0;
}

Doble::Doble(double d) : valor(d) { }

Doble::~Doble() { }

string Doble::toString() {
  return to_string(this->valor);
}

Doble Doble::operator+(const Doble & otro ) {
  Doble result(this->valor + otro.valor);
  return result;
}

Doble Doble::operator-(const Doble & otro ) {
  Doble result(this->valor - otro.valor);
  return result;
}

Doble Doble::operator*(const Doble & otro) {
  Doble result(this->valor * otro.valor);
  return result;
}

Doble Doble::operator/(const Doble & otro) {
  Doble result(this->valor / otro.valor);
  return result;
}
