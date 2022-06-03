#include "Conjunto.h"

Conjunto::Conjunto() { }

Conjunto::Conjunto(set<int> d) : valor(d) { }

Conjunto::~Conjunto() { }

string Conjunto::toString() {
  string temp = "[";
  for (it=valor.begin(); it!=valor.end(); ++it){
	temp += *it + ", ";
  }
  temp += "]";
  return temp;
}

Conjunto& Conjunto::operator+(Operando& otro ) {
  Conjunto resultado;
  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  set_union(this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), resultado->valor.begin());
  return &resultado;
}

Conjunto& Conjunto::operator-(Operando& otro ) {
  Conjunto resultado;
  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  set_difference(this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), resultado->valor.begin());
  return &resultado;
}

Conjunto& Conjunto::operator*(Operando& otro) {
  Conjunto resultado;
  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  set_intersection(this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), resultado->valor.begin());
  return &resultado;
}

Conjunto& Conjunto::operator/(Operando& otro) {
  Conjunto resultado;
  Conjunto * conjunto = dynamic_cast<Conjunto*>(&otro);
  set_symmetric_difference (this->valor.begin(), this->valor.end(), conjunto->valor.begin(), conjunto->valor.end(), resultado->valor.begin());
  return &resultado;
}

