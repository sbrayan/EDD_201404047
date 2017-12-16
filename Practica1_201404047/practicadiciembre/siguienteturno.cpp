#include "siguienteturno.h"
#include "listaavion.h"
#include "randommetodo.h"
#include "siguientepasajero.h"
#include "listaavion2.h"
#include "listaavionespera.h"
#include "siguientepasajero.h"
#include "mainwindow.h"



#include "listamantenimiento.h"
siguienteturno::siguienteturno()
{

}
using namespace std;
int auxcantidadavion=0;
int auxcontadoraviones=0;
int sumaavion=1;
listaavion la;


listamantenimiento *lmantenimiento2;
listaavionespera *lavionespera;
listaavion2 *la2;
randommetodo rm;
siguientepasajero sp;

siguientepasajero sg;

MainWindow *consola1;


void siguienteturno ::agregaraviones(int cantidad){
int pasajeros=0;
int mantenimiento=0;

if(auxcontadoraviones==0){ //para guardar una vez el numero de aviones
     auxcantidadavion=cantidad;
     auxcontadoraviones=1;
}

if(la2->devolvercabeza()==NULL){//si esta vacia la lista de aviones se agrega


    if(auxcantidadavion==0){ //contador de aviones
      //  cout<<"sin aviones"<<endl;
        return;

    }
    else{
       int random;
       random=rm.obtenernumerorango(1,3);
       if(random==1){
           pasajeros=rm.obtenernumerorango(5,10);
           mantenimiento=rm.obtenernumerorango(1,3);

           //la.insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
           la2->insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
           // la.mostrar();
         //  cout<<"arribo avion: "<<auxcantidadavion<<" tipo P"<<","<<pasajeros<<" cantidad de pasajeros"<<endl;


           auxcantidadavion--;
           la2->devolvercabeza()->desabordaje--;
           sp.agregarpasajeroacolasimple(pasajeros);

       }
       else if(random==2){
           pasajeros=rm.obtenernumerorango(15,25);
           mantenimiento=rm.obtenernumerorango(2,4);
           //la.insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
           la2->insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
           // la.mostrar();

           auxcantidadavion--;
           la2->devolvercabeza()->desabordaje--;
           sp.agregarpasajeroacolasimple(pasajeros);

       }
       else if(random==3){
           pasajeros=rm.obtenernumerorango(30,40);
           mantenimiento=rm.obtenernumerorango(3,6);

           //la.insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
           la2->insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
           //la.mostrar();
           auxcantidadavion--;
           la2->devolvercabeza()->desabordaje--;
           sp.agregarpasajeroacolasimple(pasajeros);

       }



    }


}
else{ //si ya hay algo en la lista de aviones se agrega aqui
    Nodoavion *paraver=la2->devolvercabeza();

    if(auxcantidadavion==0 && la2->devolvercabeza()!=NULL){
        if(paraver->desabordaje==0){
            lavionespera->insertarnodo(la2->devolvercabeza()->tipo,la2->devolvercabeza()->mantenimiento);
            la2->eliminar();
            Nodoavion *paraver2= la2->devolvercabeza();
            if(paraver2==NULL){

            }
            else{
                la2->devolvercabeza()->desabordaje--;
                return;
            }

            return;
        }
        la2->devolvercabeza()->desabordaje--;
              return;
    }

    if(paraver->desabordaje==0){
         lavionespera->insertarnodo(la2->devolvercabeza()->tipo,la2->devolvercabeza()->mantenimiento);
        //ya no tiene turnos de desabordaje
        la2->eliminar();
        Nodoavion *paraver2= la2->devolvercabeza();
        if(paraver2==NULL){

        }
        else{
            la2->devolvercabeza()->desabordaje--;
            return;
        }
        return;



        if(auxcantidadavion==0){ //contador de aviones
            //cout<<"sin aviones"<<endl;
            return;

        }
        else{
           int random;
           random=rm.obtenernumerorango(1,3);
           if(random==1){


               pasajeros=rm.obtenernumerorango(5,10);
               mantenimiento=rm.obtenernumerorango(1,3);

               //la.insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
               la2->insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
               // la.mostrar();
               auxcantidadavion--;
               la2->devolvercabeza()->desabordaje--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }
           else if(random==2){


               pasajeros=rm.obtenernumerorango(15,25);
               mantenimiento=rm.obtenernumerorango(2,4);
               //la.insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
               la2->insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
               // la.mostrar();
               auxcantidadavion--;
               la2->devolvercabeza()->desabordaje--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }
           else if(random==3){


               pasajeros=rm.obtenernumerorango(30,40);
               mantenimiento=rm.obtenernumerorango(3,6);

               //la.insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
               la2->insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
               //la.mostrar();
               auxcantidadavion--;
               la2->devolvercabeza()->desabordaje--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }



        }



    }


    if(auxcantidadavion==0){ //contador de aviones
       // cout<<"sin aviones"<<endl;
        return;

    }
    else{
       int random;
       random=rm.obtenernumerorango(1,3);
       if(random==1){

           pasajeros=rm.obtenernumerorango(5,10);
           mantenimiento=rm.obtenernumerorango(1,3);

           //la.insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
           la2->insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
           // la.mostrar();
           la2->devolvercabeza()->desabordaje--;
           auxcantidadavion--;
           sp.agregarpasajeroacolasimple(pasajeros);

       }
       else if(random==2){


           pasajeros=rm.obtenernumerorango(15,25);
           mantenimiento=rm.obtenernumerorango(2,4);
           //la.insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
           la2->insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
           // la.mostrar();
            la2->devolvercabeza()->desabordaje--;
           auxcantidadavion--;
           sp.agregarpasajeroacolasimple(pasajeros);

       }
       else if(random==3){


           pasajeros=rm.obtenernumerorango(30,40);
           mantenimiento=rm.obtenernumerorango(3,6);

           //la.insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
           la2->insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
           //la.mostrar();
           la2->devolvercabeza()->desabordaje--;
           auxcantidadavion--;
           sp.agregarpasajeroacolasimple(pasajeros);

       }



    }


}



}


