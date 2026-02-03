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

Curso * Horario::getCurso(int x,int y) {
    if (x >= 0 && x < DIAS && y >= 0 && y < FRANJA) {return *(*(m+x)+y);}
    return nullptr;
}

void Horario::setCurso(Curso *curso) {
    if (curso == nullptr) return;

    int dia = curso->getDia();
    int hora = curso->getHora();

    *(*(m+dia)+hora)=curso;
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

bool Horario::franjaVacia(int franja) {
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

string Horario::toString() {
    stringstream ss;
    for (int i=0; i<DIAS; i++) {
        for (int j=0; j<FRANJA; j++) {
            if ((*(*(m+i)+j))!=nullptr) {
                ss<<" | "<<(*(*(m+i)+j))->getNombre();
            }else {
                ss<<"\t\t";
            }

        }
        ss<<" | "<<endl;
    }

    return ss.str();
}
