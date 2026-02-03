#include <iostream>
#include "Interfaz.h"
#include "Controladora.h"

int main() {
    Controladora *c=new Controladora();
    Interfaz *i=new Interfaz();
    i->ejecutarInterfaz(c);
    delete i;
    delete c;

    return 0;
}