#include "listaavion.h"
#include <fstream>

 listaavion::listaavion()
{

}

using namespace std;
struct avion{
    string tipo;
    int pasajeros;
    int desabordaje;
    int mantenimiento;
    struct avion *siguiente;
    struct avion *anterior;
} *cabezalistaavion=NULL,*finallistaavion=NULL;


avion* listaavion::crearnodo(string tipo,int pasajeros,int desabordaje,int mantenimiento)
{
    struct avion *tmp;
    tmp= new (struct avion);
    tmp->tipo=tipo;
    tmp->pasajeros=pasajeros;
    tmp->desabordaje=desabordaje;
    tmp->mantenimiento=mantenimiento;
    tmp->siguiente=NULL;
    tmp->anterior=NULL;
    return tmp;


}

avion* listaavion::insertarnodo(string tipo, int pasajeros, int desabordaje, int mantenimiento){
    struct avion *temp;
    temp=crearnodo(tipo,pasajeros,desabordaje,mantenimiento);

    if(cabezalistaavion==NULL && finallistaavion==NULL){
        cabezalistaavion=temp;
        finallistaavion=temp;
        temp->siguiente=NULL;
        temp->anterior=NULL;


    }
    else{
        struct avion *aux;
        aux=finallistaavion;
        finallistaavion=temp;
        finallistaavion->siguiente=aux;
        finallistaavion->anterior=NULL;
        aux->anterior=finallistaavion;
        aux=NULL;
        free(aux);

    }


}




void listaavion:: mostrar()
{


    ofstream grafo;
    grafo.open("grafo1.txt");
    grafo<<"digraph G {\n";


    struct avion *s;
    struct avion *sf;
    if(cabezalistaavion==finallistaavion && cabezalistaavion==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=cabezalistaavion;
        sf= finallistaavion;

        if(s->anterior==NULL){
            grafo<<"\""<<s->tipo<<"\"";
          //  cout<<s->tipo<<endl;
            cout<<s->tipo<<","<<s->pasajeros<<","<<s->mantenimiento<<endl<<endl;

        }
        else{
            while(s->anterior!=NULL){
                 grafo<<"\""<<s->tipo<<"\""<<"->";
                cout<<s->tipo<<","<<s->pasajeros<<","<<s->mantenimiento<<endl<<endl;
                s=s->anterior;

            }
            grafo<<"\""<<s->tipo<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }
        if(sf->siguiente==NULL){
            grafo<<"\""<<sf->tipo<<"\"";
            //cout<<sf->tipo<<endl;

        }
        else{
            while(sf->siguiente!=NULL){
                 grafo<<"\""<<sf->tipo<<"\""<<"->";
                //cout<<sf->tipo<<"<->";
                sf=sf->siguiente;

            }
            grafo<<"\""<<sf->tipo<<"\"";
            grafo<<";"<<"\n";
           // cout<<sf->tipo<<endl;

        }
        grafo<<"}";

    }

    grafo.close();
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafo1.txt -o grafo1.png");



}


void listaavion::eliminar(){
    struct avion *aux;
    struct avion *aux2;
    struct avion *aux3;
    aux=cabezalistaavion;
    aux3=finallistaavion;



   if(aux==aux3){
        cabezalistaavion=NULL;
        finallistaavion=NULL;
        free(aux);
    }
    else{

        aux2=aux->anterior;
        cabezalistaavion=aux2;
        cabezalistaavion->siguiente=NULL;
        free(aux);

    }

}


void listaavion::mostrar2(){
    ofstream grafo;
    grafo.open("grafogrande.txt",ios::app);
    grafo<<"subgraph aviones {\n";

    struct avion *s;
    struct avion *sf;
    if(cabezalistaavion==finallistaavion && cabezalistaavion==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=cabezalistaavion;
        sf= finallistaavion;

        if(s->anterior==NULL){
            grafo<<"\""<<s->tipo<<"\"";
          //  cout<<s->tipo<<endl;
            cout<<s->tipo<<","<<s->pasajeros<<","<<s->mantenimiento<<endl<<endl;

        }
        else{
            while(s->anterior!=NULL){
                 grafo<<"\""<<s->tipo<<"\""<<"->";
                cout<<s->tipo<<","<<s->pasajeros<<","<<s->mantenimiento<<endl<<endl;
                s=s->anterior;

            }
            grafo<<"\""<<s->tipo<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }
        if(sf->siguiente==NULL){
            grafo<<"\""<<sf->tipo<<"\"";
            //cout<<sf->tipo<<endl;

        }
        else{
            while(sf->siguiente!=NULL){
                 grafo<<"\""<<sf->tipo<<"\""<<"->";
                //cout<<sf->tipo<<"<->";
                sf=sf->siguiente;

            }
            grafo<<"\""<<sf->tipo<<"\"";
            grafo<<";"<<"\n";
           // cout<<sf->tipo<<endl;

        }
        grafo<<"}";

    }

    grafo.close();


}

