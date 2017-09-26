#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_NoBackground);
    w = 70;
    h = 10;
    cntrot = 0;
    sign = -1;
    t = new QTimer(this);
    t->setInterval(10);
    connect(t,SIGNAL(timeout()),this,SLOT(update()));
    t->start();
    update();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter* p = new QPainter(this);
    QPen* pen = new QPen(Qt::red);
    pen->setWidth(5);
    QBrush* brush = new QBrush(Qt::green);
    int screenx;
    screenx = this->height();
    p->setPen(*pen);
    p->setBrush(*brush);
    p->translate(0, screenx);

   // p->rotate(-45);
    if(cntrot == -90)
        sign = 1;
    if(cntrot == 0)
        sign = -1;

   p->rotate(cntrot);
    cntrot += sign;

    p->drawRect(0, -h/2,w,h);


}
