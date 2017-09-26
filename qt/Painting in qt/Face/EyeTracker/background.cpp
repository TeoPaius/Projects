#include "background.h"
#include <QWidget>
#include <QObject>
#include <QGraphicsView>


Background::Background(QWidget *parent)
{
    this->setParent(parent);
}

void Background::mouseMoveEvent(QMouseEvent *ev)
{
    //emit Ok();

}
