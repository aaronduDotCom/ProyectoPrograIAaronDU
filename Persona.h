//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_PERSONA_H
#define PROYECTOPROGRAIAARONDU_PERSONA_H

#include "Horario.h"

class Horario;
class Curso;

#include <string>
#include <sstream>
using namespace std;

class Persona {
protected:
    string nombreCompleto; //Ej: "Carlos Andres Morales Torres"
    string identificacion; //5 digitos
public:
    Persona();
    Persona(string nombre, string identificacion);
    virtual ~Persona()=default;

    string getNombre();
    void setNombre(string nombre);
    string getId();
    void setId(string id);

    virtual double getCalificacionGlobal() = 0;
    virtual void setCalificacionGlobal(double) = 0;
    virtual Horario* getHorario() = 0;

    virtual bool matricularCurso(Curso*curso) = 0;
    virtual bool desmatricularCurso(string cod) = 0;

    virtual string toString();
};


#endif //PROYECTOPROGRAIAARONDU_PERSONA_H