//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_LISTAPROFESORES_H
#define PROYECTOPROGRAIAARONDU_LISTAPROFESORES_H

#include "NodoProfesores.h"

class ListaProfesores {
private:
    NodoProfesores *primero;
    NodoProfesores *actual;
public:
    ListaProfesores();
    ~ListaProfesores();

    bool vacia();
    void agregarPrimero(Profesor *profesor);
    bool eliminarPrimero();
    bool eliminarUltimo();
    bool eliminar(int id);
    Estudiante *buscar(int id);
};


#endif //PROYECTOPROGRAIAARONDU_LISTAPROFESORES_H