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
       return racional.imprimir(salida);
   }

   private:

      int num;
      int den;

      // Método privado para inicializar valores de num y den
      // Asi no replicamos el mismo código en todos los constructores

      Racional& _init(int,int); 

      int _mcd(int,int);

      Racional& _simplificar();

   public:
      Racional();
      Racional(int);
      Racional(int,int);

      // Métodos usados por los friend para hacer entrada salida
      istream& cargar(istream &);
      ostream& imprimir(ostream &);

      int operator==(const Racional& );

      int operator!=(const Racional&);

      int operator!=(int);


      Racional operator+(const Racional&);

      Racional operator-(const Racional&);

      Racional operator*(const Racional&);

      Racional operator/(const Racional&);

      Racional & operator=(int);

      Racional & operator++();

      // En el posIncremento i++ se debe pasar un parámetro int para saber que los ++ van después
      // de la variable.  Note que ese parámetro no se usa excepto para diferenciarlo del preIncremento
      Racional operator++(int);

      Racional & operator+=(const Racional&);
   
      Racional & operator*=(const Racional&);
};

#endif
