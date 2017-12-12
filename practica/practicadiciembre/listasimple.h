#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include <iostream>
#include <fstream>

using namespace std;
struct nodosimple;
class listasimple
{
public:
    listasimple();
    nodosimple *crearnodo(int,int,int,int);
    nodosimple *insertarnodo(int,int,int,int);
    void mostrar();
    void eliminar();
};

#endif // LISTASIMPLE_H



