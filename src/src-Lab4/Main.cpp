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
  int monstruosCreados = 4;
  vector<Wumpus *> monstruosWumpus;
  MM manadaWumpus(++ids);

  cout << "Creacion de wumpus ----------------------------------------" << endl;
  for (int i = 0; i < monstruosCreados; ++i) {
    Wumpus * temp = new Wumpus(++ids);
    temp->setManada(&manadaWumpus);
    monstruosWumpus.push_back(temp);
    cout << temp->toString() << endl;
  }

  cout << endl << "Creacion de manada ----------------------------------------" << endl;
  cout << manadaWumpus.toString() << endl;

  cout << endl << "Creacion de Wumpus solitario ----------------------------------------" << endl;
  Wumpus wumpuSolitario(++ids);
  cout << wumpuSolitario.toString() << endl;
  cout << "Wumpus solitario intenta enviar un mensaje:" << endl;
  wumpuSolitario.enviarMensaje("Encontre al cazador.");

  cout << endl << "Envio de mensajes----------------------------------------" << endl;
  cout << "Wumpus #" << monstruosWumpus[0]->getCurrentID() << " intenta enviar un mensaje:" << endl;
  monstruosWumpus[0]->enviarMensaje("Encontre al cazador.");

  for (int i = 0; i < monstruosWumpus.size(); ++i) {
    delete monstruosWumpus[i];
  }
}

int main() {
  cout << "\n    | Start |" << endl;

  run();
  
  cout << "\n   | End |" << endl;
}