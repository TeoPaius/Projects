#include "widget.h"
#include "ui_widget.h"
#include "board.h"
#include "ship.h"
#include <QGridLayout>
#include <QLayoutItem>
#include <QLabel>
#include <QRect>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    tileSize = 30;

    b1 = new Board();
    CreateBoard(20,20,b1, meta1);
    CreateShips(p1S);
    //qDebug() << p1S[0]->orientation;
    PlaceShip(p1S[0]);

}

void Widget::CreateBoard(int x, int y, Board *b, QLabel *meta[11][11])
{

    for (int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            meta[i][j] = new QLabel(this);
            meta[i][j]->setGeometry(x+j*tileSize,y+i*tileSize,tileSize,tileSize);
            meta[i][j]->setStyleSheet("border-style:solid; border-width:1px; border-color:black; background-color:red");
        }
    }
}

void Widget::CreateShips(Ship *aux[])
{
    int auxlen = 1;
    for(int i = 0; i <= 4; ++i)
    {
        aux[i] = new Ship();
        aux[i]->SetLength(auxlen);
        auxlen++;
    }

    aux[0]->SetPos(0,0); ////////////////////////////////// hard


}

Widget::~Widget()
{
    delete ui;
}

void Widget::PlaceShip(Ship *s)
{
    int _i, _j;
    if(s->orientation == 0);
    {
        _i = 0;
        _j = 1;
    }
    if(s->orientation == 1);
    {
        _i = 1;
        _j = 0;
    }
    if(s->orientation == 2);
    {
        _i = 0;
        _j = -1;
    }
    if(s->orientation == 3);
    {
        _i = -1;
        _j = 0;
    }

    if(_i != 0)
        for(int j = s->x; j <= s->x + s->length; j+=_j)
        {
            meta1[s->x][j]->setStyleSheet("border-style:dotted; border-width:1px; border-color:white; background-color:green");
        }
    if(_j != 0)
        for(int i = s->y; i <= s->y + s->length; ++i)
        {
            meta1[s->y][i]->setStyleSheet("border-style:dotted; border-width:1px; border-color:white; background-color:green");
        }
}
