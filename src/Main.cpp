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

// ============================================================================

bool juegoTerminado(int monstruosCreados, Cazador* cazador) {
  if (cazador->estaMuerto() || cazador->getMonstruosCazados() == monstruosCreados) {
    return true;
  }
  return false;
}

void administrarTurnos() { }


void declararGanador(Cazador* cazador) {
  if (cazador->estaMuerto())
    cout << "\nEl cazador está muerto.\nGanador: Los monstruos." << endl;
  else 
    cout << "\nTodos los monstruos han sido capturados.\nGanador: cazador." << endl;
}

// ============================================================================

void run() {

  int ids = 0;
  int monstruosCreados = 4;
    
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
  
  cout << endl << "Creación de 2 Cadejos, manada de Cadejos y agrega un cadejo a la manada:" << endl;
  Cadejo cadejo1(++ids);
  cout << cadejo1.toString() << endl;
  Cadejo cadejo2(++ids);
  cout << cadejo2.toString() << endl;

  MM manadaCadejos(++ids);
  manadaCadejos.agregarMiembro(&cadejo1);
  
  cout << endl << "Creación de Nueva manada de Cadejos y agrega otro cadejo a la manada:" << endl;
  MM manadaCadejos2(++ids);
  manadaCadejos2.agregarMiembro(&cadejo2);

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
  cout << "\nCazador atacado por Wumpus:" << endl;
  cout << "Wumpus hace " << wumpus1.atacar(&cazador1) << " de daño" << endl;
  cout << cazador1.toString() << endl;

  // lo ataca una manada
  cout << "\nCazador atacado por manada de Wumpus:"<< endl;
  cout << "Manada Wumpus hace " << manadaWumpus.atacar(&cazador1) << " de daño" << endl;
  cout << cazador1.toString() << endl;

  cout << "\nQuitamos a un Wumpus de la manada:"<< endl;
  cout << manadaWumpus.toString() << endl;
  wumpus2.unsetManada();
  cout << wumpus2.toString() << endl;
  cout << manadaWumpus.toString() << endl;

  cout << endl << "Probamos el ataque del cazador contra un monstruo:"<< endl;
  cazador1.atraparMonstruo(&wumpus2);
  cout << wumpus2.toString() << endl;

  cout << endl << "Probamos el ataque del cazador contra una manada:"<< endl;
  cout << manadaCadejos.toString() << endl;
  cazador1.atraparMonstruo(&cadejo1);
  cazador1.atraparMonstruo(&cadejo2);
  cout << manadaCadejos.toString() << endl;
  cout << cadejo1.toString() << endl;
  cout << cadejo2.toString() << endl;

  cout << manadaCadejos.toString() << endl;


  cazador1.atraparMonstruo(&wumpus1);  // caza el último monstruo.

  if (juegoTerminado(monstruosCreados, &cazador1)) {
    declararGanador(&cazador1);
  }

}

int main() {
  cout << "\n    | Start |" << endl;

  run();
  
  cout << "\n   | End |" << endl;
}