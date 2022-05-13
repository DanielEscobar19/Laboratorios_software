#ifndef MONSTRUOS_H
#define MONSTRUOS_H

#include "Agente.h"
#include <string>
#include <typeinfo>

using namespace std;

class Monstruos: public Agente {
    protected:
        int id;
        bool atrapado = false;

    public:
        virtual int atacar(Agente * agente);
        virtual string toString();

        virtual string pertenencia();
        virtual void setAtrapado();
        int getCurrentID();

};
#endif  // MONSTRUOS_H
