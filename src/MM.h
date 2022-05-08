#ifndef MM_H
#define MM_H

#include <vector>
#include <typeinfo>
#include <iostream>

#include "Monstruos.h" /* Agente */

using namespace std;

class Monstruo;
class MM: public Monstruos {
    private:
        vector<Monstruo * > miembros;
        bool verificarTipo(Monstruo * monstruo);

    public:
        MM(int id = 0);
        void agregarMiembro(Monstruo * monstruo);
        void quitarMiembro(Monstruo * monstruo);
        int atacar(Agente * agente);
        string toString();

        string pertenencia();
        void setAtrapado();;

};
#endif  // MM_H