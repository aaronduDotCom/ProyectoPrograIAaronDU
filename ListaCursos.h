//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_LISTACURSOS_H
#define PROYECTOPROGRAIAARONDU_LISTACURSOS_H

#include "NodoCursos.h"

class ListaCursos {
private:
    NodoCursos *primero;
    NodoCursos *actual;
public:
    ListaCursos();
    ~ListaCursos();

    NodoCursos *getPrimero();

    bool vacia();
    void agregarPrimero(Curso*curso);
    bool eliminarPrimero();
    bool eliminarUltimo();
    bool eliminar(string id);
    Curso *buscar(string id);

    string toString();
};


#endif //PROYECTOPROGRAIAARONDU_LISTACURSOS_H