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
    bool registrarEstudiante(UniversidadAlbertoMagno*u,string nombre,string id);
    bool registrarProfesores(UniversidadAlbertoMagno*u,string nombre,string id);
    bool registrarCursos(UniversidadAlbertoMagno*u,string id,string nombre,int dia, int hora,string idProfesor,int limiteCupos);

    //eliminacion
    bool expulsarEstudiante(UniversidadAlbertoMagno*u,string id);
    bool despedirProfesor(UniversidadAlbertoMagno*u,string id);
    bool eliminarCurso(UniversidadAlbertoMagno*u, string id);

    //Nuevo profe pal curso
    bool reasignarProfesor(UniversidadAlbertoMagno*u,string idCurso,string idProfesor);

    //poner y quitar cursos a los estudiantes
    bool matricularCurso(UniversidadAlbertoMagno*u,string idEstudiante, string idCursos);
    bool desmatricularCurso(UniversidadAlbertoMagno*u,string idEstudiante, string idCursos);

    //mostrar individual
    string mostrarEstudiante(UniversidadAlbertoMagno*u,string id);
    string mostrarProfesor(UniversidadAlbertoMagno*u,string id);
    string mostrarCurso(UniversidadAlbertoMagno*u,string id);

    //mostrar individual en un curso especifico
    string mostrarEstudiantePorCurso(UniversidadAlbertoMagno*u,string idCurso,string idEstudiante);

    //mostrar individual en un curso especifico (profe)
    string mostrarProfesorAsignado(UniversidadAlbertoMagno*u,string id);

    //mostrar todo
    string mostrarTodosLosEstudiantes(UniversidadAlbertoMagno*u);
    string mostrarTodosLosProfesores(UniversidadAlbertoMagno*u);
    string mostrarTodosLosCursos(UniversidadAlbertoMagno*u);

    //mostrar promedios
    double mostrarPromedioPorEstudiante(UniversidadAlbertoMagno*u,string id);
    double mostrarPromedioPorProfesor(UniversidadAlbertoMagno*u,string id);
    double mostrarPromedioPorCurso(UniversidadAlbertoMagno*u,string id);

    //mostrar horarios
    string mostrarHorarioProfesor(UniversidadAlbertoMagno*u,string id);
    string mostrarHorarioAlumno(UniversidadAlbertoMagno*u,string id);
};

#endif //PROYECTOPROGRAIAARONDU_CONTROLADORA_H