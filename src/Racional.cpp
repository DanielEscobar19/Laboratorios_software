#include "Racional.h"
#include<iostream>
using namespace std;

istream & Racional::cargar(istream & entrada){
   entrada >> num;
   entrada >> den;
   _init(num,den);
   return entrada;
}
ostream & Racional::imprimir(ostream & salida){
   salida << num;
   if(den!=1){
      salida << "/"<< den;
   }
   return salida;
}


Racional& Racional::_init(int num, int den){
   this->num = num;
   if(den){
      this->den = den;
   }
   else {
      this->den = 1;
      cerr << "Warning: Forzado denominador 0 a 1"<< endl;
   }
   _simplificar();
   return *this;
}
      
Racional& Racional::_simplificar(){
   int x = _mcd(num,den);
   num/=x;
   den/=x;
   if(den<0){
      num*= -1.0;
      den*= -1.0;
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

Racional::Racional(){
   _init(0,1);
}

Racional::Racional(int num){ 
   _init(num,1);
} 

Racional::Racional(int num, int den){
   _init(num,den);
}
           
int Racional::operator==(const Racional& otro ){
   return (this->num == otro.num && this->den == otro.den);
}

int Racional::operator!=(const Racional& otro){
   return !( *this == otro );
}

int Racional::operator!=(int x){
   Racional otro(x);
   return otro != *this;
}

Racional Racional::operator+(const Racional& otro){
   Racional nuevo (this->num * otro.den + this->den * otro.num, this->den * otro.den);
   return nuevo;
}

Racional Racional::operator-(const Racional& otro){	
   Racional nuevo( num * otro.den - den * otro.num   , den * otro.den);
   return nuevo;
}

Racional Racional::operator*(const Racional & otro){
   Racional nuevo( num * otro.num ,  den * otro.den);
   return nuevo;
}
      
Racional Racional::operator/(const Racional & otro){
   Racional nuevo (this->num*otro.den, this->den*otro.num); 
   return nuevo;
}

Racional & Racional::operator=(int entero){
   _init(entero,1);
   return *this;
}
// PreIncremento ++X
Racional & Racional::operator++(){
    this-> num = this->den + this->num;
    return *this;
 }

// x++; // posincremento, note el int que no se usa como parámetro
Racional Racional::operator++(int noSeUsa){
  Racional viejo(this->num, this->den);
  ++(*this);
  return viejo;
}

Racional & Racional::operator+=(const Racional& otroRacional){
   *this = *this + otroRacional;
   return *this;
}
      
Racional & Racional::operator*=(const Racional& otroRacional){
   *this = *this * otroRacional;
   return *this;
}
