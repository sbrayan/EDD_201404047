/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QFrame *frame;
    QLineEdit *lineaviones;
    QLabel *label;
    QLineEdit *lineescritorios;
    QLabel *label_2;
    QLineEdit *lineturnos;
    QLabel *label_4;
    QLineEdit *linemantenimiento;
    QLabel *label_3;
    QPushButton *btnaceptar;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(713, 453);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 180, 121, 23));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 141, 161));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        lineaviones = new QLineEdit(frame);
        lineaviones->setObjectName(QStringLiteral("lineaviones"));
        lineaviones->setGeometry(QRect(100, 10, 31, 20));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 47, 13));
        lineescritorios = new QLineEdit(frame);
        lineescritorios->setObjectName(QStringLiteral("lineescritorios"));
        lineescritorios->setGeometry(QRect(100, 40, 31, 20));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 51, 16));
        lineturnos = new QLineEdit(frame);
        lineturnos->setObjectName(QStringLiteral("lineturnos"));
        lineturnos->setGeometry(QRect(100, 100, 31, 20));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 41, 16));
        linemantenimiento = new QLineEdit(frame);
        linemantenimiento->setObjectName(QStringLiteral("linemantenimiento"));
        linemantenimiento->setGeometry(QRect(100, 70, 31, 20));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 71, 16));
        btnaceptar = new QPushButton(frame);
        btnaceptar->setObjectName(QStringLiteral("btnaceptar"));
        btnaceptar->setGeometry(QRect(10, 130, 121, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 220, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 713, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "SIGUIENTE", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Aviones", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Escritorios", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Turnos", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Mantenimiento", Q_NULLPTR));
        btnaceptar->setText(QApplication::translate("MainWindow", "INICIAR", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "prueba elim", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
