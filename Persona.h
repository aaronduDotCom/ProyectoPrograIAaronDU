//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_PERSONA_H
#define PROYECTOPROGRAIAARONDU_PERSONA_H

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

    virtual void setCalificacionGlobal(double) = 0;

    virtual string toString();
};


#endif //PROYECTOPROGRAIAARONDU_PERSONA_H