//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_PROFESOR_H
#define PROYECTOPROGRAIAARONDU_PROFESOR_H

#include "Persona.h"
#include "Horario.h"
class Horario;

#include <string>
#include <sstream>
using namespace std;

class Profesor:public Persona {
private:
    Horario *horario;
public:
    Profesor();
    Profesor(string identificacion, string nombreCompleto);
    ~Profesor() override;

    double getCalificacionGlobal() override;
    void setCalificacionGlobal(double) override;
    Horario *getHorario() override;

    bool matricularCurso(Curso*curso) override;
    bool desmatricularCurso(string cod) override;

    bool asignarCurso(string cod);
    bool desasignarCurso(string cod);

    string toString() override;

    double calcularPromedio();
};


#endif //PROYECTOPROGRAIAARONDU_PROFESOR_H