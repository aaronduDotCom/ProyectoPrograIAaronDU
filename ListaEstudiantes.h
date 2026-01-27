//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_LISTAESTUDIANTES_H
#define PROYECTOPROGRAIAARONDU_LISTAESTUDIANTES_H

#include "NodoEstudiantes.h"

class ListaEstudiantes {
private:
    NodoEstudiantes *primero;
    NodoEstudiantes *actual;
public:
    ListaEstudiantes();
    ~ListaEstudiantes();

    bool vacia();
    void agregarPrimero(Estudiante*estudiante);
    bool eliminarPrimero();
    bool eliminarUltimo();
    bool eliminar(int id);
    Estudiante *buscar(int id);
};


#endif //PROYECTOPROGRAIAARONDU_LISTAESTUDIANTES_H