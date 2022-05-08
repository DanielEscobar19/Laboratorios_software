#ifndef MONSTRUO_H
#define MONSTRUO_H
#include "Agente.h"
#include "MM.h"
#include <string>
using namespace std;

#define DANYO_OMISION 5

class Monstruo: public Agente {
    protected:
        int id;
        bool atrapado = false;
        MM * manada = nullptr;
        virtual string pertenencia();

    public:
        Monstruo(int id = 0, MM * manada = nullptr);
        int atacar(Agente * agente);
        virtual string toString() = 0;  // modificado
        virtual void setManada(MM * manada);
        virtual void unsetManada();

        void setAtrapado();
        int getCurrentID();

};
#endif  // MONSTRUO_H
