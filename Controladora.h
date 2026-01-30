//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_CONTROLADORA_H
#define PROYECTOPROGRAIAARONDU_CONTROLADORA_H

#include "UniversidadAlbertoMagno.h"

class Controladora {
public:
    Controladora()=default;
    ~Controladora()=default;

    bool registrarEstudiante(UniversidadAlbertoMagno*u,string nombre,int id);
    bool registrarProfesores(UniversidadAlbertoMagno*u,string nombre,int id);
    bool registrarCursos(UniversidadAlbertoMagno*u,int id,string nombre,int dia, int hora, Profesor*profesor,int limiteCupos);

    bool expulsarEstudiante(UniversidadAlbertoMagno*u,int id);
    bool despedirProfesor(UniversidadAlbertoMagno*u,int id);
    bool eliminarCurso(UniversidadAlbertoMagno*u);

    bool reasignarProfesor(UniversidadAlbertoMagno*u,int idCurso,int idProfesor);

    string mostrarEstudiante(UniversidadAlbertoMagno*u,int id);
    string mostrarProfesor(UniversidadAlbertoMagno*u,int id);
    string mostrarCurso(UniversidadAlbertoMagno*u,int id);

    string mostrarEstudiantesPorProfesor(UniversidadAlbertoMagno*u,int id);
    string mostrarEstudiantePorCurso(UniversidadAlbertoMagno*u,int id);

    string mostrarProfesorAsignado(UniversidadAlbertoMagno*u,int id);

    string mostrarTodosLosEstudiantes(UniversidadAlbertoMagno*u);
    string mostrarTodosLosProfesores(UniversidadAlbertoMagno*u);
    string mostrarTodosLosCursos(UniversidadAlbertoMagno*u);

    string mostrarPromedioPorEstudiant(UniversidadAlbertoMagno*u,int id);
    string mostrarPromedioPorProfesor(UniversidadAlbertoMagno*u,int id);
    string mostrarPromedioPorCurso(UniversidadAlbertoMagno*u,int id);

    string mostrarHorarioProfesor(UniversidadAlbertoMagno*u,int id);
    string mostrarHorarioAlumno(UniversidadAlbertoMagno*u,int id);
};


#endif //PROYECTOPROGRAIAARONDU_CONTROLADORA_H