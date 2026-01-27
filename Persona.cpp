//
// Created by Oscar on 27/1/2026.
//

#include "Persona.h"

Persona::Persona() {
    nombreCompleto="";
    identificacion=0;
}

Persona::Persona(string nombre, int id) {
    nombreCompleto=nombre;
    identificacion=id;
}

Persona::~Persona() {
}

string Persona::getNombre() {return nombreCompleto;}

void Persona::setNombre(string nombre) {nombreCompleto=nombre;}

int Persona::getId() {return identificacion;}

void Persona::setId(int id) {identificacion=id;}

string Persona::toString() {
    stringstream ss;
    ss << nombreCompleto << " " << identificacion << endl;
    return ss.str();
}
