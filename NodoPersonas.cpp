//
// Created by Oscar on 30/1/2026.
//

#include "NodoPersonas.h"

NodoPersonas::NodoPersonas() {
    sig = nullptr;
    persona = nullptr;
}

NodoPersonas::NodoPersonas(NodoPersonas *sig, Persona *persona) {
    this->sig = sig;
    this->persona = persona;
}

NodoPersonas::~NodoPersonas() {
}

NodoPersonas * NodoPersonas::getSig() {return sig;}

void NodoPersonas::setSig(NodoPersonas *sig) {this->sig = sig;}

Persona * NodoPersonas::getPersona() {return persona;}

void NodoPersonas::setPersona(Persona *persona) {this->persona = persona;}