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

    void setCurso(Curso *curso);

    bool vacia();
    bool franjaVacia(int franja);
    Curso *buscarCurso(int codigo);

    string toString();
};

#endif //PROYECTOPROGRAIAARONDU_HORARIO_H
