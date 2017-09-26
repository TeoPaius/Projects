#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QGraphicsPathItem>

class MyShape : public QObject
{

    Q_OBJECT

public:
    explicit MyShape(QObject* parent = 0);
    MyShape();
    QPoint *shapeC;
    int crot;
    QGraphicsPathItem * obj;

    void SetShapeC(QPoint *x);

public slots:
    void Rot();

};

#endif // MYSHAPE_H
