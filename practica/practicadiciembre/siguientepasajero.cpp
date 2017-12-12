#include "siguientepasajero.h"
#include "randommetodo.h"
#include "dobleenlazada.h"

siguientepasajero::siguientepasajero()
{

}
listasimple listapasajeros;
dobleenlazada listaescritorios;
randommetodo ranm;
int auxidentificacion=1;
//**********************


void siguientepasajero::agregarpasajeroacolasimple(int cantidad){

    for(int i=0;i<cantidad;i++){
        listapasajeros.insertarnodo(auxidentificacion,ranm.obtenernumerorango(1,4),ranm.obtenernumerorango(1,10),ranm.obtenernumerorango(1,3));
        auxidentificacion++;


    }
     listapasajeros.mostrar();
}

void siguientepasajero::agregarescritorios(int cantidadescritorios){
    for(int i=0;i<cantidadescritorios;i++){
        if(i==0){
            listaescritorios.insertarnodo("A");

        }
        else if(i==1){
             listaescritorios.insertarnodo("B");

        }
        else if(i==2){
             listaescritorios.insertarnodo("C");

        }
        else if(i==3){
             listaescritorios.insertarnodo("D");

        }
        else if(i==4){
             listaescritorios.insertarnodo("E");

        }
        else if(i==5){
             listaescritorios.insertarnodo("F");

        }
        else if(i==6){
             listaescritorios.insertarnodo("G");

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
    listaescritorios.mostrar();

}

void siguientepasajero::moverpasajeros(){
    struct doble *auxiniciodoble=listaescritorios.retornarinicioescritorios();



    if(auxiniciodoble==NULL){
        cout<<"no hay escritorios, esta vacio";


    }
    else{

    }



}
