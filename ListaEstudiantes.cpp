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
    if (primero==nullptr) return true;
    return false;
}

void ListaEstudiantes::agregarPrimero(Estudiante *estudiante) {
    if (vacia()) {
        primero=new NodoEstudiantes(nullptr, estudiante);
    }else if (buscar(estudiante->getId())!=nullptr) {

    }else{
        actual=primero;
        primero=new NodoEstudiantes(primero, estudiante);
        actual->setSig(primero);
    }
}

bool ListaEstudiantes::eliminarPrimero() {
    if (vacia()) {return false;}


}

bool ListaEstudiantes::eliminarUltimo() {
}

bool ListaEstudiantes::eliminar(int id) {
    if (primero->getEstudiante()->getId()==id) {
        eliminarPrimero();
    }
}

Estudiante * ListaEstudiantes::buscar(int id) {
    while (!vacia()) {}
}
