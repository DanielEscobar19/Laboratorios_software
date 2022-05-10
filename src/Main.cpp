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
  
  cout << endl << "Creación del cazador:" << endl;
  Cazador cazador1; 
  cout << cazador1.toString() << endl;

  cout << endl << "Creación de 2 Wumpus:" << endl;
  Wumpus wumpus1(++ids);
  cout << wumpus1.toString() << endl;
  Wumpus wumpus2(++ids);
  cout << wumpus2.toString() << endl;

  cout << endl << "Creación manada de Wumpus y se agregan los Wumpus a la manada:" << endl;
  MM manadaWumpus(++ids);
  wumpus1.setManada(&manadaWumpus);
  wumpus2.setManada(&manadaWumpus);
  cout << manadaWumpus.toString() << endl;
  
  cout << endl << "Creación de 2 Cadejos y manada de Cadejos:" << endl;
  Cadejo cadejo1(++ids);
  Cadejo cadejo2(++ids);
  cout << cadejo1.toString() << endl;
  cout << cadejo2.toString() << endl;
  MM manadaCadejos(++ids);
  cadejo1.setManada(&manadaCadejos);
  cout << manadaCadejos.toString() << endl;
  MM manadaCadejos2(++ids);
  cadejo2.setManada(&manadaCadejos2);
  cout << manadaCadejos2.toString() << endl;
  cout << cadejo1.toString() << endl;
  cout << cadejo2.toString() << endl;
  
  cout << endl << "Se cambia los Cadejos a una sola manada:" << endl;
  cadejo2.setManada(&manadaCadejos);
  cout << cadejo1.toString() << endl;
  cout << cadejo2.toString() << endl;
  cout << manadaCadejos.toString() << endl;
  cout << manadaCadejos2.toString() << endl;
  
  cout << endl << "Se intenta agregar Wumpus a manada de Cadejos pero no deja:" << endl;
  manadaCadejos.agregarMiembro(&wumpus1);
  cout << manadaCadejos.toString() << endl;  // continúa igual: no lo agrega.


    // Cazador lo ataca un monstruo 
  cout << endl << "Cazador atacado por Wumpus:" << endl;
  cout << "Wumpus hace " << wumpus1.atacar(&cazador1) << " de daño" << endl;
  cout << cazador1.toString() << endl;

    // lo ataca una manada
  cout << endl << "Cazador atacado por manada de Wumpus:"<< endl;
  cout << "Manada Wumpus hace " << manadaWumpus.atacar(&cazador1) << " de daño" << endl;
  cout << cazador1.toString() << endl;

  cout << endl << "Quitamos a un Wumpus de la manada:"<< endl;
  cout << manadaWumpus.toString() << endl;
  wumpus2.unsetManada();
  cout << wumpus2.toString() << endl;
  cout << manadaWumpus.toString() << endl;

  cout << endl << "Probamos el ataque del cazador contra un monstruo:"<< endl;
  cazador1.atraparMonstruo(&wumpus2);
  cout << wumpus2.toString() << endl;

  cout << endl << "Probamos el ataque del cazador contra una manada:"<< endl;
  cout << manadaCadejos.toString() << endl;
  cazador1.atraparMonstruo(&manadaCadejos);
  cout << manadaCadejos.toString() << endl;
  cout << cadejo1.toString() << endl;
  cout << cadejo2.toString() << endl;
}

int main() {
  cout << "\n    | Start |" << endl;

  run();
  
  cout << "\n   | End |" << endl;
}