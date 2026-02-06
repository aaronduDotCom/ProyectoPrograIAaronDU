//
// Created by Oscar on 27/1/2026.
//

#include "Interfaz.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Controladora.h"

#include <limits>

Interfaz::Interfaz() {
    ualma = new UniversidadAlbertoMagno();
}

Interfaz::~Interfaz() {
    delete ualma;
}

bool Interfaz::leerInt(int& x) {
    cin >> x;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}


void Interfaz::ejecutarInterfaz(Controladora*c) {
    int opcion=1;

    while (opcion!=0) {
        {
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
        }//primer menu
        if (!leerInt(opcion)) continue;

        if (opcion<0||opcion>4) {opcion=0;}
        switch (opcion) {
            case 1: {
                int opcionSubmenu1=1;
                while (opcionSubmenu1!=0) {
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

                    if (!leerInt(opcionSubmenu1)) continue;

                    if (opcionSubmenu1<0||opcionSubmenu1>3) {opcionSubmenu1=0;}
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
                }
            }break;//UALMA
            case 2: {
                int opcionSubmenu2=1;
                while (opcionSubmenu2!=0) {
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

                    if (!leerInt(opcionSubmenu2)) continue;

                    if (opcionSubmenu2<0||opcionSubmenu2>7) {opcionSubmenu2=0;}
                    switch (opcionSubmenu2) {
                        case 1:{
                            cout<<"Registrar un nuevo estudiante\n";

                            string nombre;
                            cout<<"Ingrese el nombre\n";

                            getline(cin,nombre);

                            string id="";
                            cout<<"Ingrese el numero de identificacion\n";

                            getline(cin,id);

                            int dia=-1;
                            cout<<"Ingrese el dia (lunes 1 - domingo 6)\n";

                            if (!leerInt(dia)) continue;

                            int hora=-1;
                            cout<<"Ingrese la hora (8am - 7pm)\n";

                            if (!leerInt(hora)) continue;

                            string profAsignado="";
                            cout<<"Ingrese el id del profesor a asignar\n";

                            getline(cin,profAsignado);

                            int limCupos=-1;
                            cout<<"Ingrese el limite de cupos\n";

                            if (!leerInt(limCupos)) continue;


                            if (c->registrarCursos(ualma, id, nombre, dia, hora, profAsignado, limCupos)) {
                                cout << nombre << " ha sido creado exitosamente\n";
                            } else {
                                cout << nombre << " no ha podido ser creado\n";
                            }

                            Persona* p = ualma->getListaEstudiantes()->buscar(id);
                            if (p != nullptr) {
                                cout << p->toString();
                            }
                        }break;
                        case 2: {
                            cout<<"Expulsar un estudiante\n";

                            string id="";
                            cout<<"Ingrese el numero de identificacion\n";

                            getline(cin,id);

                            string nombre=" ";
                            Persona *aux=ualma->getListaEstudiantes()->buscar(id);
                            if (aux!=nullptr)
                                nombre=aux->getNombre();

                            if (c->expulsarEstudiante(ualma, id)) {
                                cout << nombre << " ha sido eliminado exitosamente\n";
                            } else {
                                cout << nombre << " no ha sido ser eliminado\n";
                            }

                        }break;
                        case 3: {
                            cout<<"Matricular curso\n";

                            string idEst="";
                            cout<<"Ingrese el numero de identificacion del estudiante\n";

                            getline(cin,idEst);

                            string idCur="";
                            cout<<"Ingrese el codigo del curso\n";

                            getline(cin,idCur);

                            Persona *auxEst=ualma->getListaEstudiantes()->buscar(idEst);
                            Curso *auxCur=ualma->getListaCursos()->buscar(idCur);

                            if (auxEst != nullptr && auxCur != nullptr) {
                                if (c->matricularCurso(ualma, idEst, idCur)) {
                                cout <<"El curso ha sido matriculado exitosamente\n";
                                } else {
                                cout <<"El curso no ha podido ser matriculado\n";
                                }
                            }

                        }break;
                        case 4: {
                            cout<<"Desmatricular curso\n";

                            string idEst="";
                            cout<<"Ingrese el numero de identificacion del estudiante\n";

                            getline(cin,idEst);

                            string idCur="";
                            cout<<"Ingrese el codigo del curso\n";

                            getline(cin,idCur);

                            Persona *auxEst=ualma->getListaEstudiantes()->buscar(idEst);
                            Curso *auxCur=ualma->getListaCursos()->buscar(idCur);

                            if (auxEst != nullptr && auxCur != nullptr) {
                                if (c->desmatricularCurso(ualma, idEst, idCur)) {
                                    cout <<"El curso ha sido desmatriculado exitosamente\n";
                                } else {
                                    cout <<"El curso no ha podido ser desmatriculado\n";
                                }
                            }
                        }break;
                        case 5: {
                            cout<<"Mostrar la informacion de un estudiante\n";

                            string idEst="";
                            cout<<"Ingrese el numero de identificacion del estudiante\n";

                            getline(cin,idEst);

                            Persona *auxEst=ualma->getListaEstudiantes()->buscar(idEst);

                            if (auxEst!=nullptr) {
                                cout <<auxEst->toString();
                            } else {
                                cout <<"El estudiante no se encontro\n";
                            }
                        }break;
                        case 6: {
                            cout<<"Mostrar el horario de un estudiante\n";

                            string idEst="";
                            cout<<"Ingrese el numero de identificacion del estudiante\n";

                            getline(cin,idEst);

                            Persona *auxEst=ualma->getListaEstudiantes()->buscar(idEst);

                            if (auxEst!=nullptr) {
                                cout <<auxEst->getHorario()->toString();
                            } else {
                                cout <<"El estudiante no se encontro\n";
                            }
                        }break;
                        case 7: {
                            cout<<"Mostrar la nota de un estudiante\n";

                            string idEst="";
                            cout<<"Ingrese el numero de identificacion del estudiante\n";

                            getline(cin,idEst);

                            Persona *auxEst=ualma->getListaEstudiantes()->buscar(idEst);

                            if (auxEst!=nullptr) {
                                cout <<auxEst->getCalificacionGlobal()<<endl;
                            } else {
                                cout <<"El estudiante no se encontro\n";
                            }
                        }break;
                    default:break;
                }
            }break;
            }//Estudiantes
            case 3: {
                int opcionSubmenu3=1;
                    while (opcionSubmenu3!=0) {
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

                        if (!leerInt(opcionSubmenu3)) continue;

                        if (opcionSubmenu3<0||opcionSubmenu3>4) {opcionSubmenu3=0;}
                        switch (opcionSubmenu3) {
                            case 1: {
                                cout<<"Contratar un nuevo profesor\n";

                                string nombre;
                                cout<<"Ingrese el nombre\n";

                                getline(cin,nombre);

                                string id="";
                                cout<<"Ingrese el numero de identificacion\n";

                                getline(cin,id);

                                if (c->registrarProfesores(ualma, nombre, id)) {
                                    cout << nombre << " ha sido ingresado exitosamente\n";
                                } else {
                                    cout << nombre << " no ha podido ser ingresado\n";
                                }

                                Persona* p = ualma->getListaProfesores()->buscar(id);
                                if (p != nullptr) {
                                    cout << p->toString();
                                }
                            }break;
                            case 2: {

                            }break;
                            default:{}break;
                    }
                }
            }break;//Profesores
            case 4: {
                int opcionSubmenu4=1;
                    while (opcionSubmenu4!=0) {
                        cout<<"**********************************************************\n"
                         <<"*                                                        *\n"
                         <<"*             Opciones de gestion de cursos              *\n"
                         <<"*                                                        *\n"
                         <<"*               Universidad Alberto Magno                *\n"
                         <<"*                                                        *\n"
                         <<"**********************************************************\n";
                        cout<<"\nIngrese una opcion: \n"
                        <<"1.Agregar un curso\n"
                        <<"2.Eliminar un curso\n"
                        <<"3.Mostrar informacion del curso\n"
                        <<"4.Mostrar promedio del curso\n"
                        <<"5.Mostrar profesor asignado\n"
                        <<"6.Reasignar profesor\n";

                        if (!leerInt(opcionSubmenu4)) continue;

                    if (opcionSubmenu4<0||opcionSubmenu4>6) {opcionSubmenu4=0;}
                    switch (opcionSubmenu4) {
                        case 1: {

                        }break;
                        case 2: {

                        }break;
                        case 3: {

                        }break;
                        case 4: {

                        }break;
                        case 5: {

                        }break;
                        case 6: {

                        }break;
                        default:break;
                    }
                }
            }break;//Cursos
            default:break;
        }
    }
}