#include "frame.h"
#include "ui_frame.h"
#include <qexlabel.h>
#include <QDesktopWidget>

QCursor *mouse = new QCursor();
//QVector2D *vec = new QVector2D();

Frame::Frame(QWidget *parent) :
    QExLabel(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);

}

void Frame::SendImage(QPixmap img)
{
    QSize size = QApplication::desktop()->size();
    ui->label->setFixedSize(size);
    ui->label->setPixmap(img);
    map = ui->label->pixmap();

    return;
}

Frame::~Frame()
{
    delete ui;
}

void Frame::on_label_mousePressEvent(QMouseEvent *e)
{
    QPoint position = mouse->pos();
    qDebug()<<position.x()<<position.y();
    temp[0] = position.x();
    temp[1] = position.y();

}

void Frame::on_label_mouseReleaseEvent(QMouseEvent *e)
{
    QPoint position = mouse->pos();
    qDebug()<<position.x()<<position.y();
//    if(temp[0] < position.x() || temp[1] < position.y())
//    {
//        QRect rect(position.x(), position.y(), abs(temp[0] - position.x()), abs(temp[1] - position.y()));
//    }
//    else
//    {

//    }
    QRect rect(temp[0], temp[1], abs(temp[0] - position.x()), abs(temp[1] - position.y()));
    //QRect rect = QRect();
    //TODO
    //rect.adjusted( temp[0], temp[1],position.x(), position.y());
    QPixmap pix = map->copy(rect);
    //ui->label->setPixmap(pix);
    qDebug()<<"X:"<<temp[0]<<"Y:"<<temp[1]<<"W:"<<abs(temp[0] - position.x())<<"H:"<<abs(temp[1] - position.y());
    pix.save(QString("./screenshot%1.png").arg(1));
    //qDebug()<<"Release";
}
