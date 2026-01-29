//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_UNIVERSIDADALBERTOMAGNO_H
#define PROYECTOPROGRAIAARONDU_UNIVERSIDADALBERTOMAGNO_H

#include "ListaEstudiantes.h"
#include "ListaProfesores.h"
#include "ListaCursos.h"

class UniversidadAlbertoMagno {
private:
    ListaEstudiantes *listaEstudiantes;
    ListaProfesores *listaProfesores;
    ListaCursos *listaCursos;
public:
    UniversidadAlbertoMagno();
    ~UniversidadAlbertoMagno();

    ListaEstudiantes *getListaEstudiantes();
    ListaProfesores *getListaProfesores();
    ListaCursos *getListaCursos();
};


#endif //PROYECTOPROGRAIAARONDU_UNIVERSIDADALBERTOMAGNO_H