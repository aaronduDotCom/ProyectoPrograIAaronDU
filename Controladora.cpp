//
// Created by Oscar on 27/1/2026.
//

#include "Estudiante.h"
#include "Profesor.h"
#include "Controladora.h"
#include "UniversidadAlbertoMagno.h"

bool Controladora::registrarEstudiante(UniversidadAlbertoMagno* u, string nombre, string id) {
    if (u->getListaEstudiantes()->buscar(id) != nullptr) {
        return false;
    }

    Persona* estudiante = new Estudiante(nombre, id);
    u->getListaEstudiantes()->agregarPrimero(estudiante);
    return true;
}

bool Controladora::registrarProfesores(UniversidadAlbertoMagno *u, string nombre, string id) {
    if (u->getListaProfesores()->buscar(id) != nullptr) {
        return false;
    }

    Persona* profesor = new Profesor(nombre, id);
    u->getListaProfesores()->agregarPrimero(profesor);
    return true;
}

bool Controladora::registrarCursos(UniversidadAlbertoMagno *u, string id, string nombre, int dia, int hora,string idProfesor, int limiteCupos) {
    if (u->getListaCursos()->buscar(id) != nullptr) {
        return false;
    }

    if (dia < 0 || dia > 7) return false;
    if (hora < 0 || hora > 12) return false;

    Persona*aux = u->getListaProfesores()->buscar(idProfesor);
    if (aux==nullptr) return false;

    Curso* curso = new Curso(id, nombre, dia, hora, aux, limiteCupos);
    u->getListaCursos()->agregarPrimero(curso);
    return true;
}

bool Controladora::expulsarEstudiante(UniversidadAlbertoMagno *u, string id) {
    Persona* e = u->getListaEstudiantes()->buscar(id);
    if (e == nullptr) {
        return false;
    }

    u->getListaEstudiantes()->eliminar(id);
    return true;
}

bool Controladora::despedirProfesor(UniversidadAlbertoMagno *u, string id) {
    Persona* p = u->getListaProfesores()->buscar(id);
    if (p == nullptr) {
        return false;
    }

    u->getListaProfesores()->eliminar(id);
    return true;
}

bool Controladora::eliminarCurso(UniversidadAlbertoMagno *u,string id) {
    Curso* c = u->getListaCursos()->buscar(id);
    if (c == nullptr) {
        return false;
    }

    u->getListaCursos()->eliminar(id);
    return true;
}

bool Controladora::reasignarProfesor(UniversidadAlbertoMagno *u, string idCurso, string idProfesor) {
    Curso *cursoAux = u->getListaCursos()->buscar(idCurso);
    Persona *profesorAux = u->getListaProfesores()->buscar(idProfesor);

    if (cursoAux == nullptr || profesorAux == nullptr) {
        return false;
    }

    if (profesorAux->getHorario()->buscarCurso(idCurso)==nullptr) {
        cursoAux->setProfesorAsignado(profesorAux);
        profesorAux->matricularCurso(cursoAux);
        return true;
    }

    return false;
}

bool Controladora::matricularCurso(UniversidadAlbertoMagno *u, string idEstudiante, string idCursos) {
    Persona*aux=u->getListaEstudiantes()->buscar(idEstudiante);
    Curso*aux2=u->getListaCursos()->buscar(idCursos);

    if (aux==nullptr||aux2==nullptr) return false;

    aux->matricularCurso(aux2);
    return true;
}

bool Controladora::desmatricularCurso(UniversidadAlbertoMagno *u, string idEstudiante, string idCursos) {
    Persona*aux=u->getListaEstudiantes()->buscar(idEstudiante);
    Curso*aux2=u->getListaCursos()->buscar(idCursos);

    if (aux==nullptr||aux2==nullptr) return false;

    aux->desmatricularCurso(aux2->getCodigo());
    return true;
}

string Controladora::mostrarEstudiante(UniversidadAlbertoMagno *u, string id) {
    Persona*aux = u->getListaEstudiantes()->buscar(id);

    if (aux==nullptr) return "";

    return aux->toString();
}

string Controladora::mostrarProfesor(UniversidadAlbertoMagno *u, string id) {
    Persona*aux = u->getListaProfesores()->buscar(id);

    if (aux==nullptr) return "";

    return aux->toString();
}

string Controladora::mostrarCurso(UniversidadAlbertoMagno *u, string id) {
    Curso*aux = u->getListaCursos()->buscar(id);

    if (aux==nullptr) return "";

    return aux->toString();
}

string Controladora::mostrarEstudiantePorCurso(UniversidadAlbertoMagno *u,string idCurso,string idEstudiante) {
    Curso *aux= u->getListaCursos()->buscar(idCurso);
    if (aux==nullptr) return "";

    Persona*aux2=aux->getListaEstudiantes()->buscar(idEstudiante);
    if (aux2==nullptr) return "";

    return aux2->toString();
}

string Controladora::mostrarProfesorAsignado(UniversidadAlbertoMagno *u, string id) {
    Curso *aux= u->getListaCursos()->buscar(id);
    if (aux==nullptr) return "";

    return aux->getProfesorAsignado()->toString();
}

string Controladora::mostrarTodosLosEstudiantes(UniversidadAlbertoMagno *u) {
    return u->getListaEstudiantes()->toString();
}

string Controladora::mostrarTodosLosProfesores(UniversidadAlbertoMagno *u) {
    return u->getListaProfesores()->toString();
}

string Controladora::mostrarTodosLosCursos(UniversidadAlbertoMagno *u) {
    return u->getListaCursos()->toString();
}

double Controladora::mostrarPromedioPorEstudiante(UniversidadAlbertoMagno *u, string id) {
    Persona *aux= u->getListaEstudiantes()->buscar(id);
    if (aux==nullptr) return 0;

    return aux->getCalificacionGlobal();
}

double Controladora::mostrarPromedioPorProfesor(UniversidadAlbertoMagno *u, string id) {
    Persona *aux= u->getListaProfesores()->buscar(id);
    if (aux==nullptr) return 0;

    return aux->getCalificacionGlobal();
}

double Controladora::mostrarPromedioPorCurso(UniversidadAlbertoMagno* u, string id) {
    Curso* c = u->getListaCursos()->buscar(id);
    if (c == nullptr) {
        return 0;
    }

    return c->calcularPromedio();
}

string Controladora::mostrarHorarioProfesor(UniversidadAlbertoMagno *u, string id) {
    Persona *aux= u->getListaProfesores()->buscar(id);
    if (aux==nullptr) return "";

    return aux->getHorario()->toString();
}

string Controladora::mostrarHorarioAlumno(UniversidadAlbertoMagno *u, string id) {
    Persona *aux= u->getListaEstudiantes()->buscar(id);
    if (aux==nullptr) return "";

    return aux->getHorario()->toString();
}
