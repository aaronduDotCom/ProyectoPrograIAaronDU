//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_CURSO_H
#define PROYECTOPROGRAIAARONDU_CURSO_H

#include "Profesor.h"
#include "ListaPersonas.h"
class ListaPersonas;
class Estudiante;
class Profesor;

#include <string>
#include <sstream>
using namespace std;

class Curso {
private:
    int codigo;
    string nombre;
    int dia; //1-7 domingo a lunes
    int hora; //8am-7pm
    Persona *profesorAsignado;
    ListaPersonas *listaEstudiantes;
    int cantidadEstudiantes;
    int limiteCupos;
public:
    Curso(int codigo, string nombre, int dia, int hora, Persona *profesor, int limiteCupos);
    ~Curso();

    Persona* getProfesorAsignado();
    ListaPersonas* getListaEstudiantes();

    bool agregarEstudiante(Persona* estudiante);
    bool eliminarEstudiante(Persona* estudiante);

    int getCodigo();
    string getNombre();
    int getDia();
    int getHora();

    void setProfesorAsignado(Profesor *profesor);

    string toString();
};


#endif //PROYECTOPROGRAIAARONDU_CURSO_H