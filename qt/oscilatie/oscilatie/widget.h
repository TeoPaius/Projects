#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    QTimer *tim;
    QTimer *tim2;


    ~Widget();
    
public slots:
    void paintEvent(QPaintEvent *ev);
    void Change();
    void Conections();
    void Change2();
    void Draw(int k);


private:
    Ui::Widget *ui;
    double x, y;
    float A;
    float s;
    float t;
    double o;
    float t2;
    float r;
    float s2;
    float s3;
    float s4;
    float s5;
    float s6;
    float pi;
    float T;
};

#endif // WIDGET_H
