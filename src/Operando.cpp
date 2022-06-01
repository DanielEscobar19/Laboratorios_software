#include "Operando.h"

// métodos abstractos
istream& Operando::cargar(istream &) {}
ostream&  Operando::toString(ostream &) {}
Operando Operando::operator+(const Operando&) {}
Operando Operando::operator-(const Operando&) {}
Operando Operando::operator*(const Operando&) {}
Operando Operando::operator/(const Operando&) {}

// método plantilla
void Operando::evaluarPosfijo(string operation) {
    
}
