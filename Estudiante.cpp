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

double Estudiante::getCalificacionGlobal() {return calificacionGlobal;}

void Estudiante::setCalificacionGlobal(double calificacionGlobal) {this->calificacionGlobal = calificacionGlobal;}

Horario *Estudiante::getHorario() {return horario;}

bool Estudiante::matricularCurso(Curso*curso) {

    Curso*aux=horario->buscarCurso(curso->getCodigo());

    if(aux!=nullptr && horario->franjaVacia(aux->getHora())) {

        if (aux->agregarEstudiante(this)) {
            horario->setCurso(curso);
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
