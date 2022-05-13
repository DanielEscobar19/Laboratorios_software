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

int main() {
  cout << "\n    | Start |" << endl;

  run();
  
  cout << "\n   | End |" << endl;
}