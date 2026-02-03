//
// Created by Oscar on 27/1/2026.
//

#include "Interfaz.h"
#include "Controladora.h"

Interfaz::Interfaz() {
    u = new UniversidadAlbertoMagno();
}

void Interfaz::ejecutarInterfaz() {
    UniversidadAlbertoMagno *ualma = new UniversidadAlbertoMagno();
    char opcion='1';

    while (opcion!='0') {
        cout<<"**********************************************************\n"
            <<"*                                                        *\n"
            <<"*   Bienvenido al sistema de gestion electronico de la   *\n"
            <<"*                                                        *\n"
            <<"*               Universidad Alberto Magno                *\n"
            <<"*                                                        *\n"
            <<"**********************************************************\n";
        cout<<"\nIngrese una opcion: \n"
            <<"1.Universidad Alberto Magno\n"
            <<"2.Estudiantes\n"
            <<"3.Profesores\n"
            <<"4.Cursos\n"
            <<"0.Salir del sistema\n";
        cin>>opcion;

        switch (opcion) {
            case 1: {
                cout<<"**********************************************************\n"
                    <<"*                                                        *\n"
                    <<"*         Opciones de geastion de la universidad         *\n"
                    <<"*                                                        *\n"
                    <<"*               Universidad Alberto Magno                *\n"
                    <<"*                                                        *\n"
                    <<"**********************************************************\n";
                cout<<"\nIngrese una opcion: \n"
                    <<"1.Registrar un nuevo estudiante\n"
                    <<"2.Expulsar un estudiante\n"
                    <<"3.Matricular un curso\n"
                    <<"4.Desmatricular un curso\n"
                    <<"5.Mostrar la informacion de un estudiante\n"
                    <<"6.Mostrar el horario de un estudiante\n"
                    <<"7.Mostrar la nota de un estudiante\n"
                    <<"0.Salir de la opcion\n";
                cin>>opcion;
                switch (opcion) {
                    case 1:{
                        cout<<"Registrar un nuevo estudiante\n";
                    }break;
                    case 2: {
                        cout<<"Expulsar un estudiante\n";
                    }break;
                    case 3: {
                        cout<<"Matricular curso\n";
                    }break;
                    case 4: {
                        cout<<"Desmatricular curso\n";
                    }break;
                    case 5: {
                        cout<<"Mostrar la informacion de un estudiante\n";
                    }break;
                    case 6: {
                        cout<<"Mostrar el horario de un estudiante\n";
                    }break;
                    case 7: {
                        cout<<"Mostrar la nota de un estudiante\n";
                    }break;
                }
            }break;
            case 2: {
                cout<<"**********************************************************\n"
                    <<"*                                                        *\n"
                    <<"*          Opciones de geastion de estudiantes           *\n"
                    <<"*                                                        *\n"
                    <<"*               Universidad Alberto Magno                *\n"
                    <<"*                                                        *\n"
                    <<"**********************************************************\n";
                cout<<"\nIngrese una opcion: \n"
                    <<"1.Mostrar todos los estudiantes\n"
                    <<"2.Mostrar todos los profesores\n"
                    <<"3.Mostrar todos los cursos\n"
                    <<"0.Salir de la opcion\n";
                cin>>opcion;
                switch (opcion) {
                    case 1: {

                    }break;
                }
            }break;
            case 3: {
                cout<<"**********************************************************\n"
                    <<"*                                                        *\n"
                    <<"*           Opciones de geastion de profesores           *\n"
                    <<"*                                                        *\n"
                    <<"*               Universidad Alberto Magno                *\n"
                    <<"*                                                        *\n"
                    <<"**********************************************************\n";
                cout<<"\nIngrese una opcion: \n"
                    <<"1.Mostrar todos los estudiantes\n"
                    <<"2.Mostrar todos los profesores\n"
                    <<"3.Mostrar todos los cursos\n"
                    <<"0.Salir de la opcion\n";
                cin>>opcion;
                switch (opcion) {
                    case 1: {

                    }break;
                }
            }break;
            case 4: {
                cout<<"**********************************************************\n"
                     <<"*                                                        *\n"
                     <<"*             Opciones de geastion de cursos             *\n"
                     <<"*                                                        *\n"
                     <<"*               Universidad Alberto Magno                *\n"
                     <<"*                                                        *\n"
                     <<"**********************************************************\n";
                cout<<"\nIngrese una opcion: \n"
                    <<"1.Mostrar todos los estudiantes\n"
                    <<"2.Mostrar todos los profesores\n"
                    <<"3.Mostrar todos los cursos\n"
                    <<"0.Salir de la opcion\n";
                cin>>opcion;
                switch (opcion) {
                    case 1: {

                    }break;
                }
            }break;
        }
    }
    delete ualma;
}
