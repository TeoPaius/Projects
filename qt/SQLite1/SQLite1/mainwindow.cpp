#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSql>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlRecord>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OpenDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenDB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");

#ifdef Q_OS_LINUX

    QString path(QDir::home().path());
    path.append(QDir::separator()).append("mydb.sqlite");
    path = QDir::toNativeSeparators(path);
    db.setDatabaseName(path);
#else
    db.setDatabaseName("mydb.sqlite");
#endif

    // Open databasee
    db.open();
}

void MainWindow::CreateTable()
{ 
    if (db.isOpen())
    {
        QSqlQuery query;
        bool ok = query.exec("create table person "
                         "(id integer primary key, "
                         "firstname varchar(20), "
                         "lastname varchar(30), "
                         "age integer)");
        if (ok)
        {

            QSqlQuery query1;
            query1.exec(QString("insert into person values(1,'Ion','Popicu',60)"));
            query1.exec(QString("insert into person values(2,'Vasi','Marginean',40)"));
            query1.exec(QString("insert into person values(3,'Adrian','Gherghina',20)"));
        }
    }
    else
    {
        QMessageBox::warning(this, "Eroare", "Nu s-a putut deschide conexiunea!");
        return;
    }

    QSqlQuery query2(QString("select * from person"));

    // OK !!!
    cols = query2.record().count();

    ui->tableWidget->setColumnCount(cols);
   // ui->tableWidget->setColumnCount(cols);
    //ui->tableWidget->setRowCounts(squery.size()); // nu merge pe SQLite
    for (int i = 0; i < cols; ++i)
        ui->tableWidget->setHorizontalHeaderItem
                      (i, new QTableWidgetItem(query2.record().fieldName(i)));


    for (int i = 0; query2.next(); ++i)
    {
        ui->tableWidget->insertRow( ui->tableWidget->rowCount());
        for (int j = 0; j < cols; ++j)
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(query2.value(j).toString()));

    }

}

void MainWindow::ChooseDatabaseFile()
{
      if ( db.open())
           db.close();
      db = QSqlDatabase::addDatabase("QSQLITE");
      dbFile = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                       "/home/work",
                                                       tr("Database Files (*.sqlite);;All files (*)"));
     ui->dbLineEdit->setText(dbFile);
     QFileInfo fi(dbFile);
     //dbFile = fi.completeBaseName();
     dbFile = fi.fileName();
     db.setDatabaseName(dbFile);
     if ( !db.isOpen())
         db.open();

}

void MainWindow::on_connectButton_clicked()
{
    CreateTable();

}
