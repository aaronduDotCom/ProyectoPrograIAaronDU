//
// Created by Oscar on 30/1/2026.
//

#include "ListaPersonas.h"

#include "Estudiante.h"
#include "Profesor.h"

ListaPersonas::ListaPersonas() {
    primero=nullptr;
    actual=nullptr;
}

ListaPersonas::~ListaPersonas() {
    while (!vacia()) {
        eliminarPrimero();
    }
}

NodoPersonas * ListaPersonas::getPrimero() {return primero;}

bool ListaPersonas::vacia() {
    return primero==nullptr;
}

bool ListaPersonas::agregarPrimero(Persona *estudiante) {
    if (buscar(estudiante->getId()) != nullptr) {
        return false;

    }else {
        primero = new NodoPersonas(estudiante, primero);
        return true;
    }
}

bool ListaPersonas::eliminarPrimero() {
    if (vacia()) {return false;}

    actual=primero;
    primero=primero->getSig();
    delete actual;
    actual=nullptr;

    return true;
}

bool ListaPersonas::eliminarUltimo() {
    if (vacia()) {return false;}

    if (primero->getSig()==nullptr) {
        delete primero;
        primero=nullptr;
        return true;
    }

    actual=primero;
    NodoPersonas *anterior=nullptr;

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

bool ListaPersonas::eliminar(string id) {
    if (vacia()) return false;

    if (primero->getPersona()->getId()==id) {
        eliminarPrimero();
        return true;
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {

        NodoPersonas *anterior=actual;
        actual=actual->getSig();

        if (actual->getPersona()->getId()==id) {

            anterior->setSig(actual->getSig());
            delete actual;

            return true;
        }
    }
    return false;
}

Persona* ListaPersonas::buscar(string id) {
    if (vacia()) return nullptr;

    actual = primero;
    while (actual != nullptr) {
        if (actual->getPersona()->getId() == id) {
            return actual->getPersona();
        }
        actual = actual->getSig();
    }

    return nullptr;
}

string ListaPersonas::toString() {
    stringstream resultado;

    actual = primero;
    while (actual!= nullptr) {
        resultado << actual->getPersona()->toString() << "\n";
        actual = actual->getSig();
    }

    return resultado.str();
}

void ListaPersonas::guardarDatos(FILE *fileName) {
    if (fileName) {
        actual=primero;
        while (actual!=nullptr) {
            fprintf(fileName,"%s", actual->getPersona()->toString().c_str());

            actual=actual->getSig();
        }
    }
}

//Para estos si me ayude de chat
void ListaPersonas::cargarDatosEst(FILE *fileName) {
    if (fileName) {
        char buffer[256];

        while (fgets(buffer, sizeof(buffer), fileName)) {
            string linea(buffer);

            if (!linea.empty() && linea.back() == '\n') {
                linea.pop_back();
            }

            stringstream ss(linea);
            string id, nombre;

            getline(ss, id, ';');
            getline(ss, nombre);

            Persona* p = new Estudiante(id,nombre);
            agregarPrimero(p);
        }
    }
}

void ListaPersonas::cargarDatosProf(FILE *fileName) {
    if (fileName) {
        char buffer[256];

        while (fgets(buffer, sizeof(buffer), fileName)) {
            string linea(buffer);

            if (!linea.empty() && linea.back() == '\n') {
                linea.pop_back();
            }

            stringstream ss(linea);
            string id, nombre;

            getline(ss, id, ';');
            getline(ss, nombre);

            Persona* p = new Profesor(id,nombre);
            agregarPrimero(p);
        }
    }
}
