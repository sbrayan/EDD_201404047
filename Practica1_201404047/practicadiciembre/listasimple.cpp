#include "listasimple.h"


listasimple::listasimple()
{

}

using namespace std;
struct nodosimple{
    int identificacion;
    int maletas;
    int documentos;
    int turnos;
    struct nodosimple *siguiente;

}*cabezasimple=NULL, *finalsimple=NULL;


nodosimple* listasimple::crearnodo(int identificacion,int maletas,int documentos,int turnos)
{
    struct nodosimple *tmp;
    tmp= new (struct nodosimple);
    tmp->identificacion=identificacion;
    tmp->maletas=maletas;
    tmp->documentos=documentos;
    tmp->turnos=turnos;
    tmp->siguiente=NULL;
    return tmp;


}

nodosimple* listasimple::insertarnodo(int identificacion,int maletas,int documentos,int turnos){
    struct nodosimple *temp;
    temp=crearnodo(identificacion,maletas,documentos,turnos);

    if(cabezasimple==finalsimple && cabezasimple==NULL){
        cabezasimple=temp;
        finalsimple=temp;
        temp->siguiente=NULL;



    }
    else{
        struct nodosimple *aux;
        aux=finalsimple;
        finalsimple=temp;
        finalsimple->siguiente=aux;
       // finallistaavion->anterior=NULL;
        //aux->anterior=finallistaavion;
        aux=NULL;
        free(aux);

    }

}



void listasimple:: mostrar()
{


    ofstream grafo;
    grafo.open("grafogrande.txt",ios::app);
    grafo<<"subgraph estaciones {\n";

    struct nodosimple *s;

    if(cabezasimple==finalsimple && cabezasimple==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=finalsimple;


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
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafo2.txt -o grafo2.png");



}


void listasimple::mostrarmantenimiento(){

        ofstream grafo;
        grafo.open("grafogrande.txt",ios::app);
        grafo<<"subgraph estaciones {\n";
        struct nodosimple *s;

        if(cabezasimple==finalsimple && cabezasimple==NULL)
        {
            cout<<"la lista esta vacia"<<endl;
            grafo<<"}";
          //  return;
        }
        else {
            s=finalsimple;


            if(s->siguiente==NULL){
                grafo<<"\""<<"estacion-"<<s->identificacion<<"\"";
              //  cout<<s->tipo<<endl;

            }
            else{
                while(s->siguiente!=NULL){
                     grafo<<"\""<<"estacion-"<<s->identificacion<<"\""<<"->";
                    //cout<<s->tipo<<"<->";
                    s=s->siguiente;

                }
                grafo<<"\""<<"estacion-"<<s->identificacion<<"\"";
                grafo<<";"<<"\n";
                //cout<<s->tipo<<endl;

            }

            grafo<<"}";

        }

        grafo.close();
       // system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafo2.txt -o grafo2.png");





}




void listasimple::eliminar(){
    struct nodosimple *aux;
    struct nodosimple *aux2;
    struct nodosimple *aux3;
    aux=cabezasimple;
    aux3=finalsimple;



   if(aux==aux3){
        cabezasimple=NULL;
        finalsimple=NULL;
        free(aux);
    }
    else{

        while(aux3->siguiente->siguiente!=NULL){
            aux3=aux3->siguiente;
        }
        aux2=aux3;
        //cout<<aux2->identificacion<<endl;
        cabezasimple=aux2;
        cabezasimple->siguiente=NULL;
        free(aux);

    }

}
