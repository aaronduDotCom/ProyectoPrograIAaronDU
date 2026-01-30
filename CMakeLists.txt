cmake_minimum_required(VERSION 4.1)
project(ProyectoPrograIAaronDU)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoPrograIAaronDU main.cpp
        Interfaz.cpp
        Interfaz.h
        Controladora.cpp
        Controladora.h
        UniversidadAlbertoMagno.cpp
        UniversidadAlbertoMagno.h
        Horario.cpp
        Horario.h
        Curso.cpp
        Curso.h
        Persona.cpp
        Persona.h
        Estudiante.cpp
        Estudiante.h
        Profesor.cpp
        Profesor.h
        NodoEstudiantes.cpp
        NodoEstudiantes.h
        NodoProfesores.cpp
        NodoProfesores.h
        NodoCursos.cpp
        NodoCursos.h
        ListaEstudiantes.cpp
        ListaEstudiantes.h
        ListaProfesores.cpp
        ListaProfesores.h
        ListaCursos.cpp
        ListaCursos.h
        ListaPersonas.cpp
        ListaPersonas.h
        NodoPersonas.cpp
        NodoPersonas.h)
