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

string Profesor::getTipo() {
    return "Estudiantes";
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
