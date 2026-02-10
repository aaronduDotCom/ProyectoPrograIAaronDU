//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_ESTUDIANTE_H
#define PROYECTOPROGRAIAARONDU_ESTUDIANTE_H

#include "Persona.h"
#include "Horario.h"
class Horario;

#include <string>
#include <sstream>
using namespace std;

class Estudiante:public Persona {
private:
    double calificacionGlobal;
    Horario* horario;
public:
    Estudiante();
    Estudiante(string id, string nombre);
    ~Estudiante() override;

    double getCalificacionGlobal() override;
    void setCalificacionGlobal(double calificacionGlobal) override;
    Horario *getHorario() override;

    bool matricularCurso(Curso*curso) override;
    bool desmatricularCurso(string cod) override;
    string toString() override;
};


#endif //PROYECTOPROGRAIAARONDU_ESTUDIANTE_H