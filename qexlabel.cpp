#include "qexlabel.h"

QExLabel::QExLabel(QWidget * parent ) :QLabel(parent)
{
    connect( this, SIGNAL( clicked() ), this, SLOT( slotClicked() ) );
    //connect( this, SIGNAL( mousePressEvent(QMouseEvent *event) ), this, SLOT( sl_mousePressEvent(QMouseEvent *event) ) );
    //connect( this, SIGNAL( mouseReleaseEvent(QMouseEvent *ev) ), this, SLOT( sl_mouseReleaseEvent(QMouseEvent *ev) ) );
}



void QExLabel::slotClicked()
{
    qDebug()<<"Clicked";
}

void QExLabel::sl_mousePressEvent(QMouseEvent *event)
{
    emit clicked();
    QCursor *mouse = new QCursor();
    QPoint position = mouse->pos();
    //qDebug()<<position.x();

    //qDebug()<<"Pressed";
    //qDebug()<<position.x()<<position.y();
}

void QExLabel::sl_mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked();
    //qDebug()<<"Released";
}
