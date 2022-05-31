#include<iostream>
using namespace std;
#include "Racional.h"

int main(){
   Racional x;
   Racional y;
   Racional suma;
   Racional resta;
   Racional producto;
   Racional division;
   
   cout << "Digite un valor: ";
   cin >> x;
   cout << endl;

   cout << "Digite un valor: ";
   cin >> y;
   cout << endl;

   suma = x + y;
   resta = x - y;
   producto = x * y;
   if(y!=0) {
      division = x / y;  
   }

   cout << "X: ";
   cout << x << endl; 

   cout << "Y: ";
   cout << y << endl;

   // Operador de comparación de igualdad == 
   // es igual retorna 0 si no son iguales y !0 en caso contrario
   if( x == y){ 
      cout << "X y Y son iguales" << endl;
   }
   cout << "Suma:";
   cout << suma << endl;

   cout << "Resta:";
   cout << resta << endl;

   cout << "Producto:";
   cout << producto << endl;
   if(y!=0){
      cout << "Division:";
      cout << division << endl;
   }
   cout << "X = 1" << endl;
   x = 1;
   cout << "Después y = ++x :"<< endl;

   y = ++x; // preincremento

   cout << "X: ";
   cout << x << endl;

   cout << "Y: ";
   cout << y << endl;

   cout << "X = 1" << endl;
   x = 1;
   cout << "Después y = x++ :"<< endl;

   y = x++; // posincremento

   cout << "X: ";
   cout << x << endl;

   cout << "Y: ";
   cout << y << endl;

   cout << "X = 1" << endl;
   x = 1;
   y = 2;
   cout << "Si ejecuto x=1; y y=2; :";
   cout << "Después x+=y :"<< endl;

   x+= y; // masIgual

   cout << "X: ";
   cout << x << endl;

   cout << "Y: ";
   cout << y << endl;

  cout << "X = 2 y Y= 3" << endl;
   x = 2;
   y = 3;
   cout << "Después x*=y :"<< endl;

   x*= y; // masIgual

   cout << "X: ";
   cout << x << endl;

   cout << "Y: ";
   cout << y << endl;

//   cout << "Si imprimo directamente ++(x+=2) x vale: " << ++(x+=2) << " x="<< x << endl;

   cout << "Si imprimo directamente ++(x+=2) = " << ++(x+=2) << endl;
   cout << "X = "<< x << endl;

   return 0;
}
