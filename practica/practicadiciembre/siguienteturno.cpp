#include "siguienteturno.h"
#include "listaavion.h"
#include "randommetodo.h"
#include "siguientepasajero.h"

siguienteturno::siguienteturno()
{

}
using namespace std;
int auxcantidadavion=0;
int auxcontadoraviones=0;
int sumaavion=1;
listaavion la;
randommetodo rm;
siguientepasajero sp;



void siguienteturno ::agregaraviones(int cantidad){
int pasajeros=0;
int mantenimiento=0;
if(auxcontadoraviones==0){ //para guardar una vez el numero de aviones
     auxcantidadavion=cantidad;
     auxcontadoraviones=1;
}


   if(auxcantidadavion==0){ //contador de aviones
       cout<<"sin aviones"<<endl;

   }
   else{
      int random;
      random=rm.obtenernumerorango(1,3);
      if(random==1){
          pasajeros=rm.obtenernumerorango(5,10);
          mantenimiento=rm.obtenernumerorango(1,3);


          la.insertarnodo("P"+to_string(auxcantidadavion),pasajeros,1,mantenimiento);
          la.mostrar();
          auxcantidadavion--;
          sp.agregarpasajeroacolasimple(pasajeros);

      }
      else if(random==2){
          pasajeros=rm.obtenernumerorango(15,25);
          mantenimiento=rm.obtenernumerorango(2,4);
          la.insertarnodo("M"+to_string(auxcantidadavion),pasajeros,2,mantenimiento);
          la.mostrar();
          auxcantidadavion--;
          sp.agregarpasajeroacolasimple(pasajeros);

      }
      else if(random==3){
          pasajeros=rm.obtenernumerorango(30,40);
          mantenimiento=rm.obtenernumerorango(3,6);

          la.insertarnodo("G"+to_string(auxcantidadavion),pasajeros,3,mantenimiento);
          la.mostrar();
          auxcantidadavion--;
          sp.agregarpasajeroacolasimple(pasajeros);

      }



   }


}
