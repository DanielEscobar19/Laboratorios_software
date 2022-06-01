#include "Racional.h"
#include<iostream>
using namespace std;

istream & Racional::cargar(istream & entrada){
   entrada >> numerador;
   entrada >> denominador;
   _init(numerador,denominador);
   return entrada;
}
ostream & Racional::toString(ostream & salida){
   salida << numerador;
   if(denominador!=1){
      salida << "/"<< denominador;
   }
   return salida;
}

Racional& Racional::_init(int numerador, int denominador){
   this->numerador = numerador;
   if(denominador){
      this->denominador = denominador;
   }
   else {
      this->denominador = 1;
      cerr << "Warning: Forzado denominadorominador 0 a 1"<< endl;
   }
   _simplificar();
   return *this;
}
      
Racional& Racional::_simplificar(){
   int x = _mcd(numerador,denominador);
   numerador/=x;
   denominador/=x;
   if(denominador<0){
      numerador*= -1.0;
      denominador*= -1.0;
   }
   return *this;
}

int Racional::_mcd(int x, int y){
    int resp;
    if(y==0){
       resp = x;
    }
    else {
       resp = _mcd( y , x%y);
    }
    return resp;
}

Racional::Racional(int numerador, int denominador){
   _init(numerador,denominador);
}

Racional Racional::operator+(const Racional& otro){
   Racional nuevo (this->numerador * otro.denominador + this->denominador * otro.numerador, this->denominador * otro.denominador);
   return nuevo;
}

Racional Racional::operator-(const Racional& otro){	
   Racional nuevo( numerador * otro.denominador - denominador * otro.numerador   , denominador * otro.denominador);
   return nuevo;
}

Racional Racional::operator*(const Racional & otro){
   Racional nuevo( numerador * otro.numerador ,  denominador * otro.denominador);
   return nuevo;
}
      
Racional Racional::operator/(const Racional & otro){
   Racional nuevo (this->numerador*otro.denominador, this->denominador*otro.numerador); 
   return nuevo;
}
