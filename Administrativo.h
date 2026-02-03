//
// Created by Oscar on 2/2/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_ADMINISTRATIVO_H
#define PROYECTOPROGRAIAARONDU_ADMINISTRATIVO_H

#include "Persona.h"

//Clase correspondiente al segundo punto de los Bonus:
//● Agregar un nuevo tipo de Persona sin modificar código existente (+5 pts).

class Administrativo: public Persona {
public:
    Administrativo();
    ~Administrativo() override;
};


#endif //PROYECTOPROGRAIAARONDU_ADMINISTRATIVO_H