//
// Created by Oscar on 30/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_NODOPERSONAS_H
#define PROYECTOPROGRAIAARONDU_NODOPERSONAS_H

#include "Persona.h"

class NodoPersonas {
private:
    NodoPersonas *sig;
    Persona* persona;
public:
    NodoPersonas();
    NodoPersonas(NodoPersonas *sig,Persona *persona);
    ~NodoPersonas();
    NodoPersonas *getSig();
    void setSig(NodoPersonas *sig);
    Persona *getPersona();
    void setPersona(Persona *persona);
};


#endif //PROYECTOPROGRAIAARONDU_NODOPERSONAS_H