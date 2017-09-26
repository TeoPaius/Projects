#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>
#include <QTimer>

int coordi, coordj;
int s = 20;
int dir;
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int iv, jv;
int ci, cj;
QTimer *t;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    t = new QTimer(this);
    t->setInterval(1000);
    t->setSingleShot(true);
    connect(t,SIGNAL(timeout()),SLOT(Move()));
    this->setFocusPolicy(Qt::StrongFocus);
    for(int i = 0; i <= 6; i++)
        for(int j = 0; j <= 6; ++j)
        {
            board[i][j] = new QLabel(this);
            coordi = 5 + i * s;
            coordj = 5 + j * s;
            board[i][j]->setGeometry(coordj, coordi, s, s);
        }

    for(int i = 0; i <= 6; ++i)
    {
        board[0][i]->setStyleSheet("background-color:black");
        board[i][6]->setStyleSheet("background-color:black");
        board[6][i]->setStyleSheet("background-color:black");
        board[i][0]->setStyleSheet("background-color:black");

    }

    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; ++j)
        {
             board[i][j]->setStyleSheet("");
        }

    board[1][1]->setStyleSheet("background-color: lime");
    ci = 1;
    cj = 1;



}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Up)
    {
        t->stop();
        dir = 1;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Move();


    }
    if(e->key() == Qt::Key_Right)
    {
        t->stop();
        dir = 2;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Move();



    }
    if(e->key() == Qt::Key_Down)
    {
        t->stop();
        dir = 3;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Move();


    }
    if(e->key() == Qt::Key_Left)
    {
        t->stop();
        dir = 4;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Move();



    }
}


Widget::~Widget()
{
    delete ui;
}

void Widget::Move()
{
    board[iv][jv]->setStyleSheet("background-color: lime");
    board[ci][cj]->setStyleSheet("");
    ci = iv;
    cj = jv;
    iv = ci + di[dir-1];
    jv = cj + dj[dir-1];
    t->stop();
    t->start();

}