void siguienteturno::agregaraviones2(int cantidad){

    int pasajeros=0;
    int mantenimiento=0;

    if(auxcontadoraviones==0){ //para guardar una vez el numero de aviones
         auxcantidadavion=cantidad;
         auxcontadoraviones=1;
    }

    if(la2->devolvercabeza()==NULL){//si esta vacia la lista de aviones se agrega


        if(auxcantidadavion==0){ //contador de aviones
            //cout<<"sin aviones"<<endl;
            return;

        }
        else{
           int random;
           random=rm.obtenernumerorango(1,3);
           if(random==1){
               pasajeros=rm.obtenernumerorango(5,10);
               mantenimiento=rm.obtenernumerorango(1,3);

               //la.insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
               la2->insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
               // la.mostrar();
               auxcantidadavion--;

               la2->devolvercabeza()->desabordaje--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }
           else if(random==2){
               pasajeros=rm.obtenernumerorango(15,25);
               mantenimiento=rm.obtenernumerorango(2,4);
               //la.insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
               la2->insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
               // la.mostrar();
               auxcantidadavion--;
               la2->devolvercabeza()->desabordaje--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }
           else if(random==3){
               pasajeros=rm.obtenernumerorango(30,40);
               mantenimiento=rm.obtenernumerorango(3,6);

               //la.insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
               la2->insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
               //la.mostrar();
               auxcantidadavion--;
               la2->devolvercabeza()->desabordaje--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }



        }


    }
    else{ //si ya hay algo en la lista de aviones se agrega aqui

        if(auxcantidadavion==0 && la2->devolvercabeza()!=NULL){
            if(la2->devolvercabeza()->desabordaje==0){
                lavionespera->insertarnodo(la2->devolvercabeza()->tipo,la2->devolvercabeza()->mantenimiento);
                la2->eliminar();

                return;
            }
            la2->devolvercabeza()->desabordaje--;
                  return;
        }

        if(la2->devolvercabeza()->desabordaje==0){
             lavionespera->insertarnodo(la2->devolvercabeza()->tipo,la2->devolvercabeza()->mantenimiento);
            //ya no tiene turnos de desabordaje
            la2->eliminar();



            if(auxcantidadavion==0){ //contador de aviones
              //  cout<<"sin aviones"<<endl;
                return;

            }
            else{
               int random;
               random=rm.obtenernumerorango(1,3);
               if(random==1){


                   pasajeros=rm.obtenernumerorango(5,10);
                   mantenimiento=rm.obtenernumerorango(1,3);

                   //la.insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
                   la2->insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
                   // la.mostrar();
                   auxcantidadavion--;
                   la2->devolvercabeza()->desabordaje--;
                   sp.agregarpasajeroacolasimple(pasajeros);

               }
               else if(random==2){


                   pasajeros=rm.obtenernumerorango(15,25);
                   mantenimiento=rm.obtenernumerorango(2,4);
                   //la.insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
                   la2->insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
                   // la.mostrar();
                   auxcantidadavion--;
                   la2->devolvercabeza()->desabordaje--;
                   sp.agregarpasajeroacolasimple(pasajeros);

               }
               else if(random==3){


                   pasajeros=rm.obtenernumerorango(30,40);
                   mantenimiento=rm.obtenernumerorango(3,6);

                   //la.insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
                   la2->insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
                   //la.mostrar();
                   auxcantidadavion--;
                   la2->devolvercabeza()->desabordaje--;
                   sp.agregarpasajeroacolasimple(pasajeros);

               }



            }



        }


        if(auxcantidadavion==0){ //contador de aviones
           // cout<<"sin aviones"<<endl;
            return;

        }
        else{
           int random;
           random=rm.obtenernumerorango(1,3);
           if(random==1){

               pasajeros=rm.obtenernumerorango(5,10);
               mantenimiento=rm.obtenernumerorango(1,3);

               //la.insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
               la2->insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
               // la.mostrar();
               la2->devolvercabeza()->desabordaje--;
               auxcantidadavion--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }
           else if(random==2){


               pasajeros=rm.obtenernumerorango(15,25);
               mantenimiento=rm.obtenernumerorango(2,4);
               //la.insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
               la2->insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
               // la.mostrar();
                la2->devolvercabeza()->desabordaje--;
               auxcantidadavion--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }
           else if(random==3){


               pasajeros=rm.obtenernumerorango(30,40);
               mantenimiento=rm.obtenernumerorango(3,6);

               //la.insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
               la2->insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
               //la.mostrar();
               la2->devolvercabeza()->desabordaje--;
               auxcantidadavion--;
               sp.agregarpasajeroacolasimple(pasajeros);

           }



        }


    }


}




