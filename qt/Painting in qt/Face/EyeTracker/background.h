#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include <QGraphicsView>



class Background : public QGraphicsView
{

public:
    explicit Background(QWidget *parent = 0);


    void mouseMoveEvent(QMouseEvent *ev);

signals:
    //void Ok();

};

#endif // BACKGROUND_H
