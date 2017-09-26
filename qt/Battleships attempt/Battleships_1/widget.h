#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "board.h"
#include "ship.h"
#include <QGridLayout>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    Board *b1;
    Board *b2;


    QLabel *meta1[11][11];
    QLabel *meta2[11][11];

    Ship *p1S[6];
    Ship *p2S[6];


    int tileSize;


    void CreateBoard(int x, int y, Board *b, QLabel *meta[11][11]);
    void CreateShips(Ship * aux[6]);
    ~Widget();

public slots:
    void PlaceShip(Ship *s);



private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
