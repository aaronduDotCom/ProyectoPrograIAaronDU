//
// Created by Oscar on 27/1/2026.
//

#include "Profesor.h"

Profesor::Profesor():Persona() {
    horario = new Horario();
}

Profesor::Profesor(string nombre, string id):Persona(nombre,id) {
    horario = new Horario();
}

Profesor::~Profesor() {
    delete horario;
}

double Profesor::getCalificacionGlobal() {
    return 0;
}

void Profesor::setCalificacionGlobal(double) {
}

Horario *Profesor::getHorario() {return horario;}

bool Profesor::matricularCurso(Curso*curso) {

    Curso*aux=horario->buscarCurso(curso->getCodigo());

    if(aux!=nullptr && horario->franjaVacia(aux->getHora())) {

        if (aux->getListaEstudiantes()->agregarPrimero(this)) {
            horario->setCurso(curso);
            return true;
        }
    }
    return false;
}

bool Profesor::desmatricularCurso(string cod) {

    Curso*aux=horario->buscarCurso(cod);

    if(aux!=nullptr) {

        if (aux->getListaEstudiantes()->eliminar(this->getId())) {
            horario->setCurso(nullptr);
            return true;
        }
    }
    return false;
}

bool Profesor::asignarCurso(string cod) {
    Curso* aux = horario->buscarCurso(cod);
    if (aux != nullptr) {
        aux->setProfesorAsignado(this);
        return true;
    }
    return false;

}

bool Profesor::desasignarCurso(string cod) {
    Curso* aux = horario->buscarCurso(cod);
    if (aux != nullptr) {
        aux->setProfesorAsignado(nullptr);
        return true;
    }
    return false;
}

void Profesor::asignarNota(string codCur, string codEst, double nuevaNota) {
    horario->buscarCurso(codCur)->getListaEstudiantes()->buscar(codEst)->setCalificacionGlobal(nuevaNota);
}

string Profesor::toString() {
    stringstream ss;
    ss << Persona::toString();
    return ss.str();
}

double Profesor::calcularPromedio() {
    double suma = 0;
    int cantidad = 0;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 11; j++) {

            Curso* c = horario->getCurso(i, j);
            if (c == nullptr) {
                continue;
            }

            double promCurso = c->calcularPromedio();
            if (promCurso > 0) {
                suma += promCurso;
                cantidad++;
            }
        }
    }

    if (cantidad == 0) {
        return 0;
    }

    return suma / cantidad;
}

