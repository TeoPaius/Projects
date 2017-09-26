#include "myshape.h"
#include <QTransform>
#include <QGraphicsPathItem>
#include <QPoint>


MyShape::MyShape(QObject *parent)
{
    this->setParent(parent);
    crot = 0;
}

void MyShape::SetShapeC(QPoint *x)
{
    shapeC = new QPoint();
    shapeC = x;
}

void MyShape::SetPeriod(int x)
{
    period = x;
}

void MyShape::SetColor(QColor x)
{
    color = x;
    obj->setBrush(QBrush(x));
}

void MyShape::SetGradient(QColor startColor, QColor endColor)
{
    grStart = startColor;
    grEnd = endColor;
}

void MyShape::SetDirection(int _dir)
{
    dir = _dir;
}

void MyShape::Rot()
{

     crot+=2*dir;

     QTransform *tr = new QTransform();

     tr->translate(shapeC->x(), shapeC->y());
    tr->rotate(crot);
     tr->translate(-shapeC->x(), -shapeC->y());

     this->obj->setTransform(*tr);

    if(crot % 360 == 0)
    {
        QColor aux = grStart;
        grStart = grEnd;
        grEnd = aux;
        crot = 0;

        // emit RotDone();
    }
}

