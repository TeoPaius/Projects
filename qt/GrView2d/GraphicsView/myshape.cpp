#include "myshape.h"
#include <QTransform>
#include <QGraphicsPathItem>

MyShape::MyShape(QObject *parent)
{
    crot = 0;
    obj = new QGraphicsPathItem();
    shapeC = new QPoint();

}

void MyShape::SetShapeC(QPoint *x)
{
    shapeC = x;
}

void MyShape::Rot()
{
     crot++;
     QGraphicsPathItem * aux = new QGraphicsPathItem();
     aux = this->obj;
     QTransform *tr = new QTransform();

     tr->translate(shapeC->x(), shapeC->y());
     tr->rotate(crot);
     tr->translate(-shapeC->x(), -shapeC->y());

     aux->setTransform(*tr);

}

