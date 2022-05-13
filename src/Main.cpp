/* Prueba de concepto
Compilar con: g++ *.cpp -o program
Ejecutar con: ./program
Autores: Fabián Orozco Chaves - Daniel Escobar Giraldo - Manuel Arroyo.
 */
#include "Wumpus.h"
#include "Cadejo.h"
#include "MM.h"
#include "Cazador.h"
#include "MonstruoInvisible_S.h"
#include "MonstruoInvisible_D.h"

// #include "MonstruoReplicable_E.h"
#include "MonstruoReplicable_D.h"

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
  Wumpus wumpus(1);
  cout << wumpus.toString() << endl;
  MonstruoInvisible_D wumpusInvi {true};
  // cout << wumpusInvi.toString() << endl;

}

void runLab2_E() {
  // cout << "\nEjecutando solucion estatica" << endl;
  int ids = 0;

  cout << endl << "Creación de 3 Wumpus:" << endl;
  Wumpus wumpus1(++ids);
  cout << wumpus1.toString() << endl;
  Wumpus wumpus2(++ids);
  cout << wumpus2.toString() << endl; 
  Wumpus wumpus3(++ids);
  cout << wumpus3.toString() << endl;
  
  cout << endl << "Creación manada de Wumpus y se agregan los Wumpus a la manada:" << endl;
  MM manadaWumpus(++ids);
  wumpus1.setManada(&manadaWumpus);
  wumpus2.setManada(&manadaWumpus);
  wumpus3.setManada(&manadaWumpus);
  cout << manadaWumpus.toString() << endl;
  
  cout << endl << "Wumpus 1 invisible" << endl;

  cout << endl << "Wumpus 2 replicable" << endl;
  // MonstruoReplicable_D wumpusReplicable1 {wumpus2, true, 5};
  // cout << wumpusReplicable1.toString() << endl;
  cout << endl << "Wumpus 3 con memoria" << endl;

}

void runLab2_D() {
  // cout << "Ejecutando solucion Dinamica" << endl;
  Wumpus wumpus1;
}

int main() {
  cout << "\n    | Start |" << endl;

  // run();
  runLab2_E();
  // runLab2_D();

  cout << "\n   | End |" << endl;
}
