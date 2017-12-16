#ifndef LISTASIMPLEESCRITORIOS_H
#define LISTASIMPLEESCRITORIOS_H
#include <iostream>

class listasimpleescritorios
{
public:
    listasimpleescritorios();
};


typedef struct listasimpleescri listasimpleescri;
typedef struct Nodosimpleescri Nodosimpleescri;
using namespace std;

struct Nodosimpleescri{
   // string id;
    int identificacion;
    int maletas;
    int documentos;
    int turnos;

    Nodosimpleescri *siguiente;

    Nodosimpleescri(int identificacion,int maletas,int documentos,int turnos);
};

struct listasimpleescri{
    Nodosimpleescri *crearnodo;
    void insertarnodo(int identificacion,int maletas,int documentos,int turnos);
    Nodosimpleescri *devolvercabeza();
    void mostrar();
    void eliminar();
    void grafogrande();
};




#endif // LISTASIMPLEESCRITORIOS_H
