#include "widget.h"
#include "ui_widget.h"
#include "background.h"
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QPainter>


#include <QGraphicsScene>
#include <QTransform>
#include <QPoint>

void Widget::ChangePixmap()
{
    QPainter *p = new QPainter();
    p->begin(pix);

    p->drawEllipse(*p1,circR,circR);
    p->drawEllipse(*p2,circR,circR);

    p->end();
}

void Widget::Debug()
{
    ui->pushButton->setText("ok");
}


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    back = new Background(this);
    scene = new QGraphicsScene();
    back->setSceneRect(0,0,back->size().width(),back->size().height());
    back->setAcceptDrops(true);
    back->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    connect(back,SIGNAL(Ok()),this,SLOT(Debug()));

    circR = 15;
    circE = 6;
    p1 = new QPoint(107,102);
    p2 = new QPoint(141,99);

    back->setGeometry(10,10,this->size().width() -20 , this->size().height()-20);
    pix = new QPixmap(":/Images/img2.png");
    *pix = pix->scaled(300,400,Qt::IgnoreAspectRatio);
    back->setScene(scene);


    ChangePixmap();

    item = new QGraphicsPixmapItem();
    item = scene->addPixmap(*pix);
    item->setFlag(QGraphicsPixmapItem::ItemIsMovable);


    rect = new QGraphicsRectItem();
    rect = scene->addRect(item->boundingRect(),QPen(Qt::red));


    reye = new QGraphicsEllipseItem();
    reye = scene->addEllipse(p2->x()-circE/2,p2->y()-circE/2,circE,circE,QPen(Qt::NoPen),QBrush(Qt::black));

    leye = new QGraphicsEllipseItem();
    leye = scene->addEllipse(p1->x()-circE/2,p1->y()-circE/2,circE,circE,QPen(Qt::NoPen),QBrush(Qt::black));


    scene->setBackgroundBrush(QBrush(Qt::green));


}

Widget::~Widget()
{
    delete ui;
}
