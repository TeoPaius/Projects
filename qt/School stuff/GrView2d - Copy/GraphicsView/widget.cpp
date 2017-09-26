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
#include <QDebug>
#include <cmath>
#include <QTime>

int maxim;

void Widget::Initialize()
{
    absCenter = new QPoint(350,350);
    for(int i = 0; i <= 9; ++i)
        objects[i] = new MyShape(this);
    cnto = 0;
    scene = new QGraphicsScene();
    ui->graphicsView->setAcceptDrops(true);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
  //  ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
}

void Widget::ObjCreation()
{



    objects[cnto]->obj = CreateObj(*absCenter,130, 150);
    objects[cnto]->SetGradient(QColor::fromRgb(79,20,152),QColor::fromRgb(0,255,0));
    objects[cnto]->SetDirection(-1);
    cnto++;

    objects[cnto]->obj = CreateObj(*absCenter,120, 130);
    objects[cnto]->SetGradient(QColor::fromRgb(10,24,66),QColor::fromRgb(56,48,185));
    objects[cnto]->SetDirection(1);
    cnto++;

    objects[cnto]->obj = CreateObj(*absCenter, 120, 100);
    objects[cnto]->SetGradient(QColor::fromRgb(123,165,187),QColor::fromRgb(110,27,212));
    objects[cnto]->SetDirection(-1);
    cnto++;

    objects[cnto]->obj = CreateObj(*absCenter, 100, 70);
    objects[cnto]->SetGradient(QColor::fromRgb(255,0,0),QColor::fromRgb(0,0,255));
    objects[cnto]->SetDirection(-1);
    cnto++;

    objects[cnto]->obj = CreateObj(*absCenter,70, 50);
    objects[cnto]->SetGradient(QColor::fromRgb(25,152,13),QColor::fromRgb(15,210,120));
    objects[cnto]->SetDirection(1);
    cnto++;

    objects[cnto]->obj = CreateObj(*absCenter,150, 165);
    objects[cnto]->SetGradient(QColor::fromRgb(197,200,247),QColor::fromRgb(189,195,21));
    objects[cnto]->SetDirection(-1);
    cnto++;

    objects[cnto]->obj = CreateObj(*absCenter,165, 185);
    objects[cnto]->SetGradient(QColor::fromRgb(21,200,153),QColor::fromRgb(222,20,111));
    objects[cnto]->SetDirection(1);
    cnto++;


    for(int i = 0; i < cnto; ++i)
    {
        objects[i]->SetShapeC(absCenter);
        objects[i]->SetColor(objects[i]->grStart);
    }

    rotfreq[0] = 10;
    rotfreq[1] = 20;
    rotfreq[2] = 30;
    rotfreq[3] = 40;
    rotfreq[4] = 50;

    rotfreq[5] = 60;
    rotfreq[6] = 70;

    maxim = 48 * 360;



    for(int i = 0; i < cnto; ++i)
        objects[i]->SetPeriod(rotfreq[i]);

}

void Widget::TimerIntialization()
{
    for(int i = 0; i < cnto; ++i)
    {
       timers[i] = new QTimer();
        timers[i]->setInterval(rotfreq[i]);
    }


    t = new QTimer(this);
    t->setInterval(1);
    connect(t,SIGNAL(timeout()),this,SLOT(Rotate()));
    //connect(objects[4],SIGNAL(RotDone()),t,SLOT(stop()));

}

QColor Widget::Interpolate(QColor start, QColor end, float p)
{

    double red = (start.red() * (1-p) + end.red() * (p));
    int blue = (start.blue() * (1-p) + end.blue() * (p));
    int green = (start.green() * (1-p) + end.green() * (p));
    //qDebug() << start.red() * p;
    return QColor::fromRgb(red,green,blue);
}



void Widget::Rotate()
{
    timeel++;

    for(int i = 0; i < cnto; ++i)
    {
        if(timeel % rotfreq[i] == 0)
        objects[i]->Rot();
        objects[i]->SetColor((Interpolate(objects[i]->grStart, objects[i]->grEnd, objects[i]->dir*(float)(objects[i]->crot%360)/360)));
    }

    if(timeel == maxim)
        timeel = 0;

}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Initialize();

    ObjCreation();

    TimerIntialization();

    ui->graphicsView->setScene(scene);


}

Widget::~Widget()
{
    delete ui;
}

QGraphicsPathItem *Widget::CreateObj(QPoint cp, int innerR, int outerR)
{
    QBrush *brush = new QBrush(Qt::red);
    QPen * pen = new QPen(Qt::NoPen);
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

   // p->setFlag(QGraphicsItem::ItemIsMovable);
   // p->setFlag(QGraphicsItem::ItemIsSelectable);


    return p;

}

void Widget::on_btnStart_clicked()
{
    t->start();
}

void Widget::on_btnPause_clicked()
{
    t->stop();
}
