#include "dobleenlazada2.h"
#include <iostream>
#include <fstream>

/*dobleenlazada2::dobleenlazada2()
{

} */

using namespace std;
Nodoenlazada *cabezadoble2=NULL;
Nodoenlazada *finaldoble2=NULL;

Nodoenlazada::Nodoenlazada(string nombre){
    this->id=nombre;
    this->contador= 0;
    this->iniciolista=NULL;
    this->iniciopila=NULL;
    this->siguiente=NULL;

}

void listaenlazada::insertarnodo(string id){

    struct Nodoenlazada *temp;
    temp= new Nodoenlazada(id);

    if(cabezadoble2==NULL && finaldoble2==NULL){
        cabezadoble2=temp;
        finaldoble2=temp;
        temp->siguiente=NULL;
        temp->anterior=NULL;
    }
    else{
        struct Nodoenlazada *aux;
        aux=finaldoble2;
        finaldoble2=temp;
        finaldoble2->siguiente=aux;
        finaldoble2->anterior=NULL;
        aux->anterior=finaldoble2;
        aux=NULL;
        free(aux);

    }

}

void listaenlazada::mostrar(){


    ofstream grafo;
    grafo.open("grafoescritorios.txt");
    grafo<<"digraph G {\n";


    struct Nodoenlazada *s;
    struct Nodoenlazada *sf;
    if(cabezadoble2==finaldoble2 && cabezadoble2==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";

      //  return;
    }
    else {
        s=cabezadoble2;
        sf= finaldoble2;

        if(s->anterior==NULL){
            grafo<<"\""<<s->id<<"\"";
          //  cout<<s->tipo<<endl;
            //cout<<s->tipo<<","<<s->pasajeros<<","<<s->mantenimiento<<endl<<endl;

        }
        else{
            while(s->anterior!=NULL){
                 grafo<<"\""<<s->id<<"\""<<"->";
               // cout<<s->tipo<<","<<s->pasajeros<<","<<s->mantenimiento<<endl<<endl;
                s=s->anterior;

            }
            grafo<<"\""<<s->id<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }
        if(sf->siguiente==NULL){
            grafo<<"\""<<sf->id<<"\"";
            //cout<<sf->tipo<<endl;

        }
        else{
            while(sf->siguiente!=NULL){
                 grafo<<"\""<<sf->id<<"\""<<"->";
                //cout<<sf->tipo<<"<->";
                sf=sf->siguiente;

            }
            grafo<<"\""<<sf->id<<"\"";
            grafo<<";"<<"\n";
           // cout<<sf->tipo<<endl;

        }
        grafo<<"}";

    }

    grafo.close();
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafoescritorios.txt -o grafoescritorios.png");



}


Nodoenlazada * listaenlazada::devolvercabeza(){
    if(cabezadoble2==NULL){
        return NULL;
    }
    return cabezadoble2;
}
