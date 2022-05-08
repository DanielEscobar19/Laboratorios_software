#include "MM.h"
MM::MM(int id = 0):Monstruo(id, nullptr) {}

bool MM::verificarTipo(Monstruo * monstruo) {
    // retorna true si el monstruo es del mismo tipo que la manada
    // falso en caso contrario
    try{
        return typeid(*this->miembros[0]) == typeid(*monstruo);
    } catch(...) {
        // caso del que el vector este vacio
        // devolvemos true porque si se peude agregar el minstruo al arreglo
        return true;
    }
}

void MM::agregarMiembro(Monstruo * monstruo) {
    if (this->verificarTipo(monstruo)) {
        this->miembros.push_back(monstruo);
    }
}

void MM::quitarMiembro(Monstruo * monstruo) {
    int i = 0;
    while (this->miembros[i++] != monstruo) {}
    this->miembros.erase(this->miembros.begin() + i);
}

int MM::atacar(Agente * agente) {
    for (int i = 0; i < this->miembros.size(); ++i) {
        this->miembros[i]->atacar(agente);
    }
}

string MM::toString() {
    try {
        cout << "Manada compuesta de " << this->miembros.size() << " monstruos de tipo: " \
            << typeid(*this->miembros[0]).name() << endl;
    } catch (...) {
        cout << "La manada no tiene tipo" << endl;

    }
}
