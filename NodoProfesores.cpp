//
// Created by Oscar on 27/1/2026.
//

#include "NodoProfesores.h"

NodoProfesores::NodoProfesores() {
    sig=nullptr;
    profesor=nullptr;
}

NodoProfesores::NodoProfesores(NodoProfesores *sig, Profesor *profesor) {
    this->sig=sig;
    this->profesor=profesor;
}

NodoProfesores::~NodoProfesores() {
}

NodoProfesores * NodoProfesores::getSig() {return sig;}

void NodoProfesores::setSig(NodoProfesores *sig) {this->sig=sig;}

Profesor * NodoProfesores::getProfesor() {return profesor;}

void NodoProfesores::setProfesor(Profesor *profesor) {this->profesor=profesor;}
