#include "siguientepasajero.h"
#include "randommetodo.h"
#include "dobleenlazada.h"
#include "dobleenlazada2.h"
#include "listasimpleescritorios.h"
#include "listacircular.h"

#include <iostream>
#include <fstream>
using namespace std;

siguientepasajero::siguientepasajero()
{

}

listacircular lcircu2;
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
        int auxmaletas= ranm.obtenernumerorango(1,4);
       //listapasajeros.insertarnodo(auxidentificacion,ranm.obtenernumerorango(1,4),ranm.obtenernumerorango(1,10),ranm.obtenernumerorango(1,3));
        listapasajeros2->insertarnodo(auxidentificacion,auxmaletas,ranm.obtenernumerorango(1,10),ranm.obtenernumerorango(1,3));
        lcircu2.insertarnodo2(auxmaletas);
        auxidentificacion++;


    }
    // listapasajeros.mostrar();
     listapasajeros2->mostrar();
     lcircu2.mostrar();
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
             listaescritorios2->insertarnodo("H");

        }
        else if(i==8){
             listaescritorios2->insertarnodo("I");

        }
        else if(i==9){
             listaescritorios2->insertarnodo("J");

        }
        else if(i==10){
             listaescritorios2->insertarnodo("K");

        }
        else if(i==11){
             listaescritorios2->insertarnodo("L");

        }
        else if(i==12){
             listaescritorios2->insertarnodo("M");

        }
        else if(i==13){
             listaescritorios2->insertarnodo("N");

        }
        else if(i==14){
             listaescritorios2->insertarnodo("O");

        }
        else if(i==15){
             listaescritorios2->insertarnodo("P");

        }
        else if(i==16){
             listaescritorios2->insertarnodo("Q");

        }
        else if(i==17){
             listaescritorios2->insertarnodo("R");

        }
        else if(i==18){
             listaescritorios2->insertarnodo("S");

        }
        else if(i==19){
             listaescritorios2->insertarnodo("T");

        }
        else if(i==20){
             listaescritorios2->insertarnodo("U");

        }
        else if(i==21){
             listaescritorios2->insertarnodo("V");

        }
        else if(i==22){
             listaescritorios2->insertarnodo("W");

        }
        else if(i==23){
             listaescritorios2->insertarnodo("X");

        }
        else if(i==24){
             listaescritorios2->insertarnodo("Y");

        }
        else if(i==25){
             listaescritorios2->insertarnodo("Z");

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
       // cout<<"no hay escritorios, esta vacio";

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
                      //cout<<"ya no hay nadie en la lista"<<endl;
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
                       //cout<<"ya no hay nadie en la lista"<<endl;
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
                //cout<<"ya no hay naadie en la lista de espera"<<endl;
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
                          // cout<<"ya no hay nadie en la lista"<<endl;
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
                           // cout<<"ya no hay nadie en la lista"<<endl;
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
           // cout<<"ya no hay naadie en la lista de espera"<<endl;
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
                      // cout<<"ya no hay nadie en la lista"<<endl;
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
                       // cout<<"ya no hay nadie en la lista"<<endl;
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


void siguientepasajero::moverpasajeros2(){
    Nodosimpleescri *auxpasajeros = listapasajeros2->devolvercabeza();
    Nodoenlazada *auxinicioescritorios= listaescritorios2->devolvercabeza();
    if(auxinicioescritorios!=NULL){ //mientrasa hayan escritorios
        if(auxpasajeros!=NULL){//mientras haya algo en la lista y si hay escritorios

            while(auxinicioescritorios!=NULL){
                if(auxinicioescritorios->iniciolista==NULL){//no hay nada en la lista

                    auxinicioescritorios->iniciolista=listapasajeros2->devolvercabeza();
                    listapasajeros2->eliminar();
                    Nodosimpleescri *auxpasa2 = listapasajeros2->devolvercabeza();
                    int contaaux=1;


                    while(auxpasa2!=NULL){
                        if(contaaux==10){
                            break;
                        }
                        else{
                            Nodosimpleescri *auxcabepasa = auxinicioescritorios->iniciolista;
                            Nodosimpleescri *auxcabepasa2=auxcabepasa;


                            if(auxcabepasa->siguiente==NULL){
                                auxcabepasa->siguiente=auxpasa2;
                                listapasajeros2->eliminar();
                                auxpasa2=listapasajeros2->devolvercabeza();
                                contaaux=contaaux+1;

                            }
                            else{
                                while(auxcabepasa2->siguiente!=NULL){
                                    auxcabepasa2=auxcabepasa2->siguiente;
                                }
                                auxcabepasa2->siguiente=auxpasa2;
                                listapasajeros2->eliminar();
                                contaaux=contaaux+1;
                                auxpasa2=listapasajeros2->devolvercabeza();

                            }
                        }


                    }

                }
                else{// ya hay algo en la lista pero quiza hayan espacios
                    Nodosimpleescri *auxpasa2 = listapasajeros2->devolvercabeza();
                    Nodosimpleescri *auxinicioescritorios3 =auxinicioescritorios->iniciolista;
                    Nodosimpleescri *auxinicioescritorios4 =auxinicioescritorios3;
                    int contadorpersonas=0;
                    while(auxinicioescritorios4!=NULL){ //para saber cantidd de personas
                        contadorpersonas=contadorpersonas+1;
                        auxinicioescritorios4=auxinicioescritorios4->siguiente;
                    }

                    while(auxpasa2!=NULL){
                        if(contadorpersonas==10){
                            break;
                        }
                        else{
                            Nodosimpleescri *auxcabepasa = auxinicioescritorios->iniciolista;
                            Nodosimpleescri *auxcabepasa2=auxcabepasa;


                            if(auxcabepasa->siguiente==NULL){
                                auxcabepasa->siguiente=auxpasa2;
                                listapasajeros2->eliminar();
                                auxpasa2=listapasajeros2->devolvercabeza();
                                contadorpersonas=contadorpersonas+1;

                            }
                            else{
                                while(auxcabepasa2->siguiente!=NULL){
                                    auxcabepasa2=auxcabepasa2->siguiente;
                                }
                                auxcabepasa2->siguiente=auxpasa2;
                                listapasajeros2->eliminar();
                                contadorpersonas=contadorpersonas+1;
                                auxpasa2=listapasajeros2->devolvercabeza();

                            }

                        }
                    }


                }
                auxinicioescritorios=auxinicioescritorios->anterior;
            }


        }
        else{ //si no hay nada en la lista pero si hay escritorios

        }

    }
    else{//no hay escritorios
        return;

    }




}


void siguientepasajero::mostrarlistapasajero(){
    listapasajeros2->mostrar();
}


void siguientepasajero::hacergrafo(){

    ofstream grafo;
    grafo.open("grafoescri.txt");
    grafo<<"digraph G {\n";
    struct Nodoenlazada *s;
    struct Nodoenlazada *fin;
    s=listaescritorios2->devolvercabeza();

    if(s==NULL)
    {
       // cout<<"la lista esta vacia"<<endl;
        grafo<<"}";
      //  return;
    }
    else {

        if(s->anterior==NULL){
            grafo<<"\""<<"escritorio-"<<s->id<<"\"";
            if(s->iniciolista==NULL){

            }
            else{
                grafo<<"\""<<"escritorio-"<<s->id<<"\""<<"->"<<"\""<<s->iniciolista->identificacion<<"\"";

            }

        }
        else{
            while(s->anterior!=NULL){
                 grafo<<"\""<<"escritorio-"<<s->id<<"\""<<"->";

                 s=s->anterior;
            }
            fin=s;
            grafo<<"\""<<"escritorio-"<<s->id<<"\"";
            grafo<<";"<<"\n";

            //********************************************
            while(fin->siguiente!=NULL){
                grafo<<"\""<<"escritorio-"<<fin->id<<"\""<<"->";
                fin=fin->siguiente;

            }
            grafo<<"\""<<"escritorio-"<<fin->id<<"\"";
            grafo<<";"<<"\n";
            //*********************************************

            //------------------------------------------- para el primer nodo
            while(fin->anterior!=NULL){

                if(fin->iniciolista==NULL){

                }
                else{
                    struct Nodosimpleescri *aux=fin->iniciolista;
                    grafo<<"\""<<"escritorio-"<<fin->id<<"\""<<"->"<<"\""<<fin->iniciolista->identificacion<<"\";\n";

                    while(aux->siguiente!=NULL){
                        grafo<<"\""<<aux->identificacion<<"\""<<"->"<<"\""<<aux->siguiente->identificacion<<"\";\n";
                        aux=aux->siguiente;

                    }

                }
                fin=fin->anterior;

            }
            if(fin->iniciolista==NULL){

            }
            else{
                 struct Nodosimpleescri *aux=fin->iniciolista;
                grafo<<"\""<<"escritorio-"<<fin->id<<"\""<<"->"<<"\""<<fin->iniciolista->identificacion<<"\";\n";


                while(aux->siguiente!=NULL){
                    grafo<<"\""<<aux->identificacion<<"\""<<"->"<<"\""<<aux->siguiente->identificacion<<"\";\n";
                    aux=aux->siguiente;

                }

            }
            //-------------------------------------------





        }

        grafo<<"}";

    }

    grafo.close();
    system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafoescri.txt -o grafoescri.png");

}


void siguientepasajero::hacergrafogrande(){


        ofstream grafo;
        grafo.open("grafogrande.txt",ios::app);
        grafo<<"subgraph escritorios1 {\n";
        struct Nodoenlazada *s;
        struct Nodoenlazada *fin;
        s=listaescritorios2->devolvercabeza();

        if(s==NULL)
        {
           // cout<<"la lista esta vacia"<<endl;
            grafo<<"}";
          //  return;
        }
        else {
            cout<<"---Escritorios de registro---"<<endl;


            if(s->anterior==NULL){
                grafo<<"\""<<"escritorio-"<<s->id<<"\"";
                cout<<"     Escritorio: "<<s->id<<endl;


                if(s->iniciolista==NULL){
                    cout<<"     Pasajero: "<<endl;
                    cout<<"     Estado: libre"<<endl;
                    cout<<"     Turnos restantes: 0"<<endl;
                    cout<<"     Cantidad de documentos: 0"<<endl;
                    cout<<"-----------------------------------------"<<endl;

                }
                else{
                    grafo<<"\""<<"escritorio-"<<s->id<<"\""<<"->"<<"\""<<s->iniciolista->identificacion<<"\"";
                    cout<<"     Pasajero: "<<s->iniciolista->identificacion<<endl;
                    cout<<"     Estado: ocupado"<<endl;
                    cout<<"     Turnos restantes: "<<s->iniciolista->turnos<<endl;
                    cout<<"     Cantidad de documentos: "<<s->iniciolista->documentos<<endl;
                     cout<<"-----------------------------------------"<<endl;

                }

            }
            else{
                while(s->anterior!=NULL){
                     grafo<<"\""<<"escritorio-"<<s->id<<"\""<<"->";

                     s=s->anterior;
                }
                fin=s;
                grafo<<"\""<<"escritorio-"<<s->id<<"\"";
                grafo<<";"<<"\n";

                //********************************************
                while(fin->siguiente!=NULL){
                    grafo<<"\""<<"escritorio-"<<fin->id<<"\""<<"->";
                    fin=fin->siguiente;

                }
                grafo<<"\""<<"escritorio-"<<fin->id<<"\"";
                grafo<<";"<<"\n";
                //*********************************************

                //------------------------------------------- para el primer nodo
                while(fin->anterior!=NULL){

                    if(fin->iniciolista==NULL){
                        cout<<"Escritorio"<<fin->id<<endl;
                        cout<<"     Pasajero: "<<endl;
                        cout<<"     Estado: libre"<<endl;
                        cout<<"     Turnos restantes: 0"<<endl;
                        cout<<"     Cantidad de documentos: 0"<<endl;


                    }
                    else{
                        struct Nodosimpleescri *aux=fin->iniciolista;
                        grafo<<"\""<<"escritorio-"<<fin->id<<"\""<<"->"<<"\""<<fin->iniciolista->identificacion<<"\";\n";
                        cout<<"Escritorio"<<fin->id<<endl;
                        cout<<"     Pasajero: "<<fin->iniciolista->identificacion<<endl;
                        cout<<"     Estado: ocupado"<<endl;
                        cout<<"     Turnos restantes: "<<fin->iniciolista->turnos<<endl;
                        cout<<"     Cantidad de documentos: "<<fin->iniciolista->documentos<<endl;


                        while(aux->siguiente!=NULL){
                            grafo<<"\""<<aux->identificacion<<"\""<<"->"<<"\""<<aux->siguiente->identificacion<<"\";\n";
                            aux=aux->siguiente;

                        }

                    }
                    fin=fin->anterior;

                }
                if(fin->iniciolista==NULL){

                }
                else{
                     struct Nodosimpleescri *aux=fin->iniciolista;
                    grafo<<"\""<<"escritorio-"<<fin->id<<"\""<<"->"<<"\""<<fin->iniciolista->identificacion<<"\";\n";


                    while(aux->siguiente!=NULL){
                        grafo<<"\""<<aux->identificacion<<"\""<<"->"<<"\""<<aux->siguiente->identificacion<<"\";\n";
                        aux=aux->siguiente;

                    }

                }
                //-------------------------------------------





            }
 cout<<"-----------------------------------------"<<endl;
            grafo<<"}";

        }

        grafo.close();
       // system("C:\\Graphviz2.38\\bin\\dot.exe -Tpng grafoescri.txt -o grafoescri.png");
        listapasajeros2->grafogrande();



}


void siguientepasajero::restarturnoescritorio(){

    Nodoenlazada *auxinicioescritorios= listaescritorios2->devolvercabeza();

    if(auxinicioescritorios!=NULL){
        Nodoenlazada *aux2=auxinicioescritorios;
        while(aux2!=NULL){
            if(aux2->iniciolista!=NULL){
                if(aux2->iniciolista->turnos==0){
                    Nodosimpleescri *aux= aux2->iniciolista;
                    if(aux->siguiente!=NULL){
                        lcircu2.eliminar(aux->maletas);
                        aux2->iniciolista=aux->siguiente;


                    }
                    else{
                        aux2->iniciolista=NULL;

                    }


                }
                else{
                    aux2->iniciolista->turnos--;
                }

            }
            else{ // no hay nada en la lista escritorio

            }
            aux2=aux2->anterior;
        }


    }
    else{//la lista de escritorios esta vacia

    }


}

void siguientepasajero::mostrarlistacircular(){
    lcircu2.mostrar();
}

