#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frame.h"
#include <QScreen>
#include <QtGui>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Frame *frame = new Frame();
//    QWidget *w = QApplication::activeWindow();
//    if(w) {
//        static int count = 0;
//        QPixmap p = QPixmap::grabWindow(w);
//        p.save(QString("./screenshot%1.png").arg(count));
//        count++;
//    }


    QScreen *screen = QGuiApplication::primaryScreen();
    if(screen)
    {
        //
        //QPixmap pix = _pix.scaled(640,480);
        static int count = 0;
        QPixmap _pix = screen->grabWindow(0);
        ui->label->setFixedSize(40,40);
        frame->showFullScreen();
        frame->show();
        frame->SendImage(_pix);
//        QRect rect(10, 20, 30, 40);
//        QPixmap pix = _pix.copy(rect);
//        ui->label->setPixmap(pix);

        //_pix.save(QString("./screenshot%1.png").arg(count));

    }
}
