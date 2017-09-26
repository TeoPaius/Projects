#include "widget.h"
#include "ui_widget.h"
#include <QtGui>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QLine>
#include <QColor>

int cnt;
int cntp, cntl;
QPoint s[1000];
QLine l[1000];
QColor col[] = {Qt::red, Qt::blue, Qt::green};

int cols[1000];
int coll[1000];

int colidx;

int shape;
bool pressed;
QPoint start, end;
QLine aux;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    ui->comboBox->clearFocus();

}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *e)
{
    QPainter paint(this);
    QPen pen;

    pen.setWidth(5);
    pen.setCapStyle(Qt::RoundCap);

    for(int i = 1; i <= cntp; ++i)
    {
        pen.setColor(col[cols[i]]);
        paint.setPen(pen);
        paint.drawPoint(s[i]);
    }
    for(int i = 1; i <= cntl; ++i)
    {
        pen.setColor(col[coll[i]]);
        paint.setPen(pen);
        paint.drawLine(l[i]);
    }

}

void Widget::mousePressEvent(QMouseEvent *e)
{
    this->setCursor(Qt::ClosedHandCursor);
    if(shape == 0)
    {
        if(e->button() == Qt::LeftButton)
        {
            pressed = true;
            //ui->PointButton->setText("succes");
            QPoint point = e->pos();
            cntp++;
            s[cntp] = point;
            cols[cntp] = colidx;

        }
    }
    if(shape == 1)
    {
        if(e->button() == Qt::LeftButton)
        {
            if(start.isNull())
            {
                start = e->pos();
                end.setX(0);
                end.setY(0);
            }
            /*
            else
            {
                end = e->pos();
                cntl++;
                aux.setP1(start);
                aux.setP2(end);
                l[cntl] = aux;
                start.setX(0);
                start.setY(0);
            }*/
        }

    }
    update();

}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    this->setCursor(Qt::OpenHandCursor);
    if(shape == 1)
    {
        end = e->pos();
        cntl++;
        aux.setP1(start);
        aux.setP2(end);
        l[cntl] = aux;
        start.setX(0);
        start.setY(0);
        coll[cntl] = colidx;
    }
    update();
}

void Widget::on_PointButton_clicked()
{
    shape = 0;
    start.setX(0);
    start.setY(0);
    end.setX(0);
    end.setY(0);
}

void Widget::on_LineButton_clicked()
{
    shape = 1;
}

void Widget::on_UPointButton_clicked()
{
    cntp--;
    update();
}

void Widget::on_ULineButton_clicked()
{
    cntl--;
    update();
}

void Widget::on_comboBox_currentIndexChanged(int index)
{
    QString colaux;
    colidx = index;
    switch(index)
    {
    case 0: colaux = "red"; break;
    case 1: colaux = "blue"; break;
    case 2: colaux = "green"; break;
    default: colaux = "white"; break;
    }

    ui->comboBox->setStyleSheet("background-color:" + colaux + ";");
    ui->comboBox->clearFocus();
}
