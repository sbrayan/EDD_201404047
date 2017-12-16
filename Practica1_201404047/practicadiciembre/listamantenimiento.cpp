#include "listamantenimiento.h"
#include <fstream>

/*listaescritorios::listaescritorios()
{

} */




Nodomantenimiento *cabemantenimiento=NULL;
Nodomantenimiento *finalmantenimiento=NULL;

Nodomantenimiento::Nodomantenimiento(int id){
    this->id=id;
    this->principioavion=NULL;
    this->siguiente=NULL;

}

void listamantenimiento::insertarnodo(int id){
    struct Nodomantenimiento *temp;
    temp=new Nodomantenimiento(id);

    if(cabemantenimiento==NULL){
        cabemantenimiento=temp;
        temp->siguiente=NULL;



    }
    else{
        struct Nodomantenimiento *aux;
        aux=cabemantenimiento;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }


        aux->siguiente=temp;
       // cabemantenimiento=temp;
        aux=NULL;
        free(aux);

    }

}

void listamantenimiento::mostrar(){
    ofstream grafo;
    grafo.open("grafogrande.txt",ios::app);
    grafo<<"subgraph estaciones {\n";
    struct Nodomantenimiento *s;

    if(cabemantenimiento==NULL)
    {
       // cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {
        s=cabemantenimiento;

        if(s->siguiente==NULL){
            grafo<<"\""<<"estacion-"<<s->id<<"\"";
            cout<<"---Estacion de servicio--"<<endl;
            cout<<"Estacion "<<s->id<<":"<<endl;
            if(s->principioavion==NULL){
               grafo<<"\""<<"estacion-"<<s->id<<"\""<<"->"<<"\""<<"NULL"<<"\""<<";";
               cout<<"     Estado: libre"<<endl;
               cout<<"     Avion en mantenimiento: ninguno"<<endl;
               cout<<"     Turnos restantes: 0"<<endl;
               cout<<"------------------------"<<endl;
            }
            else{
                grafo<<"\""<<"estacion-"<<s->id<<"\""<<"->"<<"\""<<s->principioavion->id<<"\""<<";";
                cout<<"     Estado: ocupado"<<endl;
                cout<<"     Avion en mantenimiento: "<<s->principioavion->id<<endl;
                cout<<"     Turnos restantes: "<<s->principioavion->turnos<<endl;
            }


        }
        else{
            while(s->siguiente!=NULL){
                 grafo<<"\""<<"estacion-"<<s->id<<"\""<<"->";
                //cout<<s->tipo<<"<->";
                s=s->siguiente;

            }
            grafo<<"\""<<"estacion-"<<s->id<<"\"";
            grafo<<";"<<"\n";
            //cout<<s->tipo<<endl;

        }


        grafo<<"}";

    }



    grafo.close();
   // system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafo2.txt -o grafo2.png");
}


Nodomantenimiento* listamantenimiento::devolverultimo(){

       Nodomantenimiento *aux;

       aux=cabemantenimiento;
       if(aux==NULL){

           return NULL;
       }
       if(aux->siguiente==NULL){//solo hay un elemento
           return aux;

       }

       while(aux->siguiente!=NULL){


           aux=aux->siguiente;
       }
       if(aux!=NULL){

       }

       return aux;


}

Nodomantenimiento* listamantenimiento::devolvercabeza(){
    if(cabemantenimiento==NULL){
        return NULL;
    }
    return cabemantenimiento;
}
