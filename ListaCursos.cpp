//
// Created by Oscar on 27/1/2026.
//

#include "ListaCursos.h"

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

void ListaCursos::agregarPrimero(Curso *curso) {
    if (vacia()) {
        primero=new NodoCursos(nullptr, curso);

    }else if (buscar(curso->getCodigo())==nullptr) {
        actual=primero;
        actual->setSig(new NodoCursos(primero, curso));
        primero=actual;
    }
}

bool ListaCursos::eliminarPrimero() {
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

bool ListaCursos::eliminarUltimo() {
    if (vacia()) {return false;}

    if (primero->getSig()==nullptr) {
        delete primero;
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

bool ListaCursos::eliminar(int id) {
    if (vacia()) return false;

    if (primero->getCurso()->getCodigo()==id) {
        eliminarPrimero();
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

Curso * ListaCursos::buscar(int id) {
    if (primero->getCurso()->getCodigo()==id) {
        return primero->getCurso();
    }

    actual=primero;
    while (actual->getSig()!=nullptr) {
        if (actual->getCurso()->getCodigo()==id) {
            return actual->getCurso();
        }
        actual=actual->getSig();
    }

    return nullptr;
}
