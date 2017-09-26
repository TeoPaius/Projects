#include "widget.h"
#include "ui_widget.h"
#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("F:/qt/projects/DatabaseProject1/db.sqlite");
    db.open();
    QSqlQuery q;
    q.exec("drop table Elev");
    if(q.exec("create table Elev(id int, nume varchar(10))"))
    {
        qDebug() << '1';
    }
    q.exec("insert into Elev(id, nume) values(1,'Alex')");

    QSqlQuery q2("select * from Elev");
    int cols = q2.record().count();
    ui->tableWidget->setColumnCount(cols);
    for(int i = 0; i < cols; ++i)
    {
        ui->tableWidget->setHorizontalHeaderItem(i,new QTableWidgetItem(q2.record().fieldName(i)));
    }
    for(int i = 0; q2.next(); ++i)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for(int j = 0; j < cols; ++j)
            ui->tableWidget->setItem(i,j, new QTableWidgetItem(q2.record().value(j).toString()));
    }

}

Widget::~Widget()
{
    delete ui;
}
