#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     //Ui::MainWindow *ui;


    void mostrarimagen();
    void ingresartextoconsola(QString text);
    void ingresarappend();




private slots:
    void on_btnaceptar_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
