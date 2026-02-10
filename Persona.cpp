//
// Created by Oscar on 27/1/2026.
//

#include "Persona.h"

Persona::Persona() {
    nombreCompleto="";
    identificacion="";
}

Persona::Persona(string identificacion, string nombreCompleto) {
    this->identificacion=identificacion;
    this->nombreCompleto=nombreCompleto;
}

string Persona::getNombre() {return nombreCompleto;}

void Persona::setNombre(string nombre) {nombreCompleto=nombre;}

string Persona::getId() {return identificacion;}

void Persona::setId(string id) {identificacion=id;}

string Persona::toString() {
    stringstream ss;
    ss << identificacion << ";" << nombreCompleto << "\n";
    return ss.str();
}
