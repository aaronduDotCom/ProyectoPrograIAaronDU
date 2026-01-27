//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_NODOCURSOS_H
#define PROYECTOPROGRAIAARONDU_NODOCURSOS_H

#include "Curso.h"

class NodoCursos {
    NodoCursos *sig;
    Curso* curso;
public:
    NodoCursos();
    NodoCursos(NodoCursos *sig, Curso *curso);
    ~NodoCursos();
    NodoCursos *getSig();
    void setSig(NodoCursos *sig);
    Curso *getCurso();
    void setCurso(Curso *curso);
};


#endif //PROYECTOPROGRAIAARONDU_NODOCURSOS_H