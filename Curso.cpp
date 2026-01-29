//
// Created by Oscar on 27/1/2026.
//

#include "Curso.h"

Curso::Curso(int codigo,
    string nombre,
    int dia,
    int hora,
    Profesor *profesor,
    int limiteCupos)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->dia = dia;
    this->hora = hora;
    this->profesorAsignado = profesor;
    this->listaEstudiantes = new ListaEstudiantes();
    this->limiteCupos = limiteCupos;
    this->cantidadEstudiantes = 0;
}

Curso::~Curso() {
}

Profesor * Curso::getProfesorAsignado() {return this->profesorAsignado;}

ListaEstudiantes * Curso::getListaEstudiantes() {return this->listaEstudiantes;}

bool Curso::agregarEstudiante(Estudiante*estudiante) {
    if (limiteCupos && estudiante!=nullptr) {
        listaEstudiantes->agregarPrimero(estudiante);
        cantidadEstudiantes++;
        return true;
    }
    return false;
}

bool Curso::eliminarEstudiante(Estudiante*estudiante) {
    listaEstudiantes->
}

int Curso::getCodigo() {return codigo;}

string Curso::getNombre() {return nombre;}

int Curso::getDia() {return dia;}

int Curso::getHora() {return hora;}

void Curso::setProfesorAsignado(Profesor *profesor) {this->profesorAsignado = profesor;}

string Curso::toString() {
    stringstream ss;
    ss<<nombre<<endl<<codigo<<profesorAsignado->getNombre();
    return ss.str();
}
