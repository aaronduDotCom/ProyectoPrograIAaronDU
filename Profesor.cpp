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

double Profesor::getCalificacionGlobal() {
    return 0;
}

void Profesor::setCalificacionGlobal(double) {
}

Horario *Profesor::getHorario() {return horario;}

bool Profesor::matricularCurso(Curso *curso) {
    return false;
}

bool Profesor::desmatricularCurso(int cod) {
    return false;
}

bool Profesor::asignarCurso(int cod) {
    Curso* aux = horario->buscarCurso(cod);
    if (aux != nullptr) {
        aux->setProfesorAsignado(this);
        return true;
    }
    return false;

}

bool Profesor::desasignarCurso(int cod) {
    Curso* aux = horario->buscarCurso(cod);
    if (aux != nullptr) {
        aux->setProfesorAsignado(nullptr);
        return true;
    }
    return false;
}

void Profesor::asignarNota(int codCur, int codEst, int nuevaNota) {
    horario->buscarCurso(codCur)->getListaEstudiantes()->buscar(codEst)->setCalificacionGlobal(nuevaNota);
}

string Profesor::toString() {
    stringstream ss;
    ss << Persona::toString();
    ss << horario->toString() << endl;
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

