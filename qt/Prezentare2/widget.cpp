#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QTimer>
int s = 50;
QString colors[] = {"background-color:red", "background-color:blue"};
int ccol = 0;
int cpos = 1;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    for(int i = 1; i <= 5; ++i)
    {
        row[i] = new QLabel(this);
        row[i]->setGeometry(20+i*s, 20, s, s);
    }
    row[1]->setStyleSheet(colors[ccol]);
    ccol = 1 - ccol;
    t = new QTimer(this);
    t->setInterval(1000);
    connect(t,SIGNAL(timeout()),SLOT(Move()));
    t->start();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::Move()
{
    row[cpos]->setStyleSheet("");
    if(cpos == 5)
        cpos = 1;
    else
        cpos++;
    row[cpos]->setStyleSheet(colors[ccol]);
    ccol = 1 - ccol;
}
