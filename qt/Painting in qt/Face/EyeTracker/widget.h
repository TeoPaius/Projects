#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "background.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    Background *back;
    QPixmap *pix;
    QGraphicsPixmapItem *item;
    QGraphicsEllipseItem *reye;
    QGraphicsEllipseItem *rcircle;
    QGraphicsEllipseItem *leye;
    QGraphicsEllipseItem *lcircle;
    QGraphicsRectItem *rect;
    QGraphicsScene *scene;

    int circR;
    QPoint *p1;
    QPoint *p2;
    int circE;


    ~Widget();

    void ChangePixmap();


public slots:
    void Debug();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
