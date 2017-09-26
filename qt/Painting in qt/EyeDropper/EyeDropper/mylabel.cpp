#include "mylabel.h"
#include <QImage>

myLabel::myLabel(QWidget *parent, QPushButton *btn) :
    QLabel(parent), button(btn)
{
    //img = new QImage();

    img.load(":/imagini/img.jpg");
    //setStyleSheet("background-color:red");
    setPixmap(QPixmap::fromImage(img));
}

myLabel::~myLabel()
{

}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    //double wWidth, wHeight;
    int x, y;
    x = ev->x();
    y = ev->y();

    QColor currentColor(img.pixel(x, y));
   // button->setText(QString::number(currentColor.red()) + ' ' + QString::number(currentColor.green()) + ' ' + QString::number(currentColor.blue()) );
   // int z = currentColor.red();
    button->setStyleSheet("background-color: rgb(" + QString::number(currentColor.red()) + "," + QString::number(currentColor.green()) + "," + QString::number(currentColor.blue()) + ")" );
}

