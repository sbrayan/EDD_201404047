#include "randommetodo.h"

randommetodo::randommetodo()
{
     srand(time(NULL));
}

int aux=0;
int auxrepetido=1;


int randommetodo ::obtenernumerorango(int infe,int supe){
  /*  int randoom;
    bool first = true;



    if(first)
    {

        first = false;
    }
    randoom=rand()%(supe-infe+infe)+infe;
    return randoom; */

    srand(time(NULL));
      int ale=0;
      ale=rand()%(supe-infe+1)+infe;
      return ale;



}

