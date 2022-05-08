#ifndef MM_H
#define MM_H
#include <vector>
#include <typeinfo>
#include <iostream>
#include "Monstruo.h"
#include "Agente.h"


using namespace std;

class MM: public Monstruo {
    private:
        vector<Monstruo * > miembros;
        bool verificarTipo(Monstruo * monstruo);

    public:
        MM(int id = 0);
        void agregarMiembro(Monstruo * monstruo);
        void quitarMiembro(Monstruo * monstruo);
        int atacar(Agente * agente);
        string toString();

};
#endif  // MM_H