#include "Cadejo.h"
Cadejo::Cadejo(int id = 0, MM * manada = nullptr):Monstruo(id, manada) {}


int Cadejo::atacar(Agente * agente) {
    agente->setVida(agente->getVida() - DANYO);
}

string Cadejo::toString() {
    cout << "Vida del cadejo {" << this->id << "} = " << this->vida << endl;
}