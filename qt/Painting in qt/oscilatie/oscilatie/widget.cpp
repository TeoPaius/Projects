#include "widget.h"
#include "ui_widget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>
#include <qmath.h>
#include <cmath>
#include <QString>


QPainter *p = new QPainter();
QPen *pen = new QPen(Qt::red);
QBrush *brush = new QBrush(Qt::red);
QPen *pen2 = new QPen(Qt::green);

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_NoSystemBackground);
    x = 20;
    y = 20;
    A = 200;
    s = 0;
    pi = 3.14159265359;
    T =2;
    t = 0;
    t2 = 0;
    r = -30;
    tim = new QTimer(this);
    tim2 = new QTimer(this);
    Conections();
    tim2->setInterval(100);
    tim->setInterval(10);
    tim->start();
    tim2->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *ev)
{


    p->begin(this);

    p->setPen(*pen2);


    p->resetTransform();
    p->translate(250,250);
     p->drawEllipse(0,0,400,400);



    p->setPen(*pen2);
    p->drawLine(-200, 0,200,0);

    p->setPen(*pen);
    p->setBrush(*brush);

    p->drawEllipse(s,0,x,y);

    Draw(s2);

    Draw(s3);

    Draw(s4);

    Draw(s5);

    Draw(s6);

    p->end();
}

void Widget::Change()
{
    t+= 0.01;
    s = A * sin(2*pi/T * t );
    s2 = A * sin(2*pi/T *t + pi/6);
    s3 = A * sin(2*pi/T *t + 2*pi/6);
    s4 =A * sin(2*pi/T *t + 3*pi/6);

    s5 = A* sin(2*pi/T *t + 4*pi/6);
    s6 = A* sin(2*pi/T *t + 5*pi/6);

    //ui->pushButton->setText(QString::number(t));
    update();

}

void Widget::Conections()
{
    connect(tim,SIGNAL(timeout()),this,SLOT(Change()));
    connect(tim2,SIGNAL(timeout()),this,SLOT(Change2()));
}

void Widget::Change2()
{
    t2+=1;
    //x++;
    //r+=1;

    //ui->pushButton_2->setText(QString::number(t2));

}

void Widget::Draw(int k)
{
    p->rotate(r);

    p->setPen(*pen2);
    p->drawLine(-200 ,0,200,0);

    p->setPen(*pen);
    p->setBrush(*brush);
    p->drawEllipse(k,0,x,y);
}



