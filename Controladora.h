//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_CONTROLADORA_H
#define PROYECTOPROGRAIAARONDU_CONTROLADORA_H

class UniversidadAlbertoMagno;

class Controladora {
public:
    Controladora()=default;
    ~Controladora()=default;

    //Registros
    bool registrarEstudiante(UniversidadAlbertoMagno*u,string nombre,int id);
    bool registrarProfesores(UniversidadAlbertoMagno*u,string nombre,int id);
    bool registrarCursos(UniversidadAlbertoMagno*u,int id,string nombre,int dia, int hora,int idProfesor,int limiteCupos);

    //eliminacion
    bool expulsarEstudiante(UniversidadAlbertoMagno*u,int id);
    bool despedirProfesor(UniversidadAlbertoMagno*u,int id);
    bool eliminarCurso(UniversidadAlbertoMagno*u, int id);

    //Nuevo profe pal curso
    bool reasignarProfesor(UniversidadAlbertoMagno*u,int idCurso,int idProfesor);

    //poner y quitar cursos a los estudiantes
    bool matricularCurso(UniversidadAlbertoMagno*u,int idEstudiante, int idCursos);
    bool desmatricularCurso(UniversidadAlbertoMagno*u,int idEstudiante, int idCursos);

    //mostrar individual
    string mostrarEstudiante(UniversidadAlbertoMagno*u,int id);
    string mostrarProfesor(UniversidadAlbertoMagno*u,int id);
    string mostrarCurso(UniversidadAlbertoMagno*u,int id);

    //mostrar individual en un curso especifico
    string mostrarEstudiantePorCurso(UniversidadAlbertoMagno*u,int idCurso,int idEstudiante);

    //mostrar individual en un curso especifico (profe)
    string mostrarProfesorAsignado(UniversidadAlbertoMagno*u,int id);

    //mostrar todo
    string mostrarTodosLosEstudiantes(UniversidadAlbertoMagno*u);
    string mostrarTodosLosProfesores(UniversidadAlbertoMagno*u);
    string mostrarTodosLosCursos(UniversidadAlbertoMagno*u);

    //mostrar promedios
    double mostrarPromedioPorEstudiante(UniversidadAlbertoMagno*u,int id);
    double mostrarPromedioPorProfesor(UniversidadAlbertoMagno*u,int id);
    double mostrarPromedioPorCurso(UniversidadAlbertoMagno*u,int id);

    //mostrar horarios
    string mostrarHorarioProfesor(UniversidadAlbertoMagno*u,int id);
    string mostrarHorarioAlumno(UniversidadAlbertoMagno*u,int id);
};

#endif //PROYECTOPROGRAIAARONDU_CONTROLADORA_H