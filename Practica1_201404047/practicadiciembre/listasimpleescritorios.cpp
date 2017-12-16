#include "listasimpleescritorios.h"
#include <fstream>

/*listasimpleescritorios::listasimpleescritorios()
{

} */


using namespace std;
Nodosimpleescri *iniciosimpleescritorios=NULL;
Nodosimpleescri *finalsimpleescritorios=NULL;

Nodosimpleescri::Nodosimpleescri(int identificacion,int maletas,int documentos,int turnos){
   // this->id=nombre;
    this->identificacion=identificacion;
    this->maletas=maletas;
    this->documentos=documentos;
    this->turnos=turnos;

    this->siguiente=NULL;

}


void listasimpleescri::insertarnodo(int identificacion,int maletas,int documentos,int turnos){
    struct Nodosimpleescri *temp;
     temp= new Nodosimpleescri(identificacion,maletas,documentos,turnos);
    //temp=crearnodo(id,identificacion,maletas,documentos,turnos);

    if(iniciosimpleescritorios==finalsimpleescritorios && iniciosimpleescritorios==NULL){
        iniciosimpleescritorios=temp;
        finalsimpleescritorios=temp;
        temp->siguiente=NULL;



    }
    else{
        struct Nodosimpleescri *aux;
        aux=finalsimpleescritorios;
        finalsimpleescritorios=temp;
        finalsimpleescritorios->siguiente=aux;
       // finallistaavion->anterior=NULL;
        //aux->anterior=finallistaavion;
        aux=NULL;
        free(aux);

    }
}



void listasimpleescri:: mostrar()
{


    ofstream grafo;
    grafo.open("grafoespera.txt");
    grafo<<"digraph G {\n";


    struct Nodosimpleescri *s;

    if(iniciosimpleescritorios==finalsimpleescritorios && iniciosimpleescritorios==NULL)
    {
       // cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=finalsimpleescritorios;


        if(s->siguiente==NULL){
            grafo<<"\""<<s->identificacion<<"\"";
          //  cout<<s->tipo<<endl;

        }
        else{
            while(s->siguiente!=NULL){
                 grafo<<"\""<<s->identificacion<<"\""<<"->";
                //cout<<s->tipo<<"<->";
                s=s->siguiente;

            }
            grafo<<"\""<<s->identificacion<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }

        grafo<<"}";

    }

    grafo.close();
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafoespera.txt -o grafoespera.png");



}


void listasimpleescri::grafogrande(){


    ofstream grafo;
    grafo.open("grafogrande.txt",ios::app);
    grafo<<"subgraph filaespera {\n";


    struct Nodosimpleescri *s;

    if(iniciosimpleescritorios==finalsimpleescritorios && iniciosimpleescritorios==NULL)
    {
       // cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=finalsimpleescritorios;


        if(s->siguiente==NULL){
            grafo<<"\""<<s->identificacion<<"\"";
          //  cout<<s->tipo<<endl;

        }
        else{
            while(s->siguiente!=NULL){
                 grafo<<"\""<<s->identificacion<<"\""<<"->";
                //cout<<s->tipo<<"<->";
                s=s->siguiente;

            }
            grafo<<"\""<<s->identificacion<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }

        grafo<<"}";

    }

    grafo.close();
   // system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafoespera.txt -o grafoespera.png");
}


void listasimpleescri::eliminar(){
    struct Nodosimpleescri *aux;
    struct Nodosimpleescri *aux2;
    struct Nodosimpleescri *aux3;
    aux=iniciosimpleescritorios;
    aux3=finalsimpleescritorios;



   if(aux==aux3){
        iniciosimpleescritorios=NULL;
        finalsimpleescritorios=NULL;
        //free(aux);
    }
    else{

        while(aux3->siguiente->siguiente!=NULL){
            aux3=aux3->siguiente;
        }
        aux2=aux3;
        //cout<<aux2->identificacion<<endl;
        iniciosimpleescritorios=aux2;
        iniciosimpleescritorios->siguiente=NULL;
        //free(aux);

    }

}

Nodosimpleescri * listasimpleescri::devolvercabeza(){
    if(iniciosimpleescritorios==NULL){
        return NULL;
    }
    return iniciosimpleescritorios;
}

