//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_NODOPROFESORES_H
#define PROYECTOPROGRAIAARONDU_NODOPROFESORES_H

#include "Profesor.h"

class NodoProfesores {
    NodoProfesores *sig;
    Profesor* profesor;
public:
    NodoProfesores();
    NodoProfesores(NodoProfesores *sig, Profesor *profesor);
    ~NodoProfesores();
    NodoProfesores *getSig();
    void setSig(NodoProfesores *sig);
    Profesor *getProfesor();
    void setProfesor(Profesor *profesor);
};

#endif //PROYECTOPROGRAIAARONDU_NODOPROFESORES_H