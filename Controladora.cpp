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

    Persona* estudiante = new Estudiante(id, nombre);
    u->getListaEstudiantes()->agregarPrimero(estudiante);
    return true;
}

bool Controladora::registrarProfesores(UniversidadAlbertoMagno *u, string nombre, string id) {
    if (u->getListaProfesores()->buscar(id) != nullptr) {
        return false;
    }

    Persona* profesor = new Profesor(id, nombre);
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

bool Controladora::eliminarCurso(UniversidadAlbertoMagno *u, string id) {

    Curso* c = u->getListaCursos()->buscar(id);
    if (c == nullptr) return false;

    NodoPersonas* ne = u->getListaEstudiantes()->getPrimero();
    while (ne != nullptr) {
        Persona* e = ne->getPersona();
        Horario* h = e->getHorario();
        if (h != nullptr) {
            Curso* ch = h->buscarCurso(id);
            if (ch != nullptr) {
                h->eliminarCurso(ch->getDia(), ch->getHora());
            }
        }
        ne = ne->getSig();
    }

    Persona* p = c->getProfesorAsignado();
    if (p != nullptr && p->getHorario() != nullptr) {
        p->getHorario()->eliminarCurso(c->getDia(), c->getHora());
    }

    u->getListaCursos()->eliminar(id);

    return true;
}

bool Controladora::reasignarProfesor(UniversidadAlbertoMagno *u, string idCurso, string idProfesor) {
    bool resultado = false;

    if (u != nullptr) {

        Curso* cursoAux = u->getListaCursos()->buscar(idCurso);
        Persona* nuevoProf = u->getListaProfesores()->buscar(idProfesor);

        if (cursoAux != nullptr && nuevoProf != nullptr) {

            Persona* profeViejo = cursoAux->getProfesorAsignado();

            if (profeViejo != nullptr) {
                profeViejo->desmatricularCurso(idCurso);
            }

            if (nuevoProf->getHorario()->buscarCurso(idCurso) == nullptr) {

                cursoAux->setProfesorAsignado(nuevoProf);
                nuevoProf->matricularCurso(cursoAux);
                resultado = true;
            }
        }
    }
    return resultado;
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

    curso->getListaEstudiantes()->agregarPrimero(estudiante);

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

    return aux->getHorario()->toDisplayString();
}

string Controladora::mostrarHorarioAlumno(UniversidadAlbertoMagno *u, string id) {
    Persona *aux= u->getListaEstudiantes()->buscar(id);
    if (aux==nullptr) return "";

    return aux->getHorario()->toDisplayString();
}

//pruebita montada por gpt
void Controladora::cargarDatosPrueba(UniversidadAlbertoMagno* u) {

    // ===== ESTUDIANTES =====
    for (int i = 1; i <= 6; i++) {
        u->getListaEstudiantes()->agregarPrimero(
            new Estudiante(to_string(i), "Alumno_" + to_string(i))
        );
    }

    // ===== PROFESORES =====
    u->getListaProfesores()->agregarPrimero(new Profesor("1", "Profe_A"));
    u->getListaProfesores()->agregarPrimero(new Profesor("2", "Profe_B"));

    // ===== CURSOS =====
    Curso* c1 = new Curso("A1", "Calculo", 1, 9, nullptr, 3);
    Curso* c2 = new Curso("B2", "Programacion", 3, 11, nullptr, 3);
    Curso* c3 = new Curso("C3", "Fisica", 5, 15, nullptr, 3);

    u->getListaCursos()->agregarPrimero(c1);
    u->getListaCursos()->agregarPrimero(c2);
    u->getListaCursos()->agregarPrimero(c3);

    // ASIGNAR PROFESORES COMO EN LA INTERFAZ
    reasignarProfesor(u, "A1", "2");
    reasignarProfesor(u, "B2", "2");
    reasignarProfesor(u, "C3", "1");


    // ===== MATRICULAS =====
    for (int i = 1; i <= 6; i++) {

        Estudiante* e = (Estudiante*)u->getListaEstudiantes()->buscar(to_string(i));

        if (e != nullptr) {
            e->matricularCurso(c1);
            e->matricularCurso(c2);

            if (i % 2 == 0) {
                e->matricularCurso(c3);
            }

            e->setCalificacionGlobal( 60 );
            e->setCalificacionGlobal( 70 );

            if (i % 2 == 0) {
                e->setCalificacionGlobal(80);
            }
        }
    }
}
