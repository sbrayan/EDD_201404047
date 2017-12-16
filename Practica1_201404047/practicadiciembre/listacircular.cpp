#include "listacircular.h"

listacircular::listacircular()
{

}

using namespace std;
struct nodocircular{
    int id;
    struct nodocircular *siguiente;
    struct nodocircular *anterior;
}*cabezacircular=NULL,*finalcircular=NULL;

int contadorcircular=0;
int auxnumeromaleta=1;

nodocircular* listacircular::crearnodo(int id)
{
    struct nodocircular *tmp;
    tmp= new (struct nodocircular);
    tmp->id=id;
    tmp->siguiente=NULL;
    tmp->anterior=NULL;
    contadorcircular++;
    return tmp;


}


void listacircular::insertarnodo2(int cantidad){
    for(int i=0;i<cantidad;i++){
        insertarnodo(auxnumeromaleta);
        auxnumeromaleta++;
    }

}

nodocircular* listacircular::insertarnodo(int id){
    struct nodocircular *temp;
    temp=crearnodo(id);

    if(cabezacircular==NULL && finalcircular==NULL){
        cabezacircular=temp;
        finalcircular=temp;
        temp->siguiente=temp;
        temp->anterior=temp;


    }
    else{
        struct nodocircular *aux1=cabezacircular;
        struct nodocircular *aux2=finalcircular;
        if(aux1==aux2){
            cabezacircular=temp;
            finalcircular->siguiente=temp;
            temp->anterior=finalcircular;
            temp->siguiente=finalcircular;
            finalcircular->anterior=temp;
        }
        else{
            cabezacircular=temp;
            temp->anterior=aux1;
            aux1->siguiente=temp;
            temp->siguiente=finalcircular;
            finalcircular->anterior=temp;
        }

    }


}



void listacircular:: mostrar()
{
    ofstream grafo;
    grafo.open("grafocircular.txt");
    grafo<<"digraph G {\n";


    struct nodocircular *s;
    struct nodocircular *sf;
    if(cabezacircular==finalcircular && cabezacircular==NULL)
    {
        cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=cabezacircular;
        sf= finalcircular;
        int auxcontador=contadorcircular;

        for(int i=0;i<=contadorcircular;i++){
            if(i==auxcontador){
                grafo<<"\""<<s->id<<"\"";
                s=s->anterior;
            }
            else{
                grafo<<"\""<<s->id<<"\""<<"->";
                s=s->anterior;
            }

        }
        grafo<<";";
        grafo<<"\n";

        for(int i=0;i<=contadorcircular;i++){

            if(auxcontador==i){
                grafo<<"\""<<sf->id<<"\"";
                sf=sf->siguiente;
            }
            else{
                grafo<<"\""<<sf->id<<"\""<<"->";
                sf=sf->siguiente;
            }

        }
        grafo<<";";
        grafo<<"\n";
        grafo<<"}";

    }

    grafo.close();
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafocircular.txt -o grafocircular.png");



}


void listacircular::eliminar(int cantidad){
    for(int i=0;i<cantidad;i++){
        eliminar();
    }

}

void listacircular::eliminar(){
    struct nodocircular *aux1;
    struct nodocircular *aux2;
    aux1=cabezacircular;
    aux2=finalcircular;


    if(aux1==aux2){
        cabezacircular=NULL;
        finalcircular=NULL;
        free(aux1);
        free(aux2);
        contadorcircular--;
    }
   /* else if(aux2->siguiente==aux1){

        contadorcircular--;
    }*/
    else{
        struct nodocircular *auxeliminar;
        struct nodocircular *auxanterior;
        auxanterior=aux2->siguiente;
        auxanterior->anterior=cabezacircular;
        cabezacircular->siguiente=auxanterior;
        finalcircular=auxanterior;
        contadorcircular--;



    }
}
