/* Prueba de concepto
Compilar con: g++ *.cpp -o program
Ejecutar con: ./program
Autores: Fabián Orozco Chaves - Daniel Escobar Giraldo - Manuel Arroyo.
 */
#include "Wumpus.h"
#include "Cadejo.h"
#include "MM.h"
#include "Cazador.h"

#include <iostream>
using namespace std;

void run() {
  int ids = 0;
  // ================= Creación del cazador
  Cazador cazador1; 


  // ================= Creación de 2 Wumpus y manada de Wumpus (2)
  Wumpus wumpus1(++ids);
  cout << wumpus1.toString() << endl;
  Wumpus wumpus2(++ids);
  cout << wumpus2.toString() << endl;

  MM manadaWumpus(++ids);
  wumpus1.setManada(&manadaWumpus);
  wumpus2.setManada(&manadaWumpus);

  cout << manadaWumpus.toString() << endl;
  

  // ================= Creación de 2 Cadejos y manada de Cadejos (1)
  Cadejo cadejo1(++ids);
  Cadejo cadejo2(++ids);
  cout << cadejo1.toString() << endl;
  cout << cadejo2.toString() << endl;
  
  MM manadaCadejos(++ids);
  cadejo1.setManada(&manadaCadejos);
  cout << manadaCadejos.toString() << endl;


  // =============== Probamos agregar un miembro de distinto tipo a la manada
  manadaCadejos.agregarMiembro(&wumpus1);
  cout << "Se intenta agregar wumpus a manada de cadejos pero no deja" << endl;
  cout << manadaCadejos.toString() << endl;  // continúa igual: no lo agrega.


  // =============== Creamos cazador, probamos el atacar de monstruo y de una manada

  cout << "Vida del cazador: " << cazador1.getVida() << "\n" << endl;

    // lo ataca un monstruo 
  cout << "Cazador atacado por wumpus" << endl;
  wumpus1.atacar(&cazador1);
  cout << "Vida del cazador: " << cazador1.getVida() << "\n" << endl;

    // lo ataca una manada
  cout << "Cazador atacado por manada de wumpus"<< endl;
  manadaWumpus.atacar(&cazador1);
  cout << "Vida del cazador: " << cazador1.getVida() << "\n" << endl;


  // =============== Probamos el unsetManada de monstruo
  cout << manadaWumpus.toString() << endl;
  wumpus2.unsetManada();
  cout << "Wumpus desvinculado de manada"<< endl;
  cout << wumpus2.toString() << endl;
  cout << manadaWumpus.toString() << endl;

  // =============== Probamos el ataque del cazador
  cazador1.atraparMonstruo(&cadejo1);
  cout << "Cazador atrapa a cadejo"<< endl;
  cout << cadejo1.toString() << endl;
}

int main() {
  cout << "\n    | Start |" << endl;

  run();
  
  cout << "\n   | End |" << endl;
}