//
// Created by Oscar on 27/1/2026.
//

#include "UniversidadAlbertoMagno.h"

UniversidadAlbertoMagno::UniversidadAlbertoMagno() {
    listaEstudiantes = new ListaPersonas();
    listaProfesores  = new ListaPersonas();
    listaCursos      = new ListaCursos();
}

UniversidadAlbertoMagno::~UniversidadAlbertoMagno() {
    eliminarEstudiantes();
    eliminarProfesores();
    eliminarCursos();

    delete listaEstudiantes;
    delete listaProfesores;
    delete listaCursos;
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

void UniversidadAlbertoMagno::cargarDatos() {
    FILE*archivoEstudiantesLeer=fopen("archivoEstudiantes.txt","r");
    FILE*archivoProfesoresLeer=fopen("archivoProfesores.txt","r");
    FILE*archivoCursosLeer=fopen("archivoCursos.txt","r");

    if (archivoEstudiantesLeer)
        listaEstudiantes->cargarDatosEst(archivoEstudiantesLeer);
    if (archivoProfesoresLeer)
        listaProfesores->cargarDatosProf(archivoProfesoresLeer);
    if (archivoCursosLeer)
        listaCursos->cargarDatos(archivoCursosLeer, listaProfesores);

    if (archivoEstudiantesLeer) fclose(archivoEstudiantesLeer);
    if (archivoProfesoresLeer) fclose(archivoProfesoresLeer);
    if (archivoCursosLeer) fclose(archivoCursosLeer);
}

void UniversidadAlbertoMagno::guardarDatos() {
    FILE*archivoEstudiantes=fopen("archivoEstudiantes.txt","w");
    FILE*archivoProfesores=fopen("archivoProfesores.txt","w");
    FILE*archivoCursos=fopen("archivoCursos.txt","w");

    if (!archivoEstudiantes||!archivoProfesores||!archivoCursos) {
        printf("Error: Alguno o todos los archivos no se pudieron abrir\n");
        return;
    }

    listaEstudiantes->guardarDatos(archivoEstudiantes);
    listaProfesores->guardarDatos(archivoProfesores);
    listaCursos->guardarDatos(archivoCursos);

    fclose(archivoEstudiantes);
    fclose(archivoProfesores);
    fclose(archivoCursos);
}
