#include "Racional.h"
#include "Doble.h"
#include "Conjunto.h"
#include <set>

#include<iostream>
using namespace std;



void probarOperando(Operando& x, Operando& y) {
   cout << "-------------------------------------------" << endl;
   cout << "Prueba de operando:\n" << endl;
   cout << "x: " << x.toString() << " | y: " << y.toString() << endl;
   cout << "Operando sobre (x) y (y)" << endl;
   Operando& suma = x + y;
   Operando&  resta = x - y;
   Operando&  multiplicacion = x * y;
   Operando&  division = x / y;
   cout << "Suma: " << suma.toString() << "\nResta: " << resta.toString()  << "\nMultiplicacion: " << multiplicacion.toString()  << "\nDivision: " << division.toString()  << endl;
   cout << "-------------------------------------------" << endl;
}

void run() {
   // probamos Racionales
   Racional r2(5,3);
   Racional r4(6,12);
   probarOperando(r2, r4);

   // Probamos Dobles
   Doble d2(2.5);
   Doble d4(40.3);
   probarOperando(d2, d4);

   // probamos conjuntos
   set<int> conj1;
   conj1.insert(5); conj1.insert(7);

   Conjunto c2(conj1);
  
   set<int> conj2;
   conj2.insert(2); conj2.insert(4); conj2.insert(7);

   Conjunto c3(conj2);
   probarOperando(c2, c3);

   Doble general;
   general.setVar("d2", d2);
   general.setVar("d4", d4);
   string operacion = "d2 d4 +";
   general.evaluarPosfijo(operacion);
   // cout << general.getVar("d2").toString() << endl;
   // cout << general.getVar("d4").toString() << endl;
}

int main(){
   cout << "\n    | Start |" << endl;

   run();
   
   cout << "\n   | End |" << endl;
   return 0;
}
