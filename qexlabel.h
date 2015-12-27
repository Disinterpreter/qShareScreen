#ifndef QEXLABEL_H
#define QEXLABEL_H

#include <QLabel>
#include <QString>
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QCursor>
#include <QPoint>

class QExLabel : public QLabel
{
    Q_OBJECT
public:
    QExLabel( QWidget * parent = 0 );
    ~QExLabel(){};
signals:
    void clicked();
    void mousePressEvent ( QMouseEvent * event ) ;
    void mouseReleaseEvent (QMouseEvent *ev);

public slots:
    void slotClicked();
    void sl_mousePressEvent ( QMouseEvent * event ) ;
    void sl_mouseReleaseEvent (QMouseEvent *ev);
protected:

};

#endif // QEXLABEL_H
