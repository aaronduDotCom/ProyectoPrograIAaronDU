//
// Created by Oscar on 27/1/2026.
//

#include "Curso.h"

Curso::Curso(int codigo,
    string nombre,
    int dia,
    int hora,
    Persona *profesor,
    int limiteCupos)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->dia = dia;
    this->hora = hora;
    this->profesorAsignado = profesor;
    this->listaEstudiantes = new ListaPersonas();
    this->limiteCupos = limiteCupos;
    this->cantidadEstudiantes = 0;
}

Curso::~Curso() {
}

Persona * Curso::getProfesorAsignado() {return this->profesorAsignado;}

ListaPersonas * Curso::getListaEstudiantes() {return this->listaEstudiantes;}

bool Curso::agregarEstudiante(Persona*estudiante) {
    if (limiteCupos && estudiante!=nullptr) {
        listaEstudiantes->agregarPrimero(estudiante);
        cantidadEstudiantes++;
        return true;
    }
    return false;
}

bool Curso::eliminarEstudiante(Persona*estudiante) {
    if (listaEstudiantes->eliminar(estudiante->getId())) {
        return true;
    }
    return false;
}

int Curso::getCodigo() {return codigo;}

string Curso::getNombre() {return nombre;}

int Curso::getDia() {return dia;}

int Curso::getHora() {return hora;}

void Curso::setProfesorAsignado(Persona *profesor) {this->profesorAsignado = profesor;}

string Curso::toString() {
    stringstream ss;
    ss<<nombre<<endl<<codigo<<profesorAsignado->getNombre()<<"\n\n";
    return ss.str();
}

double Curso::calcularPromedio() {
    double suma = 0;
    int cantidad = 0;

    NodoPersonas* actual = listaEstudiantes->getPrimero();
    while (actual != nullptr) {
        suma += actual->getPersona()->getCalificacionGlobal();
        cantidad++;
        actual = actual->getSig();
    }

    if (cantidad == 0) {
        return 0;
    }

    return suma / cantidad;
}

