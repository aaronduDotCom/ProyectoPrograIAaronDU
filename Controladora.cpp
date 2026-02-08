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

    if (limiteCupos<1) return false;
    if (dia < 0 || dia > 7) return false;
    if (hora < 0 || hora > 12) return false;

    Persona*aux = u->getListaProfesores()->buscar(idProfesor);
    if (aux==nullptr || aux->getHorario()->buscarCurso(id)) return false;

    Curso* curso = new Curso(id, nombre, dia, hora, aux, limiteCupos);
    aux->matricularCurso(curso);
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

bool Controladora::cambiarNota(UniversidadAlbertoMagno *u, string idProf, string idCur, string idEst, double nuevaNota) {

    bool resultado = false;

    if (u != nullptr && nuevaNota >= 0 && nuevaNota <= 100) {

        Persona* profesor = u->getListaProfesores()->buscar(idProf);
        Persona* estudiante = u->getListaEstudiantes()->buscar(idEst);
        Curso* curso = u->getListaCursos()->buscar(idCur);

        if (profesor != nullptr && estudiante != nullptr && curso != nullptr) {

            if (curso->getProfesorAsignado() == profesor) {

                Horario* horarioEst = estudiante->getHorario();

                if (horarioEst != nullptr) {

                    Curso* cursoMat = horarioEst->buscarCurso(curso->getCodigo());

                    if (cursoMat != nullptr) {

                        ListaPersonas* listaEst = cursoMat->getListaEstudiantes();

                        if (listaEst != nullptr) {

                            Persona* estACambiar = listaEst->buscar(idEst);

                            if (estACambiar != nullptr) {

                                estACambiar->setCalificacionGlobal(nuevaNota);

                                if (estACambiar->getCalificacionGlobal()==nuevaNota) {
                                    resultado = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return resultado;
}

bool Controladora::matricularCurso(UniversidadAlbertoMagno *u,string idEstudiante,string idCurso) {
    if (u == nullptr) return false;

    Persona* estudiante = u->getListaEstudiantes()->buscar(idEstudiante);
    Curso* curso = u->getListaCursos()->buscar(idCurso);

    if (estudiante == nullptr || curso == nullptr) return false;

    if (curso->getCuposAsignados() >= curso->getLimiteCupos())
        return false;

    if (!estudiante->matricularCurso(curso))
        return false;
    curso->setCuposAsignados(curso->getCuposAsignados() + 1);
    return true;
}

bool Controladora::desmatricularCurso(UniversidadAlbertoMagno *u,string idEstudiante,string idCurso) {

    Persona* estudiante = u->getListaEstudiantes()->buscar(idEstudiante);
    Curso* curso = u->getListaCursos()->buscar(idCurso);

    if (estudiante == nullptr || curso == nullptr || curso->getCuposAsignados() == 0) return false;

    if (!estudiante->desmatricularCurso(idCurso))
        return false;

    curso->setCuposAsignados(curso->getCuposAsignados() - 1);
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
    double resultado = 0;
    double suma = 0;
    int cantidadCursos = 0;

    Persona* prof = u->getListaProfesores()->buscar(id);

    if (prof != nullptr) {
        Horario* h = prof->getHorario();

        if (h != nullptr) {
            for (int dia = 0; dia < DIAS; dia++) {
                for (int franja = 0; franja < FRANJA; franja++) {
                    Curso* c = h->getCurso(dia, franja);

                    if (c != nullptr) {
                        suma += c->calcularPromedio();
                        cantidadCursos++;
                    }
                }
            }

            if (cantidadCursos > 0) {
                resultado = suma / cantidadCursos;
            }
        }
    }

    return resultado;
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
