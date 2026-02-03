//
// Created by Oscar on 27/1/2026.
//

#include "Interfaz.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Controladora.h"

Interfaz::Interfaz() {
    ualma = new UniversidadAlbertoMagno();
}

Interfaz::~Interfaz() {
    delete ualma;
}

void Interfaz::ejecutarInterfaz(Controladora*c) {
    int opcion=1;

    while (opcion!=0) {
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
                int opcionSubmenu1=0;
                cout<<"**********************************************************\n"
                    <<"*                                                        *\n"
                    <<"*         Opciones de gestion de la universidad          *\n"
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
                switch (opcionSubmenu1) {
                    case 1: {
                        cout<<"Mostrar todos los estudiantes\n";
                        cout << c->mostrarTodosLosEstudiantes(ualma);

                    }break;
                    case 2: {
                        cout<<"Mostrar todos los profesores\n";
                        cout << c->mostrarTodosLosProfesores(ualma);

                    }break;
                    case 3: {
                        cout<<"Mostrar todos los cursos\n";
                        cout << c->mostrarTodosLosCursos(ualma);

                    }break;
                    default:break;
                }

            }break;
            case 2: {
                int opcionSubmenu2=0;
                cout<<"**********************************************************\n"
                    <<"*                                                        *\n"
                    <<"*          Opciones de gestion de estudiantes            *\n"
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
                cin>>opcionSubmenu2;
                switch (opcionSubmenu2) {
                    case 1:{
                        cout<<"Registrar un nuevo estudiante\n";

                        string nombre;
                        cout<<"Ingrese el nombre\n";
                        cin.ignore();
                        getline(cin,nombre);

                        int id=0;
                        cout<<"Ingrese el numero de identificacion\n";
                        cin>>id;

                        if (c->registrarEstudiante(ualma, nombre, id)) {
                            cout << nombre << " ha sido ingresado exitosamente\n";
                        } else {
                            cout << nombre << " no ha podido ser ingresado\n";
                        }

                        Persona* p = ualma->getListaEstudiantes()->buscar(id);
                        if (p != nullptr) {
                            cout << p->toString();
                        }
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
                    default:break;
                }
            }break;
            case 3: {
                int opcionSubmenu3=0;
                cout<<"**********************************************************\n"
                    <<"*                                                        *\n"
                    <<"*           Opciones de gestion de profesores            *\n"
                    <<"*                                                        *\n"
                    <<"*               Universidad Alberto Magno                *\n"
                    <<"*                                                        *\n"
                    <<"**********************************************************\n";
                cout<<"\nIngrese una opcion: \n"
                    <<"1.Contratar un nuevo profesor\n"
                    <<"2.Despedir un profesor\n"
                    <<"3.Mostrar informacion de un profesor\n"
                    <<"4.Mostrar promedio por profesor\n"
                    <<"0.Salir de la opcion\n";
                cin>>opcionSubmenu3;
                switch (opcionSubmenu3) {
                    case 1: {

                    }break;
                    case 2: {

                    }break;
                    default:{}break;
                }
            }break;
            case 4: {
                int opcionSubmenu4=0;
                cout<<"**********************************************************\n"
                     <<"*                                                        *\n"
                     <<"*             Opciones de gestion de cursos              *\n"
                     <<"*                                                        *\n"
                     <<"*               Universidad Alberto Magno                *\n"
                     <<"*                                                        *\n"
                     <<"**********************************************************\n";
                cout<<"\nIngrese una opcion: \n"
                    <<"1.Mostrar todos los estudiantes\n"
                    <<"2.Mostrar todos los profesores\n"
                    <<"3.Mostrar todos los cursos\n"
                    <<"0.Salir de la opcion\n";
                cin>>opcionSubmenu4;
                switch (opcionSubmenu4) {
                    case 1: {

                    }break;
                    default:break;
                }
            }break;
            default:break;
        }
    }
}
