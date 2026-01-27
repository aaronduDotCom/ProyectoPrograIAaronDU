//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_ESTUDIANTE_H
#define PROYECTOPROGRAIAARONDU_ESTUDIANTE_H

#include "Persona.h"
#include "Horario.h"

#include <string>
#include <sstream>
using namespace std;

class Estudiante:public Persona {
private:
    double calificacionGlobal();
    Horario* horario;
public:
    Estudiante();
    Estudiante(string nombre, int id);
    ~Estudiante();
    string toString();
};


#endif //PROYECTOPROGRAIAARONDU_ESTUDIANTE_H