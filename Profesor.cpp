//
// Created by Oscar on 27/1/2026.
//

#include "Profesor.h"

Profesor::Profesor():Persona() {
    horario = new Horario();
}

Profesor::Profesor(string nombre, int id):Persona(nombre,id) {
    horario = new Horario();
}

Profesor::~Profesor() {
    delete horario;
}

string Profesor::toString() {
    stringstream ss;
    ss << Persona::toString();
    ss << horario->toString() << endl;
    return ss.str();
}
