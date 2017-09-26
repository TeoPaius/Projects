#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QComboBox>
#include <QLabel>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QListWidget>
#include <QSlider>



#include "SlidingStackedWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void createGuiControlComponents();
    void createMainLayout();
    void createSubSlidingWidgets();
    void createConnections();
    void createSlidingStackedWidget();
    QPushButton *buttonNext;
    QPushButton *buttonPrev;
    QCheckBox *checkWrap;
    QCheckBox *checkVertical;
    QSlider *slideSpeed;
    QComboBox *listAll;
    QLabel *speedLabel;
    QLCDNumber *speedDisplay;

    SlidingStackedWidget *slidingStacked;
    QVBoxLayout *mainLayout;
    QGridLayout *controlPaneLayout;
    QWidget *centralWidget;
    QWidget *slideWidget1;
    QWidget *slideWidget2;
    QWidget *slideWidget3;
    QWidget *slideWidget4;

    int animTime;
};

#endif // MAINWINDOW_H
