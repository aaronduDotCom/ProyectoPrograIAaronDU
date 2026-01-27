//
// Created by Oscar on 27/1/2026.
//

#include "Estudiante.h"

Estudiante::Estudiante():Persona() {
    horario = new Horario();
}

Estudiante::Estudiante(string nombre, int id) {
    horario = new Horario();
}

Estudiante::~Estudiante() {
    delete horario;
}

string Estudiante::toString() {
    stringstream ss;
    ss << Persona::toString();
    ss << horario->toString() << endl;
    return ss.str();
}
