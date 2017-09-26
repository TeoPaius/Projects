#include "cannonfield.h"
#include "widget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>
#include <QKeyEvent>
#include <cmath>
#include <QDebug>
#include <QTime>

#define PI 3.14159265
#define Eps 0.000001

CannonField::CannonField(QWidget *parent) :
    QWidget(parent)
{

    w = 70;
    h = 10;
    cntrot = -45;
    cntforce = 0;
    sign = -1;
    started = false;
    speed = 1;
    G = 0.0007;
    targetHit = false;
    targetsize = 20;

    ChangeTarget();

    t = new QTimer(this);
    shotTimer = new QTimer(this);
    shotTimer->setInterval(speed);
    t->setInterval(10);
    connect(t,SIGNAL(timeout()),this,SLOT(update()));
    connect(this,SIGNAL(ShotStarted()),shotTimer,SLOT(start()));
    connect(this,SIGNAL(ShotEnded()),shotTimer,SLOT(stop()));
    connect(shotTimer,SIGNAL(timeout()),this,SLOT(update()));
    t->start();
    update();

}

CannonField::~CannonField()
{
   //delete this;
}

void CannonField::paintEvent(QPaintEvent *e)
{

    QPainter* p = new QPainter(this);
    QPen* pen = new QPen(Qt::red);
    pen->setStyle(Qt::NoPen);

    p->drawRoundedRect(0,0,width()-1, height()-1,3,3);


    QBrush* brush = new QBrush(Qt::green);
    int screenx;
    screenx = this->height();
    p->translate(0, screenx);



    brush->setColor(Qt::darkGreen);
    p->setBrush(*brush);

    p->drawEllipse(-50,-50,100,100);

    brush->setColor(Qt::green);
    p->setBrush(*brush);


    p->rotate(cntrot);

    p->drawRect(0, -h/2,w,h);
    p->rotate(-cntrot);

    if(!targetHit)
        DrawTarget(p);

    if(!started)
    {
        starty = (w)*sin(-cntrot * PI /180);
        startx = (w)*cos(-cntrot * PI / 180);
        shotx = startx;
        shoty = starty;
    }
    if(started)
    {

        ChangeXY();
    }

    if(abs(shotx - targetCx) < Eps && shoty <= targetCy && shoty >= targetCy - targetsize && !targetHit)
    {
        emit TargetWasHit();
        targetHit = true;
    }
    if(shotx > width() || shotx < 0 || shoty > height() || shoty < 0)
    {
        EndShot();
    }



    QPen* aux = new QPen("red");
    aux->setWidth(5);
    p->setPen(*aux);
    p->drawPoint(shotx,-shoty);
    delete p;
}

void CannonField::keyPressEvent(QKeyEvent *e)
{

    if(!started)
    {
        if(e->key() == Qt::Key_Up && cntrot > -90)
        {
            cntrot--;
            emit AngleChanged(-cntrot);

        }
        if(e->key() == Qt::Key_Down && cntrot < 0)
        {
            cntrot++;
            emit AngleChanged(-cntrot);
        }
        if(e->key() == Qt::Key_Left && cntforce > 0)
        {
            cntforce--;
            emit ForceChanged(cntforce);
        }
        if(e->key() == Qt::Key_Right && cntforce < 100)
        {
            cntforce++;
            emit ForceChanged(cntforce);
        }
    }

}

void CannonField::SetAngle(int val)
{
    cntrot = -val;
}

void CannonField::SetForce(int val)
{
    cntforce = val;
}

void CannonField::StartShot()
{
    if(cntforce)
    {
        started = true;
        time_elapsed = 0;
        t->stop();
        emit ShotStarted();
    }
}

void CannonField::EndShot()
{

    if(targetHit)
    {
        targetHit = false;
        ChangeTarget();

    }
    started = false;

    t->start();
    emit ShotEnded();
}

void CannonField::ChangeXY()
{
    time_elapsed += 1;
    shoty = starty+(cntforce/80*time_elapsed)*sin(-cntrot * PI /180) - (G/2)*time_elapsed*time_elapsed;
    shotx = startx+(cntforce/80*time_elapsed)*cos(-cntrot * PI / 180);
}

void CannonField::ChangeTarget()
{
    if(!targetHit)
    {
        qsrand(QTime::currentTime().msec());
        targetCx = qrand() % ((500+1)-70) + 70;
        targetCy = qrand() % ((400+1)-70) + 70;
    }
    else
    {
        targetCx = -1;
        targetCy = -1;
    }

}

void CannonField::DrawTarget(QPainter *xp)
{
    xp->setBrush(QBrush("red"));
    xp->drawRect(targetCx, -targetCy, targetsize/2, targetsize);

}


