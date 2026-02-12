#include <iostream>
#include "Interfaz.h"
#include "Controladora.h"

int main() {
    Controladora c;
    Interfaz i;
    i.ejecutarInterfaz(&c);

    return 0;
}