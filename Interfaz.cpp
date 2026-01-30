//
// Created by Oscar on 27/1/2026.
//

#include "Interfaz.h"
#include "Controladora.h"

Interfaz::Interfaz() {
    u = new UniversidadAlbertoMagno();
}

void Interfaz::ejecutarInterfaz() {
    int opcion=1;
    while (opcion!=0) {
        cout<<"Hola mundo";
        switch (opcion) {
            case 1: {
                cin>>opcion;
            }break;
        }
        cout<<"Hola mundo";
        opcion=0;
    }
}
