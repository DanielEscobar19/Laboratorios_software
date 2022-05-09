#ifndef MONSTRUO_H
#define MONSTRUO_H

#include "Monstruos.h"
#include "MM.h"

#include <string>
using namespace std;

#define DANYO_OMISION 5

// class MM;
class Monstruo: public Monstruos {
    protected:
        MM * manada = nullptr;
        int danyo;

    public:
        virtual int atacar(Agente * agente);
        virtual string toString() = 0;
        void setManada(MM * manada);
        void unsetManada();

        string pertenencia();
        void setAtrapado();
        int getDanyo();
        void nullManada();
};
#endif  // MONSTRUO_H
