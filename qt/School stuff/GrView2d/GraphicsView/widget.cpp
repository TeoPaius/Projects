#include "widget.h"
#include "ui_widget.h"
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

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    absCenter = new QPoint(300,200);


    rotfreq[0] = 100;
    rotfreq[1] = 200;


    cnto = 0;
    scene = new QGraphicsScene();

    t = new QTimer();
    t->setInterval(10);

    objects[cnto] = CreateObj(*absCenter, 200, 150);
    //objects[cnto]->SetShapeC(absCenter);
    cnto++;

    objects[cnto] = CreateObj(*absCenter, 100, 70);
   // objects[cnto]->SetShapeC(absCenter);
    cnto++;

    for(int i = 0; i < cnto; ++i)
        currentrot[i] = 0;
    for(int i = 0; i < cnto; ++i)
    {
        timers[i] = new QTimer();
        timers[i]->setInterval(rotfreq[i]);
    }

    connect(t,SIGNAL(timeout()),this,SLOT(Rot()));

    MyShape *x = new MyShape(this);
    QPainterPath psd;
    QPen *pen = new QPen();
    QBrush *brush = new QBrush();
    x->obj = scene->addPath(psd,*pen,*brush);

    ui->graphicsView->setAcceptDrops(true);
    t->start();


    /*
    for(int i = 0; i < 2; ++i)
    {
        timers[i]->start();

    }
    */
    ui->graphicsView->setScene(scene);


}

Widget::~Widget()
{
    delete ui;
}

QGraphicsPathItem *Widget::CreateObj(QPoint cp, int innerR, int outerR)
{
    QBrush *brush = new QBrush(Qt::red);
    QPen * pen = new QPen(Qt::green);
    pen->setWidth(2);

    float cornerX, cornerY;
    cornerX = cp.x() - outerR;
    cornerY = cp.y() - outerR;

    QPainterPath *path = new QPainterPath();
    path->moveTo(cp.x() + outerR,cp.y());
    path->arcTo(cornerX,cornerY,outerR*2,outerR*2,0,-180);
    path->lineTo(cp.x() - innerR,cp.y());
    path->arcMoveTo(cp.x() - innerR,cp.y() - innerR, innerR*2, innerR*2, 0);
    path->arcTo(cp.x() - innerR,cp.y() - innerR, innerR*2, innerR*2, 0, -180);
    path->arcMoveTo(cp.x() - innerR,cp.y() - innerR, innerR*2, innerR*2, 0);
    path->lineTo(cp.x() + outerR,cp.y());

    QGraphicsPathItem *p = new QGraphicsPathItem();
    p = scene->addPath(*path);
    p->setBrush(*brush);
    p->setPen(*pen);

    p->setFlag(QGraphicsItem::ItemIsMovable);
    p->setFlag(QGraphicsItem::ItemIsSelectable);


    return p;


}

void Widget::Rot()
{
   r++;
    for(int i = 0; i < cnto; ++i)
    {
        if(r%rotfreq[i] == 0)
            currentrot[i]++;
    }
    QTransform *tr = new QTransform();

    for(int i = 0; i < cnto; ++i)
    {
        tr->translate(absCenter->x(), absCenter->y());
        tr->rotate(r);
        tr->translate(-absCenter->x(), -absCenter->y());
        objects[i]->setTransform(*tr);
    }



}
