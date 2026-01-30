//
// Created by Oscar on 27/1/2026.
//

#include "UniversidadAlbertoMagno.h"

UniversidadAlbertoMagno::UniversidadAlbertoMagno() {
    listaEstudiantes= new ListaPersonas;
    listaProfesores= new ListaPersonas;
    listaCursos= new ListaCursos;
}

UniversidadAlbertoMagno::~UniversidadAlbertoMagno() {
    eliminarEstudiantes();
    eliminarProfesores();
    eliminarCursos();
}

ListaPersonas * UniversidadAlbertoMagno::getListaEstudiantes() {
    return listaEstudiantes;
}

ListaPersonas * UniversidadAlbertoMagno::getListaProfesores() {
    return listaProfesores;
}

ListaCursos * UniversidadAlbertoMagno::getListaCursos() {
    return listaCursos;
}

void UniversidadAlbertoMagno::eliminarEstudiantes() {
    while (!listaEstudiantes->vacia()) {
        Persona* e= listaEstudiantes->getPrimero()->getPersona();
        listaEstudiantes->eliminarPrimero();
        delete e;
    }
}

void UniversidadAlbertoMagno::eliminarProfesores() {
    while (!listaProfesores->vacia()) {
        Persona* p= listaProfesores->getPrimero()->getPersona();
        listaProfesores->eliminarPrimero();
        delete p;
    }
}

void UniversidadAlbertoMagno::eliminarCursos() {
    while (!listaCursos->vacia()) {
        Curso* c= listaCursos->getPrimero()->getCurso();
        listaCursos->eliminarPrimero();
        delete c;
    }
}
