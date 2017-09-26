#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void OpenDB();
    void CreateTable();
public slots:
    void ChooseDatabaseFile();
private slots:
    void on_connectButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString dbFile;
    int cols;
};

#endif // MAINWINDOW_H
