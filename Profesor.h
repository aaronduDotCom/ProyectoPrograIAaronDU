//
// Created by Oscar on 27/1/2026.
//

#ifndef PROYECTOPROGRAIAARONDU_PROFESOR_H
#define PROYECTOPROGRAIAARONDU_PROFESOR_H

#include "Persona.h"
#include "Horario.h"
class Horario;

#include <string>
#include <sstream>
using namespace std;

class Profesor:public Persona {
private:
    Horario *horario;
public:
    Profesor();
    Profesor(string nombre, int id);
    ~Profesor() override;

    string getTipo();

    bool asignarCurso(int cod);
    bool desasignarCurso(int cod);

    void asignarNota(int codCur, int codEst, int nuevaNota);

    string toString() override;
};


#endif //PROYECTOPROGRAIAARONDU_PROFESOR_H