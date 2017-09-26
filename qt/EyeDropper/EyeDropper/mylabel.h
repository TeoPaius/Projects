#ifndef MYLABEL_H
#define MYLABEL_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QImage>

class myLabel : public QLabel
{
    Q_OBJECT
public:
   explicit myLabel(QWidget *parent = 0, QPushButton *btn = 0);
    ~myLabel();

private:
    QPushButton *button;
    QImage img;
    //int *x, *y;
    //QImage *img;

protected:
    void mousePressEvent(QMouseEvent *ev);
};

#endif // MYLABEL_H
