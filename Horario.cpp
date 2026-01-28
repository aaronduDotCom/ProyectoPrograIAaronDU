//
// Created by Oscar on 27/1/2026.
//

#include "Horario.h"

Horario::Horario() {
    m=new Curso **[DIAS];

    for (int i=0; i<DIAS; i++) {*(m+i) = new Curso *[FRANJA];}

    for (int i=0; i<DIAS; i++) {
        for (int j=0; j<FRANJA; j++) {
            *(*(m+i)+j) = nullptr;
        }
    }
}

Horario::~Horario() {
    for (int i=0; i<DIAS; i++) {delete[] *(m+i);}

    delete [] m;

    m=nullptr;
}

bool Horario::vacia() {
    bool result = true;

    for (int i=0; i<DIAS; i++) {
        for (int j=0; j<FRANJA; j++) {
            if (*(*(m+i)+j)!=nullptr) {
                result = false;
            }
        }
    }

    return result;
}

bool Horario::franjaLlena(int franja) {
    for (int i=0; i<DIAS; i++) {
        if (*(*(m+i)+franja)!=nullptr) {
            return false;
        }
    }
    return true;
}

Curso *Horario::buscarCurso(int codigo) {
    Curso *curso;
    for (int i=0; i<DIAS; i++) {
        for (int j=0; j<FRANJA; j++) {
            if ((*(*(m+i)+j))->getCodigo()==codigo) {
                curso=*(*(m+i)+j);
            }
        }
    }
    return curso;
}

//falta hacerlo segun el curso
bool Horario::matricularCurso(Curso *curso) {
    if (curso!=nullptr && !franjaLlena(curso->getHora())) {

        int dia = curso->getDia();
        int franja = curso->getHora();
        if (dia>=0 && dia<DIAS && franja>=0 && franja<FRANJA) {
            *(*(m+dia)+franja) = curso;
            return true;
        }

    }

    return false;
}

bool Horario::desmatricularCurso(int cod) {
    if (buscarCurso(cod)!=nullptr && !franjaLlena(cod)) {
        int dia = buscarCurso(cod)->getDia();
        int franja = buscarCurso(cod)->getHora();

        if (dia>=0 && dia<DIAS && franja>=0 && franja<FRANJA) {
            *(*(m+dia)+franja) = nullptr;
            return true;
        }
    }
    return false;
}

string Horario::toString() {
    stringstream ss;
    for (int i=0; i<DIAS; i++) {
        for (int j=0; j<FRANJA; j++) {
            ss<<" | "<<(*(*(m+i)+j))->getNombre();
        }
        ss<<" | "<<endl;
    }

    return ss.str();
}
