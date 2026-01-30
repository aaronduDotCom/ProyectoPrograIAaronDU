//
// Created by Oscar on 27/1/2026.
//

#include "UniversidadAlbertoMagno.h"

UniversidadAlbertoMagno::UniversidadAlbertoMagno() {
    listaEstudiantes= new ListaEstudiantes;
    listaProfesores= new ListaProfesores;
    listaCursos= new ListaCursos;
}

UniversidadAlbertoMagno::~UniversidadAlbertoMagno() {
    eliminarEstudiantes();
    eliminarProfesores();
    eliminarCursos();
}

ListaEstudiantes * UniversidadAlbertoMagno::getListaEstudiantes() {
    return listaEstudiantes;
}

ListaProfesores * UniversidadAlbertoMagno::getListaProfesores() {
    return listaProfesores;
}

ListaCursos * UniversidadAlbertoMagno::getListaCursos() {
    return listaCursos;
}

void UniversidadAlbertoMagno::eliminarEstudiantes() {
    while (!listaEstudiantes->vacia()) {
        Estudiante* e= listaEstudiantes->getPrimero()->getEstudiante();
        listaEstudiantes->eliminarPrimero();
        delete e;
    }
}

void UniversidadAlbertoMagno::eliminarProfesores() {
    while (!listaProfesores->vacia()) {
        Profesor* p= listaProfesores->getPrimero()->getProfesor();
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
