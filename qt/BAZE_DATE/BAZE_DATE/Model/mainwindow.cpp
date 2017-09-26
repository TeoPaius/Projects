#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setWindowTitle("Model");

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("test");
   db.setUserName("root");
    db.setPassword("teodor12");

    if (!db.open())
    {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                             "faf");



    }
    else
    {
        QSqlQuery q;
        q.exec("create table Chestie (id int, nume varchar(10))");


        QSqlQueryModel* model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Chestie");
      // model->setHeaderData(0, Qt::Horizontal, "Nume");
       //model->setHeaderData(1, Qt::Horizontal, "Prenume");
     model->setHeaderData(2, Qt::Horizontal, "Adresa");
      model->setHeaderData(3, Qt::Horizontal, "Orasul");

        ui->tableView->setModel(model);
        ui->tableView->show();
    }
}

MainWindow::~MainWindow()
{
    QSqlQuery q2;
    q2.exec("drop table Chestie");
    delete ui;
}
