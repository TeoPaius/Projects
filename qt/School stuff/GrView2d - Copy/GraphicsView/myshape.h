#ifndef MYSHAPE_H
#define MYSHAPE_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QGraphicsPathItem>
#include <QColor>

class MyShape : public QObject
{

    Q_OBJECT

public:
    explicit MyShape(QObject* parent = 0);
    QPoint *shapeC;
    int crot;
    QGraphicsPathItem* obj;
    int period;
    QColor color;
    QColor grStart;
    QColor grEnd;
    int dir;


    void SetShapeC(QPoint *x);
    void SetPeriod(int x);
    void SetColor(QColor x);
    void SetGradient(QColor startColor, QColor endColor);
    void SetDirection(int _dir);

public slots:
    void Rot();

signals:
    void RotDone();

};

#endif // MYSHAPE_H
