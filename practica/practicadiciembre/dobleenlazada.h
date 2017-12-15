#ifndef DOBLEENLAZADA_H
#define DOBLEENLAZADA_H
#include <iostream>
#include "pila.h"
#include "listasimple.h"
using namespace std;
//struct doble;
typedef struct doble doble;


using namespace std;


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

