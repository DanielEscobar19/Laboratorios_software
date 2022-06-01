#ifndef _OPERANDO
#define _OPERANDO

#include <string>
#include<iostream>
using namespace std;

class Operando {

   public:
	  // Métodos usados por los friend para hacer entrada salida
	  virtual string toString() = 0;

	  virtual Operando& operator+(Operando&) = 0;
	  virtual Operando& operator-(Operando&) = 0;
	  virtual Operando& operator*(Operando&) = 0;
	  virtual Operando& operator/(Operando&) = 0;
	  string evaluarPosfijo(string operation);

};

#endif
