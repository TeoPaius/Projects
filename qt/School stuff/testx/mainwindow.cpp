#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