void siguienteturno::agregarestaciones(int cantidad){
    for(int i=1;i<=cantidad;i++){
        lmantenimiento2->insertarnodo(i);
        //lmantenimiento.insertarnodo(i,0,0,0);
    }

}



void siguienteturno::generargrafogrande(){


    ofstream grafo;
    grafo.open("grafogrande.txt");
    grafo<<"digraph G {\n";

    grafo.close();
    la2->mostrar();
    //la.mostrar2();
    lmantenimiento2->mostrar();
    lavionespera->mostrar();
    sg.hacergrafogrande();

    grafo.open("grafogrande.txt",ios::app);

        grafo<<"}";


    grafo.close();
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafogrande.txt -o grafogrande.png");
}

void siguienteturno::pruebaeliminar(){
    lavionespera->eliminar();
}

void siguienteturno::agregaravionesamantenimiento(){

    Nodoavionespera *auxavionespera = lavionespera->devolvercabeza();
    Nodomantenimiento *auxmantenimiento = lmantenimiento2->devolvercabeza();

    if(auxmantenimiento!=NULL){
        if(auxavionespera!=NULL){
            if(auxmantenimiento->siguiente==NULL){//quiere decir que solo hay una stacion
                if(auxmantenimiento->principioavion!=NULL){
                    if(auxmantenimiento->principioavion->turnos!=0){
                        auxmantenimiento->principioavion->turnos--;

                    }
                    else{
                        auxmantenimiento->principioavion=NULL;

                    }

                }
                else{
                    //principio de avion es null
                    Nodoavionespera *auxinsertar= lavionespera->devolvercabeza();
                    lavionespera->eliminar();
                    if(auxinsertar->siguiente!=NULL){
                        auxinsertar->siguiente=NULL;
                    }

                    auxmantenimiento->principioavion=auxinsertar;


                }
            }
            else{

            }


        }
        else{
         //   cout<<"no hay nada en lista de espera de aviones"<<endl;
            //otra validaciones para ver si hay algo en las estaciones

            if(auxmantenimiento->siguiente==NULL){//quiere decir que solo hay una stacion
                if(auxmantenimiento->principioavion!=NULL){
                    if(auxmantenimiento->principioavion->turnos!=0){
                        auxmantenimiento->principioavion->turnos--;

                    }
                    else{
                        auxmantenimiento->principioavion=NULL;

                    }

                }
                else{
                    //principio de avion es null
                    //auxmantenimiento->principioavion=devolvercabeza();
                    //lavionespera->eliminar();
                    return;

                }
            }

        }

    }
    else{
       // cout<<"no hay estaciones de mantenimiento"<<endl;
        return;

    }







}
