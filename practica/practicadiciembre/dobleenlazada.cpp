#include "dobleenlazada.h"
#include <fstream>

dobleenlazada::dobleenlazada()
{

}

using namespace std;


struct doble{
   string id;
   struct nodopila *iniciopila=NULL;
   struct nodosimple *iniciolista=NULL;
   struct doble *siguiente;
   struct doble *anterior;
} *cabezadoble=NULL,*finaldoble=NULL;



doble* dobleenlazada::crearnodo(string id)
{
    struct doble *tmp;
    tmp= new (struct doble);
    tmp->id=id;
    tmp->iniciolista=NULL;
    tmp->iniciopila=NULL;
    tmp->siguiente=NULL;
    tmp->anterior=NULL;
    return tmp;

}

doble* dobleenlazada::insertarnodo(string tipo){
    struct doble *temp;
    temp=crearnodo(tipo);

    if(cabezadoble==NULL && finaldoble==NULL){
        cabezadoble=temp;
        finaldoble=temp;
        temp->siguiente=NULL;
        temp->anterior=NULL;


    }
    else{
        struct doble *aux;
        aux=finaldoble;
        finaldoble=temp;
        finaldoble->siguiente=aux;
        finaldoble->anterior=NULL;
        aux->anterior=finaldoble;
        aux=NULL;
        free(aux);

    }


}




void dobleenlazada:: mostrar()
{


    ofstream grafo;
    grafo.open("grafoescritorios.txt");
    grafo<<"digraph G {\n";


    struct doble *s;
    struct doble *sf;
    if(cabezadoble==finaldoble && cabezadoble==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";

      //  return;
    }
    else {
        s=cabezadoble;
        sf= finaldoble;

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


void dobleenlazada::eliminar(){
    struct doble *aux;
    struct doble *aux2;
    struct doble *aux3;
    aux=cabezadoble;
    aux3=finaldoble;



   if(aux==aux3){
        cabezadoble=NULL;
        finaldoble=NULL;
        free(aux);
    }
    else{

        aux2=aux->anterior;
        cabezadoble=aux2;
        cabezadoble->siguiente=NULL;
        free(aux);

    }

}

doble * dobleenlazada::retornarinicioescritorios(){
    if(cabezadoble==NULL){
        return NULL;
    }
    return cabezadoble;
}
