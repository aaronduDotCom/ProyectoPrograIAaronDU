//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_UNIVERSIDADALBERTOMAGNO_H
#define PROYECTOPROGRAIAARONDU_UNIVERSIDADALBERTOMAGNO_H

#include "ListaPersonas.h"
#include "ListaCursos.h"

class UniversidadAlbertoMagno {
private:
    ListaPersonas *listaEstudiantes;
    ListaPersonas *listaProfesores;
    ListaCursos *listaCursos;
public:
    UniversidadAlbertoMagno();
    ~UniversidadAlbertoMagno();

    ListaPersonas *getListaEstudiantes();
    ListaPersonas *getListaProfesores();
    ListaCursos *getListaCursos();

    void eliminarEstudiantes();
    void eliminarProfesores();
    void eliminarCursos();
};


#endif //PROYECTOPROGRAIAARONDU_UNIVERSIDADALBERTOMAGNO_H