#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <sstream>

#include "Doble.h"
#include "Racional.h"
using namespace std;

bool isOperator(string symbol) {
  return (symbol == "+" || symbol == "-" || symbol == "/" || symbol == "*");
}

Operando& operar(Operando& operando1, Operando& operando2, char oper) {
  switch (oper) {
  case '+':
    return operando1 + operando2;
    break;
  case '-':
    return operando1 - operando2;
    break;
  case '*':
    return operando1 * operando2;
    break;
  case '/':
    return operando1 / operando2;
    break;
  default:
    static Doble op(0.0);
    return op;
    break;
  }
}
int main() {
  map<string,Operando&> variables;

  Doble d1(2.2);
  Doble d2(4.4);
  Doble general();

  variables.insert(pair<string,Operando&>("d1",d1));
  variables.insert(pair<string,Operando&>("d2",d2));

  istringstream operacion("d1 d2 +");
  cout << "oper: " << operacion.str() << endl;
  
  stack<Operando*> pila;
  string symbol = "";
  while(!operacion.eof()) {
    operacion >> symbol;
    if (isOperator(symbol)) {
      Operando& op1 = *pila.top();
      pila.pop();
      Operando& op2 = *pila.top();
      pila.pop();

      Operando& result = operar(op1, op2, symbol[0]);
      pila.push(&result);

      cout << "operacion resuelta: " << op1.toString() << " " << symbol << " " << op2.toString() << " = " << result.toString() << endl;
    } 

    else {
      pila.push(&variables.at(symbol));
      cout << "agregado a la pila: " << variables.at(symbol).toString() << endl;
    }
    // cout << "n: " << n << endl;

  }
  return 0;
}