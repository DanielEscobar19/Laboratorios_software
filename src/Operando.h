#ifndef _OPERANDO
#define _OPERANDO

#include <string>
#include <map>
#include <iostream>
using namespace std;

class Operando {

	private:
		map<string, Operando&> variables;

   public:
	  // Métodos usados por los friend para hacer entrada salida
	  virtual string toString() = 0;

	  virtual Operando& operator+(Operando&) = 0;
	  virtual Operando& operator-(Operando&) = 0;
	  virtual Operando& operator*(Operando&) = 0;
	  virtual Operando& operator/(Operando&) = 0;
	  string evaluarPosfijo(string operation);

		void setVar(string, Operando&);
		Operando& getVar(string key);

};

#endif
