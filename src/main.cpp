#include "Racional.h"

#include<iostream>
using namespace std;

void probarRacional() {
   cout << "-------------------------------------------" << endl;
   cout << "Prueba de racional:\n" << endl;
   Racional y(5,2), z(2,6);
   cout << "y: " << y << " | z: " << z << endl;
   
   cout << "Operando sobre (y) y (z)" << endl;
   Racional suma = y + z;
   Racional resta = y - z;
   Racional multiplicacion = y * z;
   Racional division = y / z;
   cout << "Suma: " << suma << "\nResta: " << resta << "\nMultiplicacion: " << multiplicacion << "\nDivision: " << division << endl;


   cout << "-------------------------------------------" << endl;
}

void run() {
   probarRacional();
}

int main(){
   cout << "\n    | Start |" << endl;

   run();
   
   cout << "\n   | End |" << endl;
   return 0;
}
