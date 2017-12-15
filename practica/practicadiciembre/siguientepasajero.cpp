#include "siguientepasajero.h"
#include "randommetodo.h"
#include "dobleenlazada.h"
#include "dobleenlazada2.h"
#include "listasimpleescritorios.h"

#include <iostream>
using namespace std;

siguientepasajero::siguientepasajero()
{

}
listasimple listapasajeros;
//listasimple *listapasajeros2;
dobleenlazada listaescritorios;
listaenlazada *listaescritorios2;
listasimpleescri *listapasajeros2;
randommetodo ranm;
int auxidentificacion=1;
//**********************


void siguientepasajero::agregarpasajeroacolasimple(int cantidad){

    for(int i=0;i<cantidad;i++){
       //listapasajeros.insertarnodo(auxidentificacion,ranm.obtenernumerorango(1,4),ranm.obtenernumerorango(1,10),ranm.obtenernumerorango(1,3));
        listapasajeros2->insertarnodo(auxidentificacion,ranm.obtenernumerorango(1,4),ranm.obtenernumerorango(1,10),ranm.obtenernumerorango(1,3));
        auxidentificacion++;


    }
    // listapasajeros.mostrar();
     listapasajeros2->mostrar();
}

void siguientepasajero::agregarescritorios(int cantidadescritorios){
    for(int i=0;i<cantidadescritorios;i++){
        if(i==0){
           // listaescritorios.insertarnodo("A");
            listaescritorios2->insertarnodo("A");

        }
        else if(i==1){
             //listaescritorios.insertarnodo("B");
             listaescritorios2->insertarnodo("B");

        }
        else if(i==2){
            // listaescritorios.insertarnodo("C");
             listaescritorios2->insertarnodo("C");

        }
        else if(i==3){
             //listaescritorios.insertarnodo("D");
             listaescritorios2->insertarnodo("D");

        }
        else if(i==4){
            // listaescritorios.insertarnodo("E");
             listaescritorios2->insertarnodo("E");

        }
        else if(i==5){
           //  listaescritorios.insertarnodo("F");
             listaescritorios2->insertarnodo("F");

        }
        else if(i==6){
            // listaescritorios.insertarnodo("G");
             listaescritorios2->insertarnodo("G");

        }
        else if(i==7){
             listaescritorios.insertarnodo("H");

        }
        else if(i==8){
             listaescritorios.insertarnodo("I");

        }
        else if(i==9){
             listaescritorios.insertarnodo("J");

        }
        else if(i==10){
             listaescritorios.insertarnodo("K");

        }
        else if(i==11){
             listaescritorios.insertarnodo("L");

        }
        else if(i==12){
             listaescritorios.insertarnodo("M");

        }
        else if(i==13){
             listaescritorios.insertarnodo("N");

        }
        else if(i==14){
             listaescritorios.insertarnodo("O");

        }
        else if(i==15){
             listaescritorios.insertarnodo("P");

        }
        else if(i==16){
             listaescritorios.insertarnodo("Q");

        }
        else if(i==17){
             listaescritorios.insertarnodo("R");

        }
        else if(i==18){
             listaescritorios.insertarnodo("S");

        }
        else if(i==19){
             listaescritorios.insertarnodo("T");

        }
        else if(i==20){
             listaescritorios.insertarnodo("U");

        }
        else if(i==21){
             listaescritorios.insertarnodo("V");

        }
        else if(i==22){
             listaescritorios.insertarnodo("W");

        }
        else if(i==23){
             listaescritorios.insertarnodo("X");

        }
        else if(i==24){
             listaescritorios.insertarnodo("Y");

        }
        else if(i==25){
             listaescritorios.insertarnodo("Z");

        }

    }
   // listaescritorios.mostrar();
    listaescritorios2->mostrar();

}

