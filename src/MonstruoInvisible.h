#ifndef MONSTRUOPINVISIBLE_H
#define MONSTRUOPINVISIBLE_H
#include <iostream>
#include <string>
#include "Monstruos.h"
using namespace std;
class MonstruoInvisible {
 private:
    Monstruos & monstruos;
    bool invisibilidad = false;
 public:
    MonstruoInvisible(Monstruos & monstruos, bool invisibilidad);
    ~MonstruoInvisible();
    string toString();
    void activarInvisibilidad();
    void desActivarInvisibilidad();
};
#endif // MONSTRUOPINVISIBLE_H
