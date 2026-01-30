//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_CURSO_H
#define PROYECTOPROGRAIAARONDU_CURSO_H

#include "Profesor.h"
#include "ListaEstudiantes.h"
class ListaEstudiantes;
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
    Profesor *profesorAsignado;
    ListaEstudiantes *listaEstudiantes;
    int cantidadEstudiantes;
    int limiteCupos;
public:
    Curso(int codigo, string nombre, int dia, int hora, Profesor *profesor, int limiteCupos);
    ~Curso();

    Profesor* getProfesorAsignado();
    ListaEstudiantes* getListaEstudiantes();

    bool agregarEstudiante(Estudiante* estudiante);
    bool eliminarEstudiante(Estudiante* estudiante);

    int getCodigo();
    string getNombre();
    int getDia();
    int getHora();

    void setProfesorAsignado(Profesor *profesor);

    string toString();
};


#endif //PROYECTOPROGRAIAARONDU_CURSO_H