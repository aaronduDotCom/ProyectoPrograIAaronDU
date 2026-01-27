//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_HORARIO_H
#define PROYECTOPROGRAIAARONDU_HORARIO_H

#include "Curso.h"

#include <string>
#include <sstream>
using namespace std;

const int DIAS=7;
const int FRANJA=11;//8am-9pm

class Horario {
private:
    Curso*** m;
public:
    Horario();
    ~Horario();

    bool vacia();
    Curso *buscarCurso(int codigo);
    bool matricularCurso(Curso*otrCcurso);
    bool desmatricularCurso(int dia,int franja);

    string toString();
};

#endif //PROYECTOPROGRAIAARONDU_HORARIO_H
