#ifndef PILA_H
#define PILA_H
#include <iostream>

using namespace std;
struct nodopila;

class pila
{
public:
    pila();
    nodopila *crearnodo(string);
    nodopila *insertarnodo(string iddocumento);

    void mostrar();
    void eliminar();
};

#endif // PILA_H
