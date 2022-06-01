#ifndef _OPERANDO
#define _OPERANDO

#include <string>
#include<iostream>
using namespace std;

class Operando {
   friend istream & operator>>(istream & entrada, Operando & operando){
       return operando.cargar(entrada);
   }
   friend ostream & operator<<(ostream & salida, Operando & operando){
       return operando.toString(salida);
   }
   public:
      // Métodos usados por los friend para hacer entrada salida
      virtual istream& cargar(istream &);
      virtual ostream& toString(ostream &);

      virtual Operando operator+(const Operando&);
      virtual Operando operator-(const Operando&);
      virtual Operando operator*(const Operando&);
      virtual Operando operator/(const Operando&);
      void evaluarPosfijo(string operation);

};

#endif
