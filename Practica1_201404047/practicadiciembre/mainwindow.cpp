#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "listaavion.h"
#include "listasimple.h"
#include "listacircular.h"
#include "randommetodo.h"
#include "siguienteturno.h"
#include "siguientepasajero.h"
#include "pila.h"
#include <QLabel>
#include <QtGui>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
QString textoapped;
 int cantidadaviones=0;
 int cantidaturnos=0;
 int auxcantidadturnos=1;
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
    ui->consola->append("**********************INICIO**********************");
    cout<<"**********************INICIO**********************"<<endl;

     cantidadaviones=ui->lineaviones->text().toInt(&ok,10);
     cantidaturnos= ui->lineturnos->text().toInt(&ok,10);
     cantidadmantenimiento=ui->linemantenimiento->text().toInt(&ok,10);
     cantidadescritorios= ui->lineescritorios->text().toInt(&ok,10);

    ui->lineaviones->setEnabled(false);
    ui->lineaviones->setEnabled(false);
    ui->linemantenimiento->setEnabled(false);
    ui->lineescritorios->setEnabled(false);
    ui->lineturnos->setEnabled(false);
    ui->btnaceptar->setEnabled(false);

    stt.agregaraviones(cantidadaviones);
    st.agregarescritorios(cantidadescritorios);
    stt.agregarestaciones(cantidadmantenimiento);
    stt.generargrafogrande();

     st.hacergrafo(); //grafo de escritorio
     mostrarimagen();


}

void MainWindow::on_pushButton_clicked()
{

    if(cantidaturnos==0){
        ui->pushButton->setEnabled(false);
        ui->consola->append("--------------SE ACABARON LOS TURNOS----------");
        cout<<"--------------SE ACABARON LOS TURNOS----------"<<endl;
        return;
    }
    ui->consola->append("*************** TURNO "+QString::number(auxcantidadturnos)+"***************");
    cout<<"*************** TURNO "<<auxcantidadturnos<<"***************"<<endl;
    auxcantidadturnos++;

   // st.moverpasajeros();
    stt.agregaraviones(cantidadaviones);
    stt.agregaravionesamantenimiento();
    st.moverpasajeros2();
    st.mostrarlistapasajero();
    st.restarturnoescritorio();
    st.hacergrafo();
    stt.generargrafogrande();
    st.mostrarlistacircular();
    mostrarimagen();
cout<<"***************FIN TURNO "<<auxcantidadturnos<<"***************"<<endl;
    cantidaturnos--;
    ui->lineturnos->setText(QString::number(cantidaturnos));

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

  /* QString u = QFileDialog::getOpenFileName(this, tr("Seleccione una Imagen"),
    "/home/",
    tr("Images (*.png *.xpm *.jpg)"));
    cout<<u.toStdString()<<endl; */

    
    ui->consola->append("HOLA");





}

void MainWindow::mostrarimagen(){
    QString u;
    u= "C:/Users/Admin/Documents/build-practicadiciembre-Desktop_Qt_5_9_0_MinGW_32bit-Debug/grafogrande.png";
    QPixmap pixmap;
    pixmap.load(u);
    ui->labelimagen->setText(u);
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");



    ui->labelimagen->setPixmap(pixmap);
    ui->scrollArea->setWidget(ui->labelimagen);
}


void MainWindow::ingresartextoconsola(QString texto){
    ui->consola->append(texto);
   // ingresarappend();

}

void MainWindow::ingresarappend(){

}
