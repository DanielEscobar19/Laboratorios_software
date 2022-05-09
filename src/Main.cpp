#include "Wumpus.h"
#include "Cadejo.h"
#include "MM.h"
#include "Cazador.h"

#include <iostream>
using namespace std;

int main() {
  cout << "\nstart" << endl;

  int ids = 0;

  // ================= Creación de Wumpus y manada de Wumpus
  Wumpus wumpus1(++ids);
  Wumpus wumpus2(++ids);
  cout << wumpus1.toString() << endl;
  cout << wumpus2.toString() << endl;

  MM manadaWumpus(++ids);
  wumpus1.setManada(&manadaWumpus);
  wumpus2.setManada(&manadaWumpus);

  cout << manadaWumpus.toString() << endl;
  
  // ================= Creación de Cadejos y manada de Cadejos
  Cadejo cadejo1(++ids);
  Cadejo cadejo2(++ids);
  cout << cadejo1.toString() << endl;
  cout << cadejo2.toString() << endl;
  
  MM manadaCadejos(++ids);
  cadejo1.setManada(&manadaCadejos);
  cout << manadaCadejos.toString() << endl;

  // =============== Probamos agregar un miembro de distinto tipo a la manada
  manadaCadejos.agregarMiembro(&wumpus1);
  cout << manadaCadejos.toString() << endl;  // continúa igual: no lo agrega.

  // =============== Probamos el ataque del cazador
  Cazador cazador1;
  cout << cazador1.estaMuerto() << endl;
  cazador1.atraparMonstruo(&cadejo1);
  
  cout << "\nend" << endl;
}