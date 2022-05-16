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

#include "MonstruoReplicable_E.h"
#include "MonstruoReplicable_D.h"

#include "MonstruoConMemoria_D.h"
#include "MonstruoConMemoria_E.h"

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
void runLab2_E() {
  cout << "\nEjecutando solucion estatica (con plantillas)" << endl;
  int ids = 0;
  Cazador cazador;

  cout << endl << "Creacion de 3 Wumpus:" << endl;
  Wumpus wumpus1(++ids);
  cout << wumpus1.toString() << endl;
  Wumpus wumpus2(++ids);
  cout << wumpus2.toString() << endl; 
  Wumpus wumpus3(++ids);
  cout << wumpus3.toString() << endl;
  Wumpus wumpus4(++ids);
  cout << wumpus3.toString() << endl;
  
  cout << endl << "Creacion manada de Wumpus y se agregan los Wumpus a la manada:" << endl;
  MM manadaWumpus(++ids);
  wumpus1.setManada(&manadaWumpus);
  wumpus2.setManada(&manadaWumpus);
  wumpus3.setManada(&manadaWumpus);
  cout << manadaWumpus.toString() << endl;
  
  cout << "\n========================================================" << endl;
  cout << "Se activan poderes" << endl;
  cout << endl << "Se crea Wumpus 1 invisible" << endl;
  MonstruoInvisible_S <Wumpus> wumpusInvisible1 {true, wumpus1};
  cout << wumpusInvisible1.toString() << endl;

  cout << endl << "Se crea Wumpus 2 replicable" << endl;
  MonstruoReplicable_E <Wumpus> wumpusReplicable1 {true, 3, wumpus2};
  cout << wumpusReplicable1.toString() << endl;
  
  cout << endl << "Se crea Wumpus 3 con memoria" << endl;
  MonstruoConMemoria_E <Wumpus> wumpusConMemoria {true, wumpus3};
  cout << wumpusConMemoria.toString() << endl;
  cout << cazador.toString() << endl;

  wumpusConMemoria.atacar(&cazador);
  wumpusConMemoria.atacar(&cazador);
  cout << wumpusConMemoria.toString() << endl;
  cout << cazador.toString() << endl;
  cout << "El wumpus con memoria ataco dos veces al cazador con: ";
  cout << wumpusConMemoria.buscarEnMemoria(0);
  cout << " y " << wumpusConMemoria.buscarEnMemoria(1) << " de daño" <<endl;

  cout << "\nCombina replicabilidad e invisivilidad" << endl;
  MonstruoReplicable_E <MonstruoInvisible_S <Wumpus> > wumpusRepTransp1 {true, 7,wumpusInvisible1};
  cout << wumpusRepTransp1.toString() << endl;
  
  cout << "\nCombina replicabilidad, invisivilidad y memoria" << endl;
  MonstruoConMemoria_E <MonstruoReplicable_E <MonstruoInvisible_S <Wumpus> > > superWumpus {true, wumpusRepTransp1};
  cout << superWumpus.toString() << endl;
  
  cout << "\nManada invisible" << endl;
  MonstruoInvisible_S <MM> manadaInvisible1{true, manadaWumpus};
  cout << manadaInvisible1.toString() << endl;
  
  cout << "\nManada Replicable" << endl;
  MonstruoReplicable_E <MM> manadaReplicable{true, 3, manadaWumpus};
  cout << manadaReplicable.toString() << endl;
  
  cout << "\nManada con Memoria" << endl;
  MonstruoConMemoria_E <MM> manadaConMemoria{true, manadaWumpus};
  cout << manadaConMemoria.toString() << endl;
  

  cout << "\n========================================================" << endl;
  cout << "Desactivacion de los poderes" << endl;
  cout << "\nSe desactiva el poder al wumpusReplicable" << endl;
  wumpusReplicable1.desactivarReplicabilidad();
  cout << wumpusReplicable1.toString() << endl;

  cout << "\nSe desactiva el poder al wumpusInvisible" << endl;
  wumpusInvisible1.desActivarInvisibilidad();
  cout << wumpusInvisible1.toString() << endl;
  
  cout << "\nSe desactiva el poder de Memoria" << endl;
  wumpusConMemoria.desactivarMemoria();
  cout << wumpusConMemoria.toString() << endl;

  cout << "\nSe desactiva el poder a la manada" << endl;
  manadaInvisible1.desActivarInvisibilidad();
  cout << manadaInvisible1.toString() << endl;

  manadaInvisible1.desActivarInvisibilidad();
  cout << manadaInvisible1.toString() << endl;



}

