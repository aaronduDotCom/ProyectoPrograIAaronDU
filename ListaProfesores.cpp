//
// Created by Oscar on 27/1/2026.
//

#include "ListaProfesores.h"

ListaProfesores::ListaProfesores() {
    primero=nullptr;
    actual=nullptr;
}

ListaProfesores::~ListaProfesores() {
    while (!vacia()) {
        eliminarPrimero();
    }
}

NodoProfesores * ListaProfesores::getPrimero() {return primero;}

bool ListaProfesores::vacia() {
    return primero==nullptr;
}

void ListaProfesores::agregarPrimero(Profesor *profesor) {
    if (vacia()) {
        primero=new NodoProfesores(nullptr, profesor);

    }else if (buscar(profesor->getId())==nullptr) {
        actual=primero;
        actual->setSig(new NodoProfesores(primero, profesor));
        primero=actual;
    }
}

bool ListaProfesores::eliminarPrimero() {
    if (vacia()) {return false;}

    if (primero->getSig()==nullptr) {
        delete primero;
        primero=nullptr;

        return true;
    }

    actual=primero;
    primero=primero->getSig();
    delete actual;
    actual=nullptr;

    return true;

}

bool ListaProfesores::eliminarUltimo() {
    if (vacia()) {return false;}

    if (primero->getSig()==nullptr) {
        delete primero;
        return true;
    }

    actual=primero;
    NodoProfesores *anterior=nullptr;

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

bool ListaProfesores::eliminar(int id) {
    if (vacia()) return false;

    if (primero->getProfesor()->getId()==id) {
        eliminarPrimero();
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {

        NodoProfesores *anterior=actual;
        actual=actual->getSig();

        if (actual->getProfesor()->getId()==id) {

            anterior->setSig(actual->getSig());
            delete actual;

            return true;
        }
    }
    return false;
}

Profesor * ListaProfesores::buscar(int id) {
    if (primero->getProfesor()->getId()==id) {
        return primero->getProfesor();
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {
        if (actual->getProfesor()->getId()==id) {
            return actual->getProfesor();
        }
        actual=actual->getSig();
    }

    return nullptr;
}
