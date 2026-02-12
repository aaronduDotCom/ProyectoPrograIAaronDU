//
// Created by Oscar on 27/1/2026.
//

#include "Curso.h"

Curso::Curso(string codigo,
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
    this->cuposAsignados = 0;
}

Persona * Curso::getProfesorAsignado() {return this->profesorAsignado;}

ListaPersonas * Curso::getListaEstudiantes() {return this->listaEstudiantes;}

string Curso::getCodigo() {return codigo;}

string Curso::getNombre() {return nombre;}

int Curso::getDia() {return dia;}

int Curso::getHora() {return hora;}

int Curso::getLimiteCupos() {return limiteCupos;}

int Curso::getCuposAsignados() {return cuposAsignados;}

void Curso::setCuposAsignados(int cuposAsignados) {this->cuposAsignados = cuposAsignados;}

void Curso::setProfesorAsignado(Persona *profesor) {this->profesorAsignado = profesor;}

//Hecho asi para leerlo despues
string Curso::toString() {
    stringstream ss;

    ss << codigo << ";"
       << nombre << ";"
        << dia << ";"
        << hora << ";";

    if (profesorAsignado != nullptr)
        ss << profesorAsignado->getId()<< ";";
    else
        ss << "NULL;";

    ss << limiteCupos<<"\n";

    return ss.str();
}

string Curso::toDisplayString() {
    stringstream ss;


    ss << "Codigo: " << codigo << "\n";
    ss << "Nombre: " << nombre << "\n";

    if (dia >= 0 && dia < 7)
        ss << "Dia: " << dia << "\n";
    else
        ss << "Dia: No definido\n";

    ss << "Hora: " << (hora + 8) << ":00\n";

    if (profesorAsignado != nullptr)
        ss << "Profesor asignado: " << profesorAsignado->getNombre()
           << " (" << profesorAsignado->getId() << ")\n";
    else
        ss << "Profesor asignado: No asignado\n";

    ss << "Limite de cupos: " << limiteCupos << "\n";

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

