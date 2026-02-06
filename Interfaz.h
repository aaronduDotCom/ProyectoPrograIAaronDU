//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_INTERFAZ_H
#define PROYECTOPROGRAIAARONDU_INTERFAZ_H

#include <iostream>

#include "UniversidadAlbertoMagno.h"

class Controladora;

class Interfaz {
private:
    UniversidadAlbertoMagno *ualma;
public:
    Interfaz();
    ~Interfaz();
    bool leerInt(int& x);
    void ejecutarInterfaz(Controladora *c);
};


#endif //PROYECTOPROGRAIAARONDU_INTERFAZ_H