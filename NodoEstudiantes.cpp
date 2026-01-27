//
// Created by Oscar on 27/1/2026.
//

#include "NodoEstudiantes.h"

NodoEstudiantes::NodoEstudiantes() {
    sig = nullptr;
    estudiante = nullptr;
}

NodoEstudiantes::NodoEstudiantes(NodoEstudiantes *sig, Estudiante *estudiante) {
    this->sig = sig;
    this->estudiante = estudiante;
}

NodoEstudiantes::~NodoEstudiantes() {
}

NodoEstudiantes * NodoEstudiantes::getSig() {return sig;}

void NodoEstudiantes::setSig(NodoEstudiantes *sig) {this->sig = sig;}

Estudiante * NodoEstudiantes::getEstudiante() {return estudiante;}

void NodoEstudiantes::setEstudiante(Estudiante *estudiante) {this->estudiante = estudiante;}
