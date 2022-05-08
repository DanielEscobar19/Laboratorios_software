#ifndef MONSTRUO_H
#define MONSTRUO_H
#include "Agente.h"
#include "MM.h"
#include <string>
using namespace std;

class Monstruo: public Agente {
    protected:
        int id;
        bool atrapado = false;
        MM * manada = nullptr;
        string pertenencia();
        void setAtrapado(bool capturado);

    public:
        Monstruo(int id = 0, MM * manada = nullptr);
        int atacar(Agente * agente);
        string toString();
        void setManada(MM * manada);
        void unsetManada(MM * manada);
};
#endif  // MONSTRUO_H