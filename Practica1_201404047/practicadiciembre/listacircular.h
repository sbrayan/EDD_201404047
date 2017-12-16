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
    void insertarnodo2(int cantidad);

    void mostrar();
    void eliminar();
    void eliminar(int cantidad);
};

#endif // LISTACIRCULAR_H
