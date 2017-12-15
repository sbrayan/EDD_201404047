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
 int cantidadaviones=0;
 int cantidaturnos=0;
 int cantidadmantenimiento=0;
 int cantidadescritorios=0;
    listaavion lavion;
    listasimple lsimple;
    listacircular lcircu;
    randommetodo randu;
    pila lp;

    siguientepasajero st;
    siguienteturno stt;
    bool ok;


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnaceptar_clicked()
{

     cantidadaviones=ui->lineaviones->text().toInt(&ok,10);
     cantidaturnos= ui->lineturnos->text().toInt(&ok,10);
     cantidadmantenimiento=ui->linemantenimiento->text().toInt(&ok,10);
     cantidadescritorios= ui->lineescritorios->text().toInt(&ok,10);

    ui->lineaviones->setEnabled(false);
    ui->lineaviones->setEnabled(false);
    ui->linemantenimiento->setEnabled(false);
    ui->lineescritorios->setEnabled(false);

    stt.agregaraviones(cantidadaviones);
    stt.agregarestaciones(cantidadmantenimiento);
    stt.generargrafogrande();


}

void MainWindow::on_pushButton_clicked()
{


   // st.moverpasajeros();
    stt.agregaraviones(cantidadaviones);
    //stt.agregaravionesamantenimiento();
    stt.generargrafogrande();

    //stt.generargrafogrande();

   // st.agregarpasajeroacolasimple(10);
   // st.moverpasajeros();

 /* srand(time(NULL));
    int ale=0;
    ale=rand()%(30-20+1)+20;
    cout<<ale<<endl; */



}

void MainWindow::on_pushButton_2_clicked()
{
   // stt.agregaravionesamantenimiento();
    stt.pruebaeliminar();

   // stt.agregaravionesamantenimiento();
    stt.generargrafogrande();

}
