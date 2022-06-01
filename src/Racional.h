#ifndef _RACIONAL
#define _RACIONAL

#include<iostream>
using namespace std;

class Racional {

   // LOS METODOS friend AMIGOS NO PERTENECEN A LA CLASE
   friend istream & operator>>(istream & entrada, Racional & racional){
       return racional.cargar(entrada);
   }
   friend ostream & operator<<(ostream & salida, Racional & racional){
       return racional.toString(salida);
   }

   private:
      int num;
      int den;

      Racional& _init(int,int); 
      int _mcd(int,int);
      Racional& _simplificar();

   public:
      Racional(int,int);

      // Métodos usados por los friend para hacer entrada salida
      istream& cargar(istream &);
      ostream& toString(ostream &);

      Racional operator+(const Racional&);
      Racional operator-(const Racional&);
      Racional operator*(const Racional&);
      Racional operator/(const Racional&);

};

#endif
