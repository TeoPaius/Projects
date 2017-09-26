#include "widget.h"
#include "ui_widget.h"




Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(Update()));
    connect(ui->pushButton,SIGNAL(released()),this,SLOT(Update()));

    /*
    while(clicked == true)
    {
        ui->label->setStyleSheet("background-color:red");
    }
    while(clicked == false)
    {
        ui->label->setStyleSheet("background-color:blue");
    }
    */
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Update()
{
    if(clicked == true)
        ui->label->setStyleSheet("background-color:red");
    if(clicked == false)
        ui->label->setStyleSheet("background-color:blue");
}

void Widget::on_pushButton_pressed()
{
    clicked = true;
    /*
    while(clicked == true)
    {
        ui->label->setStyleSheet("background-color:red");
    }
    */
}

void Widget::on_pushButton_released()
{
    clicked = false;
    /*
    while(clicked == false)
    {
        ui->label->setStyleSheet("background-color:blue");
    }
    */

}
