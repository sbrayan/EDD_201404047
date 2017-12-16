#ifndef LISTAAVIONESPERA_H
#define LISTAAVIONESPERA_H
#include <iostream>



typedef struct listaavionespera listaavionespera;
typedef struct Nodoavionespera Nodoavionespera;
using namespace std;

struct Nodoavionespera{
    string id;
    int turnos;
    Nodoavionespera*siguiente;
    Nodoavionespera(string id,int turnos);
};

struct listaavionespera{
    Nodoavionespera *crearnodo;
    void insertarnodo(string id,int turnos);
    void mostrar();
    void eliminar();
    Nodoavionespera *devolvercabeza();
    int devolvercantidadnodos();

};

#endif // LISTAAVIONESPERA_H
