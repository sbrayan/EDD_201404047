#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "listaavion.h"
#include "listasimple.h"
#include "listacircular.h"
#include "randommetodo.h"
#include "siguienteturno.h"
#include "siguientepasajero.h"
#include "pila.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
    listaavion lavion;
    listasimple lsimple;
    listacircular lcircu;
    randommetodo randu;
    pila lp;



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnaceptar_clicked()
{

/*    lp.insertarnodo("1");
    lp.insertarnodo("2");
    lp.insertarnodo("3");
    lp.insertarnodo("4");
    lp.insertarnodo("5");
    lp.insertarnodo("6");
    lp.mostrar(); */
    /*

    lavion.insertarnodo("uno",1,1,1);
    lavion.insertarnodo("dos",2,2,2);
    lavion.insertarnodo("tres",3,3,3);
    lavion.insertarnodo("cuatro",4,4,4);
    lavion.insertarnodo("cinco",4,4,4);
    lavion.mostrar(); */

    lsimple.insertarnodo(1,1,1,1);
    lsimple.insertarnodo(2,1,1,1);
    lsimple.insertarnodo(3,1,1,1);
    lsimple.insertarnodo(4,1,1,1);
    lsimple.insertarnodo(5,1,1,1);
    lsimple.mostrar();
   // lsimple.eliminar();

  /*  lcircu.insertarnodo(1);
    lcircu.insertarnodo(2);
    lcircu.insertarnodo(3);
    lcircu.insertarnodo(4);
    lcircu.insertarnodo(5);
    lcircu.insertarnodo(6);
    lcircu.insertarnodo(7);
    lcircu.insertarnodo(8);
    lcircu.mostrar();  */


}

void MainWindow::on_pushButton_clicked()
{
    /*
    int randoom;
    bool first = true;

    if(first)
    {
        srand(time(0));
        first = false;
    }
    randoom=rand()%(3-1+1)+1;
    cout<<randoom<<endl; */
    siguientepasajero st;
   // st.agregarescritorios(10);


 /* srand(time(NULL));
    int ale=0;
    ale=rand()%(30-20+1)+20;
    cout<<ale<<endl; */



    //lp.eliminar();
    //lp.mostrar();


}
