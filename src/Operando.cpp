#include "Operando.h"

Operando::Operando() {}

// métodos abstractos
istream& Operando::cargar(istream & istream) { return istream; }
ostream& Operando::toString(ostream & ostream) { return ostream; }
Operando Operando::operator+(const Operando& otro) { Operando vacio; return vacio; }
Operando Operando::operator-(const Operando& otro) { Operando vacio; return vacio; }
Operando Operando::operator*(const Operando& otro) { Operando vacio; return vacio; }
Operando Operando::operator/(const Operando& otro) { Operando vacio; return vacio; }

// método plantilla
void Operando::evaluarPosfijo(string operation) {
    
}
