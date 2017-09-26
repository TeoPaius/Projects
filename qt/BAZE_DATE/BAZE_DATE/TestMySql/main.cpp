#include <QApplication>
#include <QtWidgets>
#include <QtSql>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlQueryModel>


int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    QTableWidget* table = new QTableWidget();
    table->setWindowTitle("Connect to Mysql Database Example");
    table->setGeometry(300, 300, 600, 400);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   /* db.setHostName("192.168.1.17");
    db.setDatabaseName("eval");
    db.setUserName("root");
    db.setPassword("iuliuta");
*/
     db.setHostName("localhost");
     db.setDatabaseName("Company");
     db.setUserName("root");
     db.setPassword("iuliuta");

if (!db.open())
    {
      QMessageBox::critical(0, QObject::tr("Database Error"),
                db.lastError().text());

    }
    else
    {
/*          OK !!!
        QSqlQuery query("SELECT * FROM useri");

        int cols = query.record().count();
        table->setColumnCount(cols);
        table->setRowCount(query.size());

        for (int i = 0; i < cols; ++i)
            table->setHorizontalHeaderItem
                    (i, new QTableWidgetItem(query.record().fieldName(i)));


        // atentie la memory leak

        for (int i = 0; query.next(); ++i)
            for (int j = 0; j < cols; ++j)
                table->setItem(i, j, new QTableWidgetItem(query.value(j).toString()));
    }
    table->show();
  */

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT LastName, FirstName, Address, City FROM Pers");
 //   model->setHeaderData(0, Qt::Horizontal, "Nume");
//    model->setHeaderData(1, Qt::Horizontal, "Prenume");
    model->setHeaderData(2, Qt::Horizontal, "Adresa");
    model->setHeaderData(3, Qt::Horizontal, "Orasul");

    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();

}

    return app.exec();
}
