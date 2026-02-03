//
// Created by Oscar on 30/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_LISTAPERSONAS_H
#define PROYECTOPROGRAIAARONDU_LISTAPERSONAS_H

#include "NodoPersonas.h"
#include <sstream>
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
    void agregarPrimero(Persona*estudiante);
    bool eliminarPrimero();
    bool eliminarUltimo();
    bool eliminar(int id);
    Persona *buscar(int id);

    string toString();
};


#endif //PROYECTOPROGRAIAARONDU_LISTAPERSONAS_H