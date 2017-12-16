#include "pila.h"
#include <fstream>

pila::pila()
{

}

struct nodopila{
    string idcoumento;
    nodopila *siguiente;
}*cabezapila=NULL;

nodopila* pila::crearnodo(string iddocumento)
{
    struct nodopila *tmp;
    tmp= new (struct nodopila);
    tmp->idcoumento=iddocumento;
    tmp->siguiente=NULL;
    return tmp;

}

nodopila* pila::insertarnodo(string iddocumento){
    struct nodopila *temp;
    temp=crearnodo(iddocumento);

    if(cabezapila==NULL){
        cabezapila=temp;
        temp->siguiente=NULL;



    }
    else{
        struct nodopila *aux;
        aux=cabezapila;
        temp->siguiente=aux;
        cabezapila=temp;
        aux=NULL;
        free(aux);

    }

}


void pila:: mostrar()
{
    ofstream grafo;
    grafo.open("grafopila.txt");
    grafo<<"digraph G {\n";


    struct nodopila *s;

    if(cabezapila==NULL)
    {
        cout<<"la pila esta vacia para imprimir"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=cabezapila;


        if(s->siguiente==NULL){
            grafo<<"\""<<s->idcoumento<<"\"";
          //  cout<<s->tipo<<endl;

        }
        else{
            while(s->siguiente!=NULL){
                 grafo<<"\""<<s->idcoumento<<"\""<<"->";
                //cout<<s->tipo<<"<->";
                s=s->siguiente;

            }
            grafo<<"\""<<s->idcoumento<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }

        grafo<<"}";

    }

    grafo.close();
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafopila.txt -o grafopila.png");



}


void pila::eliminar(){

    struct nodopila *aux1;
    aux1=cabezapila;
    if(aux1==NULL){
        cout<<"pila vacia para eliminar"<<endl;
    }
    else{
        if(aux1->siguiente==NULL){
            cabezapila=NULL;
            free(aux1);
        }
        else{
            struct nodopila *aux2;
            aux2=aux1->siguiente;
            cabezapila=aux2;
            free(aux1);
        }

    }
}

