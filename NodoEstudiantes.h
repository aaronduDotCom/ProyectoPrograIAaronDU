//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_NODOESTUDIANTES_H
#define PROYECTOPROGRAIAARONDU_NODOESTUDIANTES_H

#include "Estudiante.h"
class Estudiante;

class NodoEstudiantes {
private:
    NodoEstudiantes *sig;
    Estudiante* estudiante;
public:
    NodoEstudiantes();
    NodoEstudiantes(NodoEstudiantes *sig,Estudiante *estudiante);
    ~NodoEstudiantes();
    NodoEstudiantes *getSig();
    void setSig(NodoEstudiantes *sig);
    Estudiante *getEstudiante();
    void setEstudiante(Estudiante *estudiante);
};


#endif //PROYECTOPROGRAIAARONDU_NODOESTUDIANTES_H