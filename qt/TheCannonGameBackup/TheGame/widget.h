#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QLabel>
#include "cannonfield.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);    
    void CreateObjects();
    void CreateGrids();
    void SetObjectSizes();
    void CreateConnections();
    void keyPressEvent(QKeyEvent *e);
    void Initializations();
    int shotsr, shotsf;
    int points;

    ~Widget();


protected:
    QWidget* centralWidget;
    QPushButton* fireButton;
    QLabel* shotsfLabel;
    QLabel* shotsrLabel;
    QLabel* pointsLabel;
    QLabel* angleLabel;
    QLabel* forceLabel;
    QLCDNumber* shotsfLCD;
    QLCDNumber* shotsrLCD;
    QLCDNumber* angleLCD;
    QLCDNumber* forceLCD;
    QLCDNumber* pointsLCD;
    QSlider* angleSlider;
    QSlider* forceSlider;
    CannonField* field;
    QGridLayout* mainGrid;
    QGridLayout* shotGrid;
    QGridLayout* transGrid;
    
public slots:

    void EnableChanges();
    void DisableChanges();
    void ShowGameEnded();
    void AddPoint();

private slots:



private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
