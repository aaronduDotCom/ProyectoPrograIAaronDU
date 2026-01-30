//
// Created by Oscar on 27/1/2026.
//

#include "Estudiante.h"
#include "Profesor.h"
#include "Controladora.h"

bool Controladora::registrarEstudiante(UniversidadAlbertoMagno *u, string nombre, int id) {
    Persona* estudiante=new Estudiante(nombre,id);
    u->getListaEstudiantes()->agregarPrimero(estudiante);

    if (u->getListaEstudiantes()->buscar(id)!=nullptr) {
        return true;
    }else {
        delete estudiante;
        return false;
    }
}

bool Controladora::registrarProfesores(UniversidadAlbertoMagno *u, string nombre, int id) {
    Persona* profesor=new Profesor(nombre,id);
    u->getListaProfesores()->agregarPrimero(profesor);

    if (u->getListaProfesores()->buscar(id)!=nullptr) {
        return true;
    }else {
        delete profesor;
        return false;
    }
}

bool Controladora::registrarCursos(UniversidadAlbertoMagno *u, int id, string nombre, int dia, int hora,
    Profesor *profesor, int limiteCupos) {
}

bool Controladora::expulsarEstudiante(UniversidadAlbertoMagno *u, int id) {
}

bool Controladora::despedirProfesor(UniversidadAlbertoMagno *u, int id) {
}

bool Controladora::eliminarCurso(UniversidadAlbertoMagno *u) {
}

bool Controladora::reasignarProfesor(UniversidadAlbertoMagno *u, int idCurso, int idProfesor) {
}

string Controladora::mostrarEstudiante(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarProfesor(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarCurso(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarEstudiantesPorProfesor(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarEstudiantePorCurso(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarProfesorAsignado(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarTodosLosEstudiantes(UniversidadAlbertoMagno *u) {
}

string Controladora::mostrarTodosLosProfesores(UniversidadAlbertoMagno *u) {
}

string Controladora::mostrarTodosLosCursos(UniversidadAlbertoMagno *u) {
}

string Controladora::mostrarPromedioPorEstudiant(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarPromedioPorProfesor(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarPromedioPorCurso(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarHorarioProfesor(UniversidadAlbertoMagno *u, int id) {
}

string Controladora::mostrarHorarioAlumno(UniversidadAlbertoMagno *u, int id) {
}
