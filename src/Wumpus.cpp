#include "Wumpus.h"

Wumpus::Wumpus(int id = 0, MM * manada = nullptr):Monstruo(id, manada) {}


int Wumpus::atacar(Agente * agente) {
    agente->setVida(agente->getVida() - DANYO_WUMPUS);
}

string Wumpus::toString(){
    // id + tipo
    string respuesta = "Wumpus {" + std::to_string(this->getCurrentID()) + "}"; 
    // atrapado
    respuesta += (this->atrapado) ? " , ya fue atrapado" : " , sigue libre";
    // manada
    respuesta += (this->manada) ? 
    " y pertenece a la manada " + std::to_string(this->manada->getCurrentID())
    : " y no tiene manada";

    return respuesta;
}