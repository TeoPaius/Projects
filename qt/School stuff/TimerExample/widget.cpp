#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

int aux = 1;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    t = new QTimer(this);
    t->setInterval(1000);
    connect(t,SIGNAL(timeout()),this,SLOT(UpdateLabel()));
    t->start();
}

void Widget::UpdateLabel()
{
    if(aux == 1)
    {
        aux = 0;
        ui->label->setText("1");
    }
    else if(aux == 0)
    {
        aux = 1;
        ui->label->setText("0");
    }
    //t->start();
}

Widget::~Widget()
{
    delete ui;
}
