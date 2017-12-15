#include "listaavionespera.h"
#include <fstream>

/*listaavionespera::listaavionespera()
{

}*/



Nodoavionespera *cabezaavionespera=NULL;


Nodoavionespera::Nodoavionespera(string id,int turnos){
    this->id=id;
    this->turnos=turnos;
    this->siguiente=NULL;

}

void listaavionespera::insertarnodo(string id,int turnos){
    struct Nodoavionespera *temp;
    temp=new Nodoavionespera(id,turnos);

    if(cabezaavionespera==NULL){
        cabezaavionespera=temp;
        temp->siguiente=NULL;



    }
    else{
        struct Nodoavionespera *aux;
        aux=cabezaavionespera;
        temp->siguiente=aux;
        cabezaavionespera=temp;
        aux=NULL;
        free(aux);

    }

}

void listaavionespera::eliminar(){
    Nodoavionespera *aux;
    Nodoavionespera *auxante;
    aux=cabezaavionespera;
    if(aux==NULL){
        cout<<"lista de avion de espera vacia"<<endl;
        return;
    }
    if(aux->siguiente==NULL){//solo hay un elemento
        cabezaavionespera=NULL;
        //free(aux);
        return;
    }

    while(aux->siguiente!=NULL){
        auxante=aux;
        aux=aux->siguiente;
    }
    if(auxante!=NULL && aux!=NULL){
        //eliminar
        auxante->siguiente=NULL;
       // free(aux);
        //free(auxante);
    }






}

void listaavionespera::mostrar(){
    ofstream grafo;
    grafo.open("grafogrande.txt",ios::app);
    grafo<<"subgraph listaespera {\n";
    struct Nodoavionespera *s;

    if(cabezaavionespera==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=cabezaavionespera;


        if(s->siguiente==NULL){
            grafo<<"\""<<"avion-"<<s->id<<"\"";
          //  cout<<s->tipo<<endl;

        }
        else{
            while(s->siguiente!=NULL){
                 grafo<<"\""<<"avion-"<<s->id<<"\""<<"->";
                //cout<<s->tipo<<"<->";
                s=s->siguiente;

            }
            grafo<<"\""<<"avion-"<<s->id<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }

        grafo<<"}";

    }

    grafo.close();
}


Nodoavionespera* listaavionespera::devolvercabeza(){
    Nodoavionespera *aux;
    Nodoavionespera *auxante;
    aux=cabezaavionespera;
    if(aux==NULL){

        return NULL;
    }
    if(aux->siguiente==NULL){//solo hay un elemento

        //free(aux);
        return aux;
    }

    while(aux->siguiente!=NULL){

        aux=aux->siguiente;
    }
    if(auxante!=NULL && aux!=NULL){
        //eliminar
        return aux;
       // free(aux);
        //free(auxante);
    }


}

int listaavionespera::devolvercantidadnodos(){
 int auxnumero=0;
    Nodoavionespera *aux;

    aux=cabezaavionespera;
    if(aux==NULL){

        return 0;
    }
    if(aux->siguiente==NULL){//solo hay un elemento
        return 1;

    }

    while(aux->siguiente!=NULL){
        auxnumero++;

        aux=aux->siguiente;
    }
    if(aux!=NULL){
        auxnumero++;
    }

    return auxnumero;



}
