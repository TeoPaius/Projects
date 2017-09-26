#ifndef SHIP_H
#define SHIP_H

#include <QObject>

class Ship : public QObject
{
    Q_OBJECT
public:
    explicit Ship(QObject *parent = 0);
    int length;
    int x, y;
    int orientation;

    void SetLength(int l);
    void SetPos(int _x, int _y);

signals:

public slots:
};

#endif // SHIP_H
