#include "Racional.h"
#include "Doble.h"

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
   Racional r2(5,2);
   Racional r4(6,12);
   probarOperando(r2, r4);
   Doble d2(2.5);
   Doble d4(40.3);
   probarOperando(d2, d4);
}

int main(){
   cout << "\n    | Start |" << endl;

   run();
   
   cout << "\n   | End |" << endl;
   return 0;
}
