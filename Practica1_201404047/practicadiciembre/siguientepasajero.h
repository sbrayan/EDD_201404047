#ifndef SIGUIENTEPASAJERO_H
#define SIGUIENTEPASAJERO_H
#include <iostream>
#include "listasimple.h"


class siguientepasajero
{
public:
    siguientepasajero();
    void agregarpasajeroacolasimple(int cantidad);
    void agregarescritorios(int cantidadescritorios);
    void moverpasajeros();
    void mostrarlistapasajero();
    void hacergrafo();
    void hacergrafogrande();
    void mostrarlistacircular();
    void moverpasajeros2();
    void restarturnoescritorio();
    void generargrafogeneral();
};

#endif // SIGUIENTEPASAJERO_H
