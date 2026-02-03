//
// Created by Oscar on 30/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_NODOPERSONAS_H
#define PROYECTOPROGRAIAARONDU_NODOPERSONAS_H

#include "Persona.h"
class Persona;

class NodoPersonas {
private:
    Persona* persona;
    NodoPersonas* sig;
public:
    NodoPersonas(Persona* persona, NodoPersonas* sig);
    Persona* getPersona();
    NodoPersonas* getSig();
    void setSig(NodoPersonas* sig);
};



#endif //PROYECTOPROGRAIAARONDU_NODOPERSONAS_H