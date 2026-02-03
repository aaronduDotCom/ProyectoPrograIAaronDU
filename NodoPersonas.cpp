//
// Created by Oscar on 30/1/2026.
//

#include "NodoPersonas.h"



NodoPersonas::NodoPersonas(Persona* persona, NodoPersonas* sig) {
    this->persona = persona;
    this->sig = sig;
}

NodoPersonas * NodoPersonas::getSig() {return sig;}

void NodoPersonas::setSig(NodoPersonas *sig) {this->sig = sig;}

Persona * NodoPersonas::getPersona() {return persona;}