void siguientepasajero::moverpasajeros(){
  struct Nodoenlazada *aux= listaescritorios2->devolvercabeza();
  struct Nodoenlazada *auxinicioescritorio = aux;

  //  struct nodosimple *aux;



    if(auxinicioescritorio==NULL){
        cout<<"no hay escritorios, esta vacio";

    }
    else{
        if(auxinicioescritorio->anterior==NULL){ //solo hay un escritorio
           if(auxinicioescritorio->iniciolista==NULL){//si no hay lista aun
               auxinicioescritorio->iniciolista=listapasajeros2->devolvercabeza();
               listapasajeros2->eliminar();


              while(auxinicioescritorio->contador!=9){
                  auxinicioescritorio->contador= auxinicioescritorio->contador+1;
                  if(listapasajeros2->devolvercabeza()==NULL){
                      break;
                      cout<<"ya no hay nadie en la lista"<<endl;
                  }
                  else{
                      struct Nodosimpleescri *comi;
                      comi=auxinicioescritorio->iniciolista;
                      if(comi->siguiente==NULL){
                          comi->siguiente= listapasajeros2->devolvercabeza();
                         listapasajeros2->eliminar();
                      }
                      else{
                          while(comi->siguiente!=NULL){
                              comi=comi->siguiente;
                          }
                          comi->siguiente=listapasajeros2->devolvercabeza();
                          listapasajeros2->eliminar();
                      }
                  }
              }
           }
           else{ //si solo hay un escritorio y hay algo en la lista



               while(auxinicioescritorio->contador!=9){
                   auxinicioescritorio->contador= auxinicioescritorio->contador+1;
                   if(listapasajeros2->devolvercabeza()==NULL){
                       break;
                       cout<<"ya no hay nadie en la lista"<<endl;
                   }
                   else{
                       struct Nodosimpleescri *comi;
                       comi=auxinicioescritorio->iniciolista;
                       if(comi->siguiente==NULL){
                           comi->siguiente= listapasajeros2->devolvercabeza();
                          listapasajeros2->eliminar();
                       }
                       else{
                           while(comi->siguiente!=NULL){
                               comi=comi->siguiente;
                           }
                           comi->siguiente=listapasajeros2->devolvercabeza();
                           listapasajeros2->eliminar();
                       }
                   }
               }

           }


        }


        while(auxinicioescritorio->anterior!=NULL){ //hay varios escritorios
            if(listapasajeros2->devolvercabeza()==NULL){
                cout<<"ya no hay naadie en la lista de espera"<<endl;
                break;
            }
            else{

                if(auxinicioescritorio->iniciolista==NULL){//si no hay lista aun
                    auxinicioescritorio->iniciolista=listapasajeros2->devolvercabeza();
                    listapasajeros2->eliminar();


                   while(auxinicioescritorio->contador!=9){
                       auxinicioescritorio->contador= auxinicioescritorio->contador+1;
                       if(listapasajeros2->devolvercabeza()==NULL){
                           break;
                           cout<<"ya no hay nadie en la lista"<<endl;
                       }
                       else{
                           struct Nodosimpleescri *comi;
                           comi=auxinicioescritorio->iniciolista;
                           if(comi->siguiente==NULL){
                               comi->siguiente= listapasajeros2->devolvercabeza();
                              listapasajeros2->eliminar();
                           }
                           else{
                               while(comi->siguiente!=NULL){
                                   comi=comi->siguiente;
                               }
                               comi->siguiente=listapasajeros2->devolvercabeza();
                               listapasajeros2->eliminar();
                           }
                       }
                   }
                }
                else{ //si solo hay un escritorio y hay algo en la lista



                    while(auxinicioescritorio->contador!=9){
                        auxinicioescritorio->contador= auxinicioescritorio->contador+1;
                        if(listapasajeros2->devolvercabeza()==NULL){
                            break;
                            cout<<"ya no hay nadie en la lista"<<endl;
                        }
                        else{
                            struct Nodosimpleescri *comi;
                            comi=auxinicioescritorio->iniciolista;
                            if(comi->siguiente==NULL){
                                comi->siguiente= listapasajeros2->devolvercabeza();
                               listapasajeros2->eliminar();
                            }
                            else{
                                while(comi->siguiente!=NULL){
                                    comi=comi->siguiente;
                                }
                                comi->siguiente=listapasajeros2->devolvercabeza();
                                listapasajeros2->eliminar();
                            }
                        }
                    }

                }





            }


            auxinicioescritorio=auxinicioescritorio->anterior;

        }
        //ultimo escritorio

        if(listapasajeros2->devolvercabeza()==NULL){
            cout<<"ya no hay naadie en la lista de espera"<<endl;
           // break;
        }
        else{

            if(auxinicioescritorio->iniciolista==NULL){//si no hay lista aun
                auxinicioescritorio->iniciolista=listapasajeros2->devolvercabeza();
                listapasajeros2->eliminar();


               while(auxinicioescritorio->contador!=9){
                   auxinicioescritorio->contador= auxinicioescritorio->contador+1;
                   if(listapasajeros2->devolvercabeza()==NULL){
                       break;
                       cout<<"ya no hay nadie en la lista"<<endl;
                   }
                   else{
                       struct Nodosimpleescri *comi;
                       comi=auxinicioescritorio->iniciolista;
                       if(comi->siguiente==NULL){
                           comi->siguiente= listapasajeros2->devolvercabeza();
                          listapasajeros2->eliminar();
                       }
                       else{
                           while(comi->siguiente!=NULL){
                               comi=comi->siguiente;
                           }
                           comi->siguiente=listapasajeros2->devolvercabeza();
                           listapasajeros2->eliminar();
                       }
                   }
               }
            }
            else{ //si solo hay un escritorio y hay algo en la lista



                while(auxinicioescritorio->contador!=9){
                    auxinicioescritorio->contador= auxinicioescritorio->contador+1;
                    if(listapasajeros2->devolvercabeza()==NULL){
                       break;
                        cout<<"ya no hay nadie en la lista"<<endl;
                    }
                    else{
                        struct Nodosimpleescri *comi;
                        comi=auxinicioescritorio->iniciolista;
                        if(comi->siguiente==NULL){
                            comi->siguiente= listapasajeros2->devolvercabeza();
                           listapasajeros2->eliminar();
                        }
                        else{
                            while(comi->siguiente!=NULL){
                                comi=comi->siguiente;
                            }
                            comi->siguiente=listapasajeros2->devolvercabeza();
                            listapasajeros2->eliminar();
                        }
                    }
                }

            }





        }




    }


listapasajeros2->mostrar();
}

/* struct Nodosimpleescri *auxpintar;
 auxpintar=auxinicioescritorio->iniciolista;
 while(auxpintar->siguiente!=NULL){
     cout<<auxpintar->identificacion<<endl;
     auxpintar=auxpintar->siguiente;

 }
 cout<<auxpintar->identificacion<<endl;
 listapasajeros2->mostrar(); */

