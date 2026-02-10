//
// Created by Oscar on 27/1/2026.
//

#include "ListaCursos.h"

#include "Profesor.h"
#include "ListaPersonas.h"

ListaCursos::ListaCursos() {
    primero=nullptr;
    actual=nullptr;
}

ListaCursos::~ListaCursos() {
    while (!vacia()) {
        eliminarPrimero();
    }
}

NodoCursos * ListaCursos::getPrimero() {return primero;}

bool ListaCursos::vacia() {
    return primero==nullptr;
}

bool ListaCursos::agregarPrimero(Curso *curso) {
    if (buscar(curso->getCodigo()) != nullptr) {
        return false;

    }else {
        primero = new NodoCursos(primero, curso);
        return true;
    }
}

bool ListaCursos::eliminarPrimero() {
    if (vacia()) {return false;}

    actual=primero;
    primero=primero->getSig();
    delete actual;
    actual=nullptr;

    return true;

}

bool ListaCursos::eliminarUltimo() {
    if (vacia()) {return false;}

    if (primero->getSig()==nullptr) {
        delete primero;
        primero = nullptr;
        return true;
    }

    actual=primero;
    NodoCursos *anterior=nullptr;

    while (actual->getSig()!=nullptr) {

        anterior=actual;
        actual=actual->getSig();
    }
    if (anterior!=nullptr) {
        anterior->setSig(nullptr);
        delete actual;
        return true;
    }

    return false;
}

bool ListaCursos::eliminar(string id) {
    if (vacia()) return false;

    if (primero->getCurso()->getCodigo()==id) {
        eliminarPrimero();
        return true;
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {

        NodoCursos *anterior=actual;
        actual=actual->getSig();

        if (actual->getCurso()->getCodigo()==id) {

            anterior->setSig(actual->getSig());
            delete actual;

            return true;
        }
    }
    return false;
}

Curso * ListaCursos::buscar(string id) {
    if (vacia()) return nullptr;

    actual=primero;
    while (actual!=nullptr) {
        if (actual->getCurso()->getCodigo()==id) {
            return actual->getCurso();
        }
        actual=actual->getSig();
    }

    return nullptr;
}

string ListaCursos::toString() {
    stringstream resultado;
    actual = primero;

    while (actual != nullptr) {
        resultado << actual->getCurso()->toString() << "\n";
        actual = actual->getSig();
    }

    return resultado.str();
}

void ListaCursos::guardarDatos(FILE *fileName) {
    if (fileName) {
        actual=primero;
        while (actual!=nullptr) {
            fprintf(fileName,"%s", actual->getCurso()->toString().c_str());

            actual=actual->getSig();
        }
    }
}

void ListaCursos::cargarDatos(FILE* fileName, ListaPersonas* listaProfesores) {
    if (fileName && listaProfesores) {
        char buffer[256];

        while (fgets(buffer, sizeof(buffer), fileName)) {
            string linea(buffer);

            if (!linea.empty() && linea.back() == '\n') {
                linea.pop_back();
            }

            stringstream ss(linea);
            string codigo, nombre, diaStr, horaStr, cuposStr, idProfesor;

            getline(ss, codigo, ';');
            getline(ss, nombre, ';');
            getline(ss, diaStr, ';');
            getline(ss, horaStr, ';');
            getline(ss, cuposStr, ';');
            getline(ss, idProfesor);

            Persona* profe = listaProfesores->buscar(idProfesor);

            if (profe != nullptr) {
                int dia = stoi(diaStr);
                int hora = stoi(horaStr);
                int limiteCupos = stoi(cuposStr);

                Curso* c = new Curso(codigo, nombre, dia, hora, profe, limiteCupos);
                c->setProfesorAsignado(profe);

                agregarPrimero(c);
            }
        }
    }
}
