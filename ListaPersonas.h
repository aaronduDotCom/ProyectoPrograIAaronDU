//
// Created by Oscar on 30/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_LISTAPERSONAS_H
#define PROYECTOPROGRAIAARONDU_LISTAPERSONAS_H

#include "NodoPersonas.h"
#include <cstdio>
#include <string>

using namespace std;

class NodoPersonas;
class Persona;

class ListaPersonas {
private:
    NodoPersonas *primero;
    NodoPersonas *actual;
public:
    ListaPersonas();
    ~ListaPersonas();

    NodoPersonas *getPrimero();

    bool vacia();
    bool agregarPrimero(Persona*estudiante);
    bool eliminarPrimero();
    bool eliminarUltimo();
    bool eliminar(string id);
    Persona *buscar(string id);

    string toString();

    void guardarDatos(FILE *fileName);
    void cargarDatos(FILE *fileName);
};


#endif //PROYECTOPROGRAIAARONDU_LISTAPERSONAS_H