//
// Created by Oscar on 27/1/2026.
//

#include "Estudiante.h"

Estudiante::Estudiante():Persona() {
    calificacionGlobal = 0;
    horario = new Horario();
}

Estudiante::Estudiante(string nombre, int id) {
    calificacionGlobal = 0;
    horario = new Horario();
}

Estudiante::~Estudiante() {
    delete horario;
}

string Estudiante::getTipo() {
    return "Estudiantes";
}

void Estudiante::setCalificacionGlobal(double calificacionGlobal) {this->calificacionGlobal = calificacionGlobal;}

bool Estudiante::matricularCurso(int cod) {

    Curso*aux=horario->buscarCurso(cod);

    if(aux!=nullptr && horario->franjaVacia(aux->getHora())) {

        if (aux->agregarEstudiante(this)) {
            horario->setCurso(aux);
            return true;
        }
    }
    return false;
}

bool Estudiante::desmatricularCurso(int cod) {

    Curso*aux=horario->buscarCurso(cod);

    if(aux!=nullptr) {

        if (aux->eliminarEstudiante(this)) {
            horario->setCurso(nullptr);
            return true;
        }
    }
    return false;
}


string Estudiante::toString() {
    stringstream ss;
    ss << Persona::toString();
    ss << horario->toString() << endl;
    return ss.str();
}
