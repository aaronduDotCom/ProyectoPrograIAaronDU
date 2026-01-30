//
// Created by Oscar on 30/1/2026.
//

#include "ListaPersonas.h"

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

void ListaPersonas::agregarPrimero(Persona *estudiante) {
    if (vacia()) {
        primero=new NodoPersonas(nullptr, estudiante);

    }else if (buscar(estudiante->getId())==nullptr) {
        actual=primero;
        actual->setSig(new NodoPersonas(primero, estudiante));
        primero=actual;
    }
}

bool ListaPersonas::eliminarPrimero() {
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

bool ListaPersonas::eliminarUltimo() {
    if (vacia()) {return false;}

    if (primero->getSig()==nullptr) {
        delete primero;
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

bool ListaPersonas::eliminar(int id) {
    if (vacia()) return false;

    if (primero->getPersona()->getId()==id) {
        eliminarPrimero();
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

Persona * ListaPersonas::buscar(int id) {
    if (primero->getPersona()->getId()==id) {
        return primero->getPersona();
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {
        if (actual->getPersona()->getId()==id) {
            return actual->getPersona();
        }
        actual=actual->getSig();
    }

    return nullptr;
}
