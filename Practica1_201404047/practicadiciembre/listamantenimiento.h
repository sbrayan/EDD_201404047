#ifndef LISTAESCRITORIOS_H
#define LISTAESCRITORIOS_H
#include <iostream>
#include "listaavionespera.h"

typedef struct listamantenimiento listamantenimiento;
typedef struct Nodomantenimiento Nodomantenimiento;
using namespace std;

struct Nodomantenimiento{
    int id;
    Nodoavionespera *principioavion;
    Nodomantenimiento*siguiente;

    Nodomantenimiento(int id);
};

struct listamantenimiento{
    Nodomantenimiento *crearnodo;
    void insertarnodo(int id);
    void mostrar();
    Nodomantenimiento* devolverultimo();
    Nodomantenimiento* devolvercabeza();

};

#endif // LISTAESCRITORIOS_H
