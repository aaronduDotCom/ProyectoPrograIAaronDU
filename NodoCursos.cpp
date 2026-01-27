//
// Created by Oscar on 27/1/2026.
//

#include "NodoCursos.h"

NodoCursos::NodoCursos() {
    sig=nullptr;
    curso=nullptr;
}

NodoCursos::NodoCursos(NodoCursos *sig, Curso *curso) {
    this->sig=sig;
    this->curso=curso;
}

NodoCursos::~NodoCursos() {
}

NodoCursos * NodoCursos::getSig() {return sig;}

void NodoCursos::setSig(NodoCursos *sig) {this->sig=sig;}

Curso * NodoCursos::getCurso() {return curso;}

void NodoCursos::setCurso(Curso *curso) {this->curso=curso;}
