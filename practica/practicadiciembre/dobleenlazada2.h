#ifndef DOBLEENLAZADA2_H
#define DOBLEENLAZADA2_H
#include <iostream>
#include "listasimpleescritorios.h"
/*
class dobleenlazada2
{
public:
    dobleenlazada2();
}; */



typedef struct listaenlazada listaenlazada;
typedef struct Nodoenlazada Nodoenlazada;
using namespace std;

struct Nodoenlazada{
    string id;
    int contador;
    struct nodopila *iniciopila;
    struct Nodosimpleescri *iniciolista;
    Nodoenlazada *siguiente;
    Nodoenlazada *anterior;
    Nodoenlazada(string id);
};

struct listaenlazada{
    Nodoenlazada *crearnodo;
    void insertarnodo(string id);
    Nodoenlazada *devolvercabeza();
    void mostrar();
    void eliminar();
};

#endif // DOBLEENLAZADA2_H
