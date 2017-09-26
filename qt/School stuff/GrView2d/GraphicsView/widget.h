#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsView>
#include <QPen>
#include <QBrush>
#include <QPainterPath>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QTransform>
#include <QPoint>
#include <QTimer>
#include "myshape.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int r;
    QTimer *t;
    QGraphicsPathItem *pi;
    QPoint *absCenter;
    QGraphicsPathItem *objects[10];
    int rotfreq[10];
    int currentrot[10];
    QTimer* timers[10];
    int cnto;

    QGraphicsScene *scene;

    QGraphicsPathItem *CreateObj(QPoint cp, int innerR, int outerR);

public slots:
    void Rot();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
