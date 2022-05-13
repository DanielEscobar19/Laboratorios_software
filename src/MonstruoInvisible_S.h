#ifndef MONSTRUOPINVISIBLE_S_H
#define MONSTRUOPINVISIBLE_S_H
#include <iostream>
#include <string>
#include "Monstruos.h"
using namespace std;

template < typename T >
class MonstruoInvisible_S : public T {
    // Impide que se use ColoredShape con un tipo T que NO herede de Shape!!!
    static_assert(is_base_of<Monstruos, T>::value, "Template argument must be a Shape");
  private:
    bool invisibilidad = false;
  public:
    template < typename ...Args >
    MonstruoInvisible_S(bool invisibilidad, Args ...args) : T(std::forward<Args>(args)...), invisibilidad {invisibilidad} {}

    ~MonstruoInvisible_S() {}

    string toString() {
        string resultado = T::toString();
        this->invisibilidad == true? resultado += " Es invisible." : resultado += " No es invisible.";
        return resultado;
    }

    void activarInvisibilidad() {
      this->invisibilidad = true;
    }

    void desActivarInvisibilidad() {
      this->invisibilidad = false;
    }
};
#endif // MONSTRUOPINVISIBLE_S_H
