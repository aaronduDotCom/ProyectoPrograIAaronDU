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

    if (dia < 0 || dia >= DIAS) return;
    if (hora < 0 || hora >= FRANJA) return;

    m[dia][hora] = curso;
}

void Horario::eliminarCurso(int dia, int hora) {
    if (dia < 0 || dia >= DIAS) return;
    if (hora < 0 || hora >= FRANJA) return;

    *(*(m+dia)+hora) = nullptr;
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
    if (franja < 0 || franja >= FRANJA) return false;

    if (vacia()) return true;

    for (int i=0; i<DIAS; i++) {
        if (*(*(m+i)+franja)!=nullptr) {
            return false;
        }
    }
    return true;
}

Curso *Horario::buscarCurso(string codigo) {
    for (int i=0; i<DIAS; i++) {
        for (int j=0; j<FRANJA; j++) {

            if ((*(*(m+i)+j))!=nullptr) {
                if ((*(*(m+i)+j))->getCodigo()==codigo) {
                return *(*(m+i)+j);
                }
            }
        }
    }
    return nullptr;
}

string Horario::toString() {
    stringstream ss;

    for (int i = 0; i < FRANJA; i++) {
        for (int j = 0; j < DIAS; j++) {

            if (*(*(m+i)+j) != nullptr){
                ss << (*(*(m+i)+j))->getCodigo();
            }else
                ss << "0";

            if (j < DIAS-1)
                ss << ";";
        }
        ss << "\n";
    }
    return ss.str();
}


//Este si me lo medio hizo mi compa gpt
string Horario::toDisplayString() {
    stringstream ss;

    ss << "Horario \n";
    ss << "******************************************************************\n";
    ss << "  Hora   |  Lun  |  Mar  |  Mie  |  Jue  |  Vie  |  Sab  |  Dom  |\n";
    ss << "******************************************************************\n";

    for (int h = 0; h < FRANJA; h++) {
        ss << (h + 8) << "\t |";

        for (int d = 0; d < DIAS; d++) {
            if (*(*(m+d)+h) != nullptr) {
                ss << " " << (*(*(m+d)+h))->getNombre() << "\t";
            } else {
                ss << "\t";
            }
            ss << " |";
        }
        ss << endl;
    }
    ss << endl;

    return ss.str();
}

