//
// Created by Oscar on 27/1/2026.
//

#include "Estudiante.h"

Estudiante::Estudiante():Persona() {
    calificacionGlobal = 0;
    horario = new Horario();
}

Estudiante::Estudiante(string nombre, string id):Persona(nombre,id) {
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

    if(horario->franjaVacia(curso->getHora())) {

        if (curso->getListaEstudiantes()->agregarPrimero(this)) {
            horario->setCurso(curso);
            return true;
        }
    }
    return false;
}

bool Estudiante::desmatricularCurso(string cod) {
    Curso*aux=horario->buscarCurso(cod);

    if(aux!=nullptr) {

        if (aux->getListaEstudiantes()->eliminar(this->getId())) {
            horario->eliminarCurso(aux->getDia(),aux->getHora());
            return true;
        }
    }
    return false;
}


string Estudiante::toString() {
    stringstream ss;
    ss << Persona::toString();
    return ss.str();
}
