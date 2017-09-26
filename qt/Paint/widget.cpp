#include "widget.h"
#include "ui_widget.h"
#include <QtGui>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QGraphicsView>
#include <QMouseEvent>

int cnt;
int cntp;
QPoint s[100];
bool pressed;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    cnt++;

    QPen p;
    p.setColor(Qt::red);


}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter paint(this);
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(5);
    paint.setPen(pen);
    for(int i = 1; i <= cntp; ++i)
        paint.drawPoint(s[i]);

}

void Widget::mousePressEvent(QMouseEvent *e)
{

    if(e->button() == Qt::LeftButton)
    {
        pressed = true;
        ui->pushButton->setText("succes");
        QPoint point = e->pos();
        cntp++;
        s[cntp] = point;

    }
     update();

}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        pressed = false;
        ui->pushButton->setText("ok");
    }
}
