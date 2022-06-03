#include "Operando.h"
#include <map>
#include <stack>
#include <sstream>

// método plantilla
string Operando::evaluarPosfijo(string operation) {
  istringstream operacion(operation);
  cout << "oper: " << operacion.str() << endl;
  
  string symbol = "";
  while(!operacion.eof()) {
    operacion >> symbol;
    // cout << "n: " << n << endl;

  }
  return "";
}

void Operando::setVar(string key, Operando& operando) {
  this->variables.insert(pair<string, Operando&>(key,operando));
}


Operando& Operando::getVar(string key) {
  return this->variables.at(key);
}