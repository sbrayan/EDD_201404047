#ifndef LISTAAVION2_H
#define LISTAAVION2_H
#include <iostream>
/*
class listaavion2
{
public:
    listaavion2();
}; */


typedef struct listaavion2 listaavion2;
typedef struct Nodoavion Nodoavion;
using namespace std;

struct Nodoavion{
    string tipo;
    int pasajeros;
    int desabordaje;
    int mantenimiento;
    Nodoavion *siguiente;
    Nodoavion *anterior;
    Nodoavion(string tipo,int pasajeros,int desabordaje,int mantenimiento);
};

struct listaavion2{
    Nodoavion *crearnodo;
    void insertarnodo(string tipo,int pasajeros,int desabordaje,int mantenimiento);
    Nodoavion *devolvercabeza();
    void mostrar();
    void eliminar();
};

#endif // LISTAAVION2_H
