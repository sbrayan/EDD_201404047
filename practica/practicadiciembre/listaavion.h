#ifndef LISTAAVION_H
#define LISTAAVION_H
#include <iostream>


using namespace std;
struct avion;



class listaavion
{
public:
    listaavion();
    avion *crearnodo(string,int,int,int);
    avion *insertarnodo(string tipo,int pasajero,int desabordaje,int mantenimiento);

    void mostrar();
    void mostrar2();
    void eliminar();
};

#endif // LISTAAVION_H
