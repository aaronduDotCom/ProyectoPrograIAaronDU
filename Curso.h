//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_CURSO_H
#define PROYECTOPROGRAIAARONDU_CURSO_H

#include "Profesor.h"
#include "ListaEstudiantes.h"

#include <string>
#include <sstream>
using namespace std;

class Curso {
private:
    int codigo;
    string nombre;
    int dia; //1-7 domingo a lunes
    int hora; //8am-7pm
    Profesor *profesorAsignado;
    ListaEstudiantes *listaEstudiantes;
    int limiteCupos;
public:
    Curso(int codigo, string nombre, int dia, int hora, Profesor profesor, int limiteCupos);
    ~Curso();
    bool agregarEstudiante();
    bool eliminarEstudiante();

    int getCodigo();
    string getNombre();
    int getDia();
    int getHora();

    string toString();
};


#endif //PROYECTOPROGRAIAARONDU_CURSO_H