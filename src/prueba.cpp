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

void printStack(stack<Operando*> pila) {
  cout << "Pila: ";
  // como es por copia, no le afecta el pop
  while( !pila.empty() )
  {
    Operando& operando = *pila.top();
    pila.pop();
    cout << operando.toString() << "  ";
  }
  cout << "\n"<< endl;
}

void printMap(map<string, Operando&> map) {
  auto iter = map.begin();
    while (iter != map.end()) {
        cout << "[" << iter->first << ","
                    << iter->second.toString() << "]\n";
        ++iter;
    }
    cout << "\n" << endl;
}

Operando& operar(Operando& operando1, Operando& operando2, char oper) {
  switch (oper) {
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
    return operando1 + operando2;
    break;
  }
}
int main() {
  map<string,Operando&> variables;

  // Doble d1(2.2);
  // Doble d2(4.4);

  Racional d1(5,6);
  Racional d2(2,8);

  variables.insert(pair<string,Operando&>("d1",d1));
  variables.insert(pair<string,Operando&>("d2",d2));
  // variables.insert(pair<string,Operando&>("d3",d2));

  istringstream operacion("d1 d2 / d1 + d1 - d1 +");
  // 2.2 / 4.4 - 2.2
  cout << "oper: " << operacion.str() << endl;
  
  stack<Operando*> pila;
  string symbol = "";
  while(!operacion.eof()) {
    operacion >> symbol;
    if (isOperator(symbol)) {
      cout << "Calculando " << symbol << " ";

      Operando& op1 = *pila.top();
      pila.pop();
      Operando& op2 = *pila.top();
      pila.pop();

      Operando& result = operar(op2, op1, symbol[0]);
      pila.push(&result);
    } 
    else {
      pila.push(&variables.at(symbol));
    }
    // cout << "n: " << n << endl;
    printStack(pila);
  }
  
  cout << "pila al final: " << endl;
  printStack(pila);

  cout << "map al final: " << endl;
  printMap(variables);
  return 0;
}