#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "myqstackedwidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CreateMainWidget();
    connect(leftButton, SIGNAL(pressed()), stWidget, SLOT(ShowLeft()));
    connect(rightButton, SIGNAL(pressed()), stWidget, SLOT(ShowRight()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CreateMainWidget()
{
    centralWidget = new QWidget();
    leftButton = new QPushButton("left");
    rightButton = new QPushButton("right");
    btnLayout = new QHBoxLayout();
    btnLayout->addWidget(leftButton);
    btnLayout->addWidget(rightButton);
    mainLayout = new QVBoxLayout();
    stWidget = new MyQStackedWidget();
    mainLayout->addWidget(stWidget);
    mainLayout->addLayout(btnLayout);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    sWid1 = new QWidget();
    sWid2 = new QWidget();
    sWid3 = new QWidget();
    sWidLay1 = new QVBoxLayout();
    sWidLay2 = new QVBoxLayout();
    sWidLay3 = new QVBoxLayout();
    button1 = new QPushButton("1");
    button2 = new QPushButton("2");
    button3 = new QPushButton("3");
    sWidLay1->addWidget(button1);
    sWidLay2->addWidget(button2);
    sWidLay3->addWidget(button3);
    sWid1->setLayout(sWidLay1);
    sWid2->setLayout(sWidLay2);
    sWid3->setLayout(sWidLay3);
    stWidget->addWidget(sWid1);
    stWidget->addWidget(sWid2);
    stWidget->addWidget(sWid3);

}
