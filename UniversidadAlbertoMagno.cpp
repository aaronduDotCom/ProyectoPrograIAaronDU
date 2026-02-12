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
    //1
    FILE*archivoProfesoresLeer=fopen("archivoProfesores.txt","r");
    //2
    FILE*archivoCursosLeer=fopen("archivoCursos.txt","r");
    //3
    FILE*archivoEstudiantesLeer=fopen("archivoEstudiantes.txt","r");
    //4
    FILE* archivoHorariosEst = fopen("archivoHorariosEst.txt", "r");
    //5
    FILE* archivoHorariosProf = fopen("archivoHorariosProf.txt", "r");


    if (archivoProfesoresLeer)
        listaProfesores->cargarDatosProf(archivoProfesoresLeer);
    if (archivoCursosLeer)
        listaCursos->cargarDatos(archivoCursosLeer, listaProfesores);
    if (archivoEstudiantesLeer)
        listaEstudiantes->cargarDatosEst(archivoEstudiantesLeer);
    if (archivoHorariosEst)
        listaEstudiantes->cargarHorarios(archivoHorariosEst, listaCursos);
    if (archivoHorariosProf)
        listaProfesores->cargarHorarios(archivoHorariosProf, listaCursos);

    if (archivoProfesoresLeer) fclose(archivoProfesoresLeer);
    if (archivoCursosLeer) fclose(archivoCursosLeer);
    if (archivoEstudiantesLeer) fclose(archivoEstudiantesLeer);

    if (archivoHorariosEst) fclose(archivoHorariosEst);
    if (archivoHorariosProf) fclose(archivoHorariosProf);
}

void UniversidadAlbertoMagno::guardarDatos() {
    FILE*archivoProfesores=fopen("archivoProfesores.txt","w");
    FILE*archivoCursos=fopen("archivoCursos.txt","w");
    FILE*archivoEstudiantes=fopen("archivoEstudiantes.txt","w");

    FILE*archivoHorariosEst = fopen("archivoHorariosEst.txt", "w");
    FILE*archivoHorariosProf = fopen("archivoHorariosProf.txt", "w");

    if (!archivoEstudiantes||!archivoProfesores||!archivoCursos||!archivoHorariosEst||!archivoHorariosProf) {
        printf("Error: Alguno o todos los archivos no se pudieron abrir\n");
        return;
    }

    listaProfesores->guardarDatos(archivoProfesores);
    listaCursos->guardarDatos(archivoCursos);
    listaEstudiantes->guardarDatos(archivoEstudiantes);

    listaEstudiantes->guardarHorarios(archivoHorariosEst);
    listaProfesores->guardarHorarios(archivoHorariosProf);

    fclose(archivoEstudiantes);
    fclose(archivoProfesores);
    fclose(archivoCursos);

    fclose(archivoHorariosEst);
    fclose(archivoHorariosProf);
}
