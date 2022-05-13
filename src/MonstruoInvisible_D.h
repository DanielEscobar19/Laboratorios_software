#ifndef MONSTRUOPINVISIBLE_D_H
#define MONSTRUOPINVISIBLE_D_H
#include <iostream>
#include <string>
#include "Monstruos.h"
using namespace std;
class MonstruoInvisible_D: public Monstruos {
 private:
    Monstruos & monstruos;
    bool invisibilidad = false;
 public:
    MonstruoInvisible_D(Monstruos & monstruos, bool invisibilidad, int id);
    ~MonstruoInvisible_D();
    string toString();
    void activarInvisibilidad();
    void desActivarInvisibilidad();
};
#endif // MONSTRUOPINVISIBLE_H
