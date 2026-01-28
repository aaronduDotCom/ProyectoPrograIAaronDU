//
// Created by Oscar on 27/1/2026.
//

#include "ListaEstudiantes.h"

ListaEstudiantes::ListaEstudiantes() {
    primero=nullptr;
    actual=nullptr;
}

ListaEstudiantes::~ListaEstudiantes() {
    while (!vacia()) {
        eliminarPrimero();
    }
}

bool ListaEstudiantes::vacia() {
    return primero==nullptr;
}

void ListaEstudiantes::agregarPrimero(Estudiante *estudiante) {
    if (vacia()) {
        primero=new NodoEstudiantes(nullptr, estudiante);

    }else if (buscar(estudiante->getId())==nullptr) {
        actual=primero;
        actual->setSig(new NodoEstudiantes(primero, estudiante));
        primero=actual;
    }
}

bool ListaEstudiantes::eliminarPrimero() {
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

bool ListaEstudiantes::eliminarUltimo() {
    if (vacia()) {return false;}

    if (primero->getSig()==nullptr) {
        delete primero;
        return true;
    }

    actual=primero;
    NodoEstudiantes *anterior=nullptr;

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

bool ListaEstudiantes::eliminar(int id) {
    if (vacia()) return false;

    if (primero->getEstudiante()->getId()==id) {
        eliminarPrimero();
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {

        NodoEstudiantes *anterior=actual;
        actual=actual->getSig();

        if (actual->getEstudiante()->getId()==id) {

            anterior->setSig(actual->getSig());
            delete actual;

            return true;
        }
    }
    return false;
}

Estudiante * ListaEstudiantes::buscar(int id) {
    if (primero->getEstudiante()->getId()==id) {
        return primero->getEstudiante();
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {
        if (actual->getEstudiante()->getId()==id) {
            return actual->getEstudiante();
        }
        actual=actual->getSig();
    }

    return nullptr;
}
