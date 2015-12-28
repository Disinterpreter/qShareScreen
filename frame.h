#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include <QVector2D>
#include "qexlabel.h"
namespace Ui {
class Frame;
}

class Frame : public QExLabel
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = 0);
    void SendImage(QPixmap img);
    ~Frame();

private slots:
    void on_label_mousePressEvent(QMouseEvent *e);

    void on_label_mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::Frame *ui;
    QCursor *mouse;
    const QPixmap *map;
    //QVector2D *vec;
    int startpos[1] = {};

};

#endif // FRAME_H
