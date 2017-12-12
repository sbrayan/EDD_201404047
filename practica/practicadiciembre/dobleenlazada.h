#ifndef DOBLEENLAZADA_H
#define DOBLEENLAZADA_H
#include <iostream>
#include "pila.h"
#include "listasimple.h"
using namespace std;
struct doble;


class dobleenlazada
{
public:
    dobleenlazada();
    doble *crearnodo(string);
    doble *insertarnodo(string id);
    doble *retornarinicioescritorios();

    void mostrar();
    void eliminar();
};

#endif // DOBLEENLAZADA_H

