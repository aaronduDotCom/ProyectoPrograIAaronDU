//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_PERSONA_H
#define PROYECTOPROGRAIAARONDU_PERSONA_H

#include "Horario.h"
class Horario;

#include <string>
#include <sstream>
using namespace std;

class Persona {
protected:
    string nombreCompleto; //Ej: "Carlos Andres Morales Torres"
    int identificacion; //5 digitos
public:
    Persona();
    Persona(string nombre, int identificacion);
    virtual ~Persona();

    string getNombre();
    void setNombre(string nombre);
    int getId();
    void setId(int id);

    virtual double getCalificacionGlobal() = 0;
    virtual void setCalificacionGlobal(double) = 0;
    virtual Horario* getHorario() = 0;

    virtual bool matricularCurso(Curso*curso) = 0;
    virtual bool desmatricularCurso(int cod) = 0;

    virtual string toString();
};


#endif //PROYECTOPROGRAIAARONDU_PERSONA_H