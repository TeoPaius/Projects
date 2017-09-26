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
#include <QtMultimedia/QSound>
#include <QApplication>
#include <QDesktopWidget>

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
    constant = 0;
    isBox = true;

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
        auxcntrot = cntrot;
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
    if(abs(shoty - targetCy + targetsize) < Eps && shotx >= targetCx && shotx <= targetCx + targetsize/2)
    {
        emit TargetWasHit();
        targetHit = true;
    }
    if(shotx > width() || shotx < 0)
    {
        if(constant == 0)
            constant = 1;
        else
            constant = 0;
    }
    if((shotx > width() || shotx < 0 || shoty > height() || shoty < 0) && started)
    {
        EndShot();

    }



    QPen* aux = new QPen("red");
    aux->setWidth(5);
    p->setPen(*aux);
    p->drawPoint(shotx,-shoty);
    delete p;
}

void CannonField::AddExtraSpace()
{
    spaces[spacescnt] = new ExtraSpace();
    spaces[spacescnt]->setWindowFlags(Qt::Window);
    spaces[spacescnt]->pos().setX(100);
    spaces[spacescnt]->pos().setY(100);
    spaces[spacescnt]->size().setHeight(100);
    spaces[spacescnt]->size().setWidth(100);
    spaces[spacescnt]->show();
    this->activateWindow();
    spacescnt++;
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
        if(e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter)
        {
            StartShot();
        }
        if(e->key() == Qt::Key_B)
        {
            AddExtraSpace();
        }
    }
    else if(started)
        if(e->key() == Qt::Key_E)
        {
            started = false;
            t->start();
            emit ShotEnded();
        }
    if(e->key() == Qt::Key_R)
    {
        if(isBox == true)
        {
            isBox = false;
            emit ModeChanged(false);
        }
        else
        {
            isBox = true;
            emit ModeChanged(true);
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
    if(isBox)
    {
        BoxChangeXY();
    }
    else
    {
        started = false;
        t->start();
        emit ShotEnded();
    }
}

void CannonField::BoxChangeXY()
{
    startx = previousx;
    starty = previousy;
    qDebug() << auxcntrot;
    auxcntrot = atan(Vy/Vx)*180/PI-180*constant;
    qDebug() << auxcntrot;
    time_elapsed = 0;
    ChangeXY();
}

void CannonField::ChangeXY()
{
    time_elapsed += 1;
    Vx = cntforce*cos(-auxcntrot* PI/180);
    Vy = cntforce*sin(-auxcntrot* PI/180) - G*time_elapsed*70;
    //qDebug() << atan(Vy/Vx)*180/PI;
    previousy = shoty;
    previousx = shotx;
    shoty = starty+(cntforce/80*time_elapsed)*sin(-auxcntrot * PI /180) - (G/2)*time_elapsed*time_elapsed;
    shotx = startx+(cntforce/80*time_elapsed)*cos(-auxcntrot * PI / 180);
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


