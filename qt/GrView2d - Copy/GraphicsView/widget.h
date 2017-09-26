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
    MyShape *objects[10];
    int rotfreq[10];
    int currentrot[10];
    QTimer* timers[10];
    int cnto;
    int timeel;

    QGraphicsScene *scene;

    QGraphicsPathItem *CreateObj(QPoint cp, int innerR, int outerR);



    void Initialize();
    void ObjCreation();
    void TimerIntialization();
    QColor Interpolate(QColor start, QColor end, float p);


public slots:

    void Rotate();

private slots:
    void on_btnStart_clicked();

    void on_btnPause_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
