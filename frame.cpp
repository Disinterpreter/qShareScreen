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
    QRect *rect = new QRect();
    if(temp[0] < position.x() || temp[1] < position.y())
    {
        rect->setX(position.x());
        rect->setY(position.y());
        rect->setWidth(abs(temp[0] - position.x()));
        rect->setHeight(abs(temp[1] - position.y()));
    }
    else
    {
        rect->setX(temp[0]);
        rect->setY(temp[1]);
        rect->setWidth(abs(temp[0] - position.x()));
        rect->setHeight(abs(temp[1] - position.y()));
    }
    this->destroy();
    QPixmap pix = map->copy(*rect);
    qDebug()<<"X:"<<temp[0]<<"Y:"<<temp[1]<<"W:"<<abs(temp[0] - position.x())<<"H:"<<abs(temp[1] - position.y());
    pix.save(QString("./screenshot%1.png").arg(1));
}
