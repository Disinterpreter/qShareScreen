#include "frame.h"
#include "ui_frame.h"
#include <qexlabel.h>
#include <QDesktopWidget>

QCursor *mouse = new QCursor();
QPoint startPosition;
QPoint endPosition;

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
    QPoint startPosition = mouse->pos();
    startpos[0] = startPosition.x();
    startpos[1] = startPosition.y();

}

void Frame::on_label_mouseReleaseEvent(QMouseEvent *e)
{
    QPoint endPosition = mouse->pos();
    QRect *rect = new QRect();
    int weight = endPosition.x() - startpos[0];
    int height = endPosition.y() - startpos[1];
    if(weight < 0)
    {
        startpos[0] = startpos[0] + weight;
        weight = -weight;
    }
    if(height<0)
    {
        startpos[1] = startpos[1] + height;
        height = -height;
    }
    rect->setX(startpos[0]);
    rect->setY(startpos[1]);
    rect->setWidth(weight);
    rect->setHeight(height);

    QPixmap pix = map->copy(*rect);

    this->destroy();
    pix.save(QString("./screenshot%1.png").arg(1));
}
