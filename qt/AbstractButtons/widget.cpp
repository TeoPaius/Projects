#include "widget.h"
#include "ui_widget.h"

#include <QAbstractButton>
#include <QMessageBox>
#include <QDialogButtonBox>

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

void Widget::on_Pb1_clicked()
{

    QMessageBox m;
    m.setText("intrebare");
    QAbstractButton* x = m.addButton("da",QMessageBox::AcceptRole);
    QAbstractButton* y = m.addButton("nu",QMessageBox::RejectRole);
    m.exec();
    if(m.clickedButton() == x)
    {
        ui->Pb1->setText("da");
    }
    if(m.clickedButton() == y)
    {
        ui->Pb1->setText("nu");
    }



}
