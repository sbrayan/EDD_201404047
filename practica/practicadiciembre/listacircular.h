#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <iostream>
#include <fstream>

using namespace std;
struct nodocircular;

class listacircular
{
public:
    listacircular();
    nodocircular *crearnodo(int);
    nodocircular *insertarnodo(int);

    void mostrar();
    void eliminar();
};

#endif // LISTACIRCULAR_H
