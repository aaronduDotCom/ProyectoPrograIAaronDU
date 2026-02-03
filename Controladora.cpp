//
// Created by Oscar on 27/1/2026.
//

#include "Estudiante.h"
#include "Profesor.h"
#include "Controladora.h"
#include "UniversidadAlbertoMagno.h"

bool Controladora::registrarEstudiante(UniversidadAlbertoMagno* u, string nombre, int id) {
    if (u->getListaEstudiantes()->buscar(id) != nullptr) {
        return false;
    }

    Persona* estudiante = new Estudiante(nombre, id);
    u->getListaEstudiantes()->agregarPrimero(estudiante);
    return true;
}

bool Controladora::registrarProfesores(UniversidadAlbertoMagno *u, string nombre, int id) {
    if (u->getListaProfesores()->buscar(id) != nullptr) {
        return false;
    }

    Persona* profesor = new Profesor(nombre, id);
    u->getListaEstudiantes()->agregarPrimero(profesor);
    return true;
}

bool Controladora::registrarCursos(UniversidadAlbertoMagno *u, int id, string nombre, int dia, int hora,int idProfesor, int limiteCupos) {
    if (u->getListaProfesores()->buscar(id) != nullptr) {
        return false;
    }

    Persona*aux = u->getListaProfesores()->buscar(idProfesor);
    Curso* curso = new Curso(id, nombre, dia, hora, aux, limiteCupos);
    u->getListaCursos()->agregarPrimero(curso);
    return true;
}

bool Controladora::expulsarEstudiante(UniversidadAlbertoMagno *u, int id) {
    Persona* e = u->getListaEstudiantes()->buscar(id);
    if (e == nullptr) {
        return false;
    }

    u->getListaEstudiantes()->eliminar(id);
    delete e;
    return true;
}

bool Controladora::despedirProfesor(UniversidadAlbertoMagno *u, int id) {
    Persona* p = u->getListaProfesores()->buscar(id);
    if (p == nullptr) {
        return false;
    }

    u->getListaProfesores()->eliminar(id);
    delete p;
    return true;
}

bool Controladora::eliminarCurso(UniversidadAlbertoMagno *u,int id) {
    Curso* c = u->getListaCursos()->buscar(id);
    if (c == nullptr) {
        return false;
    }

    u->getListaProfesores()->eliminar(id);
    delete c;
    return true;
}

bool Controladora::reasignarProfesor(UniversidadAlbertoMagno *u, int idCurso, int idProfesor) {
    Curso *cursoAux = u->getListaCursos()->buscar(idCurso);
    Persona *profesorAux = u->getListaProfesores()->buscar(idProfesor);

    if (cursoAux == nullptr || profesorAux == nullptr) {
        return false;
    }

    cursoAux->setProfesorAsignado(profesorAux);
    return true;
}

bool Controladora::matricularCurso(UniversidadAlbertoMagno *u, int idEstudiante, int idCursos) {
    Persona*aux=u->getListaEstudiantes()->buscar(idEstudiante);
    Curso*aux2=u->getListaCursos()->buscar(idCursos);

    if (aux==nullptr||aux2==nullptr) return false;

    aux->matricularCurso(aux2);
}

bool Controladora::desmatricularCurso(UniversidadAlbertoMagno *u, int idEstudiante, int idCursos) {
    Persona*aux=u->getListaEstudiantes()->buscar(idEstudiante);
    Curso*aux2=u->getListaCursos()->buscar(idCursos);

    if (aux==nullptr||aux2==nullptr) return false;

    aux->desmatricularCurso(aux2->getCodigo());
}

string Controladora::mostrarEstudiante(UniversidadAlbertoMagno *u, int id) {
    Persona*aux = u->getListaEstudiantes()->buscar(id);

    if (aux==nullptr) return "";

    return aux->toString();
}

string Controladora::mostrarProfesor(UniversidadAlbertoMagno *u, int id) {
    Persona*aux = u->getListaProfesores()->buscar(id);

    if (aux==nullptr) return "";

    return aux->toString();
}

string Controladora::mostrarCurso(UniversidadAlbertoMagno *u, int id) {
    Curso*aux = u->getListaCursos()->buscar(id);

    if (aux==nullptr) return "";

    return aux->toString();
}

string Controladora::mostrarEstudiantePorCurso(UniversidadAlbertoMagno *u,int idCurso,int idEstudiante) {
    Curso *aux= u->getListaCursos()->buscar(idCurso);
    if (aux==nullptr) return "";

    Persona*aux2=aux->getListaEstudiantes()->buscar(idEstudiante);
    if (aux2==nullptr) return "";

    return aux2->toString();
}

string Controladora::mostrarProfesorAsignado(UniversidadAlbertoMagno *u, int id) {
    Curso *aux= u->getListaCursos()->buscar(id);
    if (aux==nullptr) return "";

    return aux->getProfesorAsignado()->toString();
}

string Controladora::mostrarTodosLosEstudiantes(UniversidadAlbertoMagno *u) {
    return u->getListaEstudiantes()->toString();
}

string Controladora::mostrarTodosLosProfesores(UniversidadAlbertoMagno *u) {
    return u->getListaEstudiantes()->toString();
}

string Controladora::mostrarTodosLosCursos(UniversidadAlbertoMagno *u) {
    return u->getListaCursos()->toString();
}

double Controladora::mostrarPromedioPorEstudiante(UniversidadAlbertoMagno *u, int id) {
    Persona *aux= u->getListaEstudiantes()->buscar(id);
    if (aux==nullptr) return 0;

    return aux->getCalificacionGlobal();
}

double Controladora::mostrarPromedioPorProfesor(UniversidadAlbertoMagno *u, int id) {
    Persona *aux= u->getListaProfesores()->buscar(id);
    if (aux==nullptr) return 0;

    return aux->getCalificacionGlobal();
}

double Controladora::mostrarPromedioPorCurso(UniversidadAlbertoMagno* u, int id) {
    Curso* c = u->getListaCursos()->buscar(id);
    if (c == nullptr) {
        return 0;
    }

    return c->calcularPromedio();
}

string Controladora::mostrarHorarioProfesor(UniversidadAlbertoMagno *u, int id) {
    Persona *aux= u->getListaProfesores()->buscar(id);
    if (aux==nullptr) return "";

    return aux->getHorario()->toString();
}

string Controladora::mostrarHorarioAlumno(UniversidadAlbertoMagno *u, int id) {
    Persona *aux= u->getListaEstudiantes()->buscar(id);
    if (aux==nullptr) return "";

    return aux->getHorario()->toString();
}