// ============================================================================

void runLab2_D() {
  cout << "Ejecutando solucion Dinamica (por herencia)" << endl;
  int ids = 0;
  Cazador cazador;

  cout << endl << "Creacion de 3 Wumpus:" << endl;
  Wumpus wumpus1(++ids);
  cout << wumpus1.toString() << endl;
  Wumpus wumpus2(++ids);
  cout << wumpus2.toString() << endl; 
  Wumpus wumpus3(++ids);
  cout << wumpus3.toString() << endl;
  
  cout << endl << "Creacion manada de Wumpus y se agregan los Wumpus a la manada:" << endl;
  MM manadaWumpus(++ids);
  wumpus1.setManada(&manadaWumpus);
  wumpus2.setManada(&manadaWumpus);
  wumpus3.setManada(&manadaWumpus);
  cout << manadaWumpus.toString() << endl;
  
  cout << "\n========================================================" << endl;
  cout << "Se activan poderes" << endl;
  cout << endl << "Se crea Wumpus 1 invisible" << endl;
  MonstruoInvisible_D wumpusInvisible1 {wumpus1, true};
  cout << wumpusInvisible1.toString() << endl;

  cout << endl << "Se crea Wumpus 2 replicable" << endl;
  MonstruoReplicable_D wumpusReplicable1 {wumpus2, true, 5};
  cout << wumpusReplicable1.toString() << endl;
  
  cout << endl << "Se crea Wumpus 3 con memoria" << endl;
  MonstruoConMemoria_D wumpusConMemoria {wumpus3, true};
  cout << wumpusConMemoria.toString() << endl;
  cout << cazador.toString() << endl;
  wumpusConMemoria.atacar(&cazador);
  wumpusConMemoria.atacar(&cazador);
  cout << wumpusConMemoria.toString() << endl;
  cout << cazador.toString() << endl;
  cout << "El wumpus con memoria ataco dos veces al cazador con: ";
  cout << wumpusConMemoria.buscarEnMemoria(0);
  cout << " y " << wumpusConMemoria.buscarEnMemoria(1) << " de daño" <<endl;

  cout << "\nCombina replicabilidad e invisivilidad" << endl;
  MonstruoReplicable_D wumpusRepTransp1{wumpusInvisible1, true, 2};
  cout << wumpusRepTransp1.toString() << endl;
  
  cout << "\nCombina replicabilidad, invisivilidad y memoria" << endl;
  MonstruoConMemoria_D superWumpus {wumpusRepTransp1, true};
  cout << superWumpus.toString() << endl;
  
  cout << "\nManada invisible" << endl;
  MonstruoInvisible_D manadaInvisible1(manadaWumpus,true);
  cout << manadaInvisible1.toString() << endl;
  
  cout << "\nManada Replicable" << endl;
  MonstruoReplicable_D manadaReplicable(manadaWumpus, true, 2);
  cout << manadaReplicable.toString() << endl;
  
  cout << "\nManada con Memoria" << endl;
  MonstruoConMemoria_D manadaConMemoria(manadaWumpus, true);
  cout << manadaConMemoria.toString() << endl;

  cout << "\n========================================================" << endl;
  cout << "Desactivacion de los poderes" << endl;
  cout << "\nSe desactiva el poder al wumpusReplicable" << endl;
  wumpusReplicable1.desactivarReplicabilidad();
  cout << wumpusReplicable1.toString() << endl;

  cout << "\nSe desactiva el poder al wumpusInvisible" << endl;
  wumpusInvisible1.desActivarInvisibilidad();
  cout << wumpusInvisible1.toString() << endl;
  
  cout << "\nSe desactiva el poder de Memoria" << endl;
  wumpusConMemoria.desactivarMemoria();
  cout << wumpusConMemoria.toString() << endl;

  cout << "\nSe desactiva el poder a la manada" << endl;
  manadaInvisible1.desActivarInvisibilidad();
  cout << manadaInvisible1.toString() << endl;
  
}

int main() {
  cout << "\n    | Start |" << endl;

  runLab2_E();
  cout << "________________________________________________________" << endl;
  cout << "\n\n\n\n\n\n\n" << endl;
  cout << "________________________________________________________" << endl;
  runLab2_D();

  cout << "\n   | End |" << endl;
}
