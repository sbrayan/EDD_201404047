#include <fstream>
#include "listaavion2.h"

/*listaavion2::listaavion2()
{

} */



using namespace std;
Nodoavion *cabezaavion=NULL;
Nodoavion *finalavion=NULL;

Nodoavion::Nodoavion(string tipo,int pasajeros,int desabordaje,int mantenimiento){
    this->tipo=tipo;
    this->pasajeros=pasajeros;
    this->desabordaje=desabordaje;
    this->mantenimiento=mantenimiento;

    this->siguiente=NULL;
    this->anterior=NULL;

}

void listaavion2::insertarnodo(string tipo, int pasajeros, int desabordaje, int mantenimiento){



    struct Nodoavion *temp;
    temp=new Nodoavion(tipo,pasajeros,desabordaje,mantenimiento);

    if(cabezaavion==NULL && finalavion==NULL){
        cabezaavion=temp;
        finalavion=temp;
        temp->siguiente=NULL;
        temp->anterior=NULL;


    }
    else{
        struct Nodoavion *aux;
        aux=finalavion;
        finalavion=temp;
        finalavion->siguiente=aux;
        finalavion->anterior=NULL;
        aux->anterior=finalavion;
        aux=NULL;
        free(aux);

    }

}


void listaavion2::mostrar(){
    ofstream grafo;
    grafo.open("grafogrande.txt",ios::app);
    grafo<<"subgraph aviones {\n";

    struct Nodoavion *s;
    struct Nodoavion *sf;
    if(cabezaavion==finalavion && cabezaavion==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=cabezaavion;
        sf= finalavion;

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


void listaavion2::eliminar(){
    struct  Nodoavion *aux;
    struct Nodoavion *aux2;
    struct Nodoavion *aux3;
    aux=cabezaavion;
    aux3=finalavion;



   if(aux==aux3){
        cabezaavion=NULL;
        finalavion=NULL;
        free(aux);
    }
    else{

        aux2=aux->anterior;
        cabezaavion=aux2;
        cabezaavion->siguiente=NULL;
        free(aux);

    }

}

Nodoavion *listaavion2::devolvercabeza(){
    if(cabezaavion==NULL){
        return NULL;
    }
    return cabezaavion;
}
