#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "myqstackedwidget.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


protected:
    QWidget* centralWidget;
    QPushButton* leftButton;
    QPushButton* rightButton;
    QHBoxLayout* btnLayout;
    QVBoxLayout* mainLayout;
    MyQStackedWidget* stWidget;
    QWidget* sWid1;
    QWidget* sWid2;
    QWidget* sWid3;
    QVBoxLayout* sWidLay1;
    QVBoxLayout* sWidLay2;\
    QVBoxLayout* sWidLay3;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;


    void CreateMainWidget();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
