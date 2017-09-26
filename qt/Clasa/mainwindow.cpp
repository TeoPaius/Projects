#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->splitter_2->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_RDiff_clicked()
{
    if(ui->splitter_2->isVisible())
        ui->splitter_2->setVisible(false);
    else
        ui->splitter_2->setVisible(true);
}

void MainWindow::on_PBCls1_clicked()
{
    ui->HSlider->setValue(1);
}

void MainWindow::on_PBCls2_clicked()
{
     ui->HSlider->setValue(2);
}

void MainWindow::on_PBCls3_clicked()
{
     ui->HSlider->setValue(3);
}

