//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_CURSO_H
#define PROYECTOPROGRAIAARONDU_CURSO_H

#include "Persona.h"
#include "ListaPersonas.h"
#include "NodoPersonas.h"

class ListaPersonas;
class Persona;

#include <string>
#include <sstream>
using namespace std;

class Curso {
private:
    string codigo;
    string nombre;
    int dia; //1-7 domingo a lunes
    int hora; //8am-7pm
    Persona *profesorAsignado;
    ListaPersonas *listaEstudiantes;
    int limiteCupos;
    int cuposAsignados;
public:
    Curso(string codigo, string nombre, int dia, int hora, Persona *profesor, int limiteCupos);
    ~Curso()=default;

    Persona* getProfesorAsignado();
    ListaPersonas* getListaEstudiantes();
    string getCodigo();
    string getNombre();
    int getDia();
    int getHora();
    int getLimiteCupos();
    int getCuposAsignados();

    void setCuposAsignados(int cuposAsignados);
    void setProfesorAsignado(Persona *profesor);

    string toString();
    string toDisplayString();

    double calcularPromedio();
};


#endif //PROYECTOPROGRAIAARONDU_CURSO_H