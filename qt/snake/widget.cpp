#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QKeyEvent>
#include <QMessageBox>
#include <QString>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QTime>
#include <QPixmap>
#include <QTimer>



struct Pos{
    int x;
    int y;
};



int s = 20;
int cnt;
int coordi, coordj;
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int dir; // 1-sus, 2-dreapta, 3-jos, 4-stanga
int iv, jv, ci, cj;
int meta[31][31]; // 1-snake, 2-apple, 3-wall(maybe), 0-liber
Pos sons[31][31]; // s[i][j] = -1 coada
int screenw, screenh;
bool moved;
int cntscore = 6;
int state = 1; //1 deschis, 2 inchis
bool gameended = true;

QString aux;
int dcnt;

void Widget::Initialize()
{

    for(int i = 0; i <= 21; ++i)
    {
        board[0][i]->setStyleSheet("background-color:black");
        board[i][21]->setStyleSheet("background-color:black");
        board[21][i]->setStyleSheet("background-color:black");
        board[i][0]->setStyleSheet("background-color:black");
        meta[0][i] = 3;
        meta[i][21] = 3;
        meta[i][0] = 3;
        meta[21][i] = 3;

    }

    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= 20; ++j)
        {
             board[i][j]->setStyleSheet("");
             sons[i][j].x = 0;
             sons[i][j].y = 0;
             meta[i][j] = 0;
        }

    board[1][1]->setStyleSheet("background-color: lime");
    board[1][2]->setStyleSheet("background-color: lime");
    board[1][3]->setStyleSheet("background-color: lime");
    board[1][4]->setStyleSheet("background-color: lime");
    board[1][5]->setStyleSheet("background-color: lime");
    board[1][6]->setStyleSheet("background-color: darkgreen");
    //board[1][6]->setPixmap(mouth[0]);
    meta[1][1] = 1;
    meta[1][2] = 1;
    meta[1][3] = 1;
    meta[1][4] = 1;
    meta[1][5] = 1;
    meta[1][6] = 1;
    sons[1][1].x = -1;
    sons[1][1].y = -1;
    sons[1][3].x = 1;
    sons[1][3].y = 2;
    sons[1][4].x = 1;
    sons[1][4].y = 3;
    sons[1][2].x = 1;
    sons[1][2].y = 1;
    sons[1][5].x = 1;
    sons[1][5].y = 4;
    sons[1][6].x = 1;
    sons[1][6].y = 5;
    ci = 1;
    cj = 6;

    gameended = false;
    iv = ci + di[dir-1];
    jv = cj + dj[dir-1];

    AssingApple();

    open.load(":/img/open.png");
    open = open.scaled(ui->label_3->size(), Qt::KeepAspectRatio);
    ui->label_3->setPixmap(open);
    t->stop();

   // Debug();
}

void Widget::CreateBoard()
{
    this->setFocusPolicy(Qt::StrongFocus);
    for(int i = 0; i <= 21; i++)
        for(int j = 0; j <= 21; ++j)
        {
            board[i][j] = new QLabel(this);
            coordi = 5 + i * s;
            coordj = 5 + j * s;
            board[i][j]->setGeometry(coordj, coordi, s, s); // dubios
        }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    screenw = QApplication::desktop()->width();
    screenh = QApplication::desktop()->height();

    open.load(":/img/open.png");
    shut.load(":/img/shut.png");
    open = open.scaled(20,20,Qt::KeepAspectRatio);
    shut = shut.scaled(20,20, Qt::KeepAspectRatio);
    mouth[0] = open;
    mouth[1] = shut;
    t = new QTimer(this);

    t->setInterval(100);
    t->setSingleShot(true);
    connect(t,SIGNAL(timeout()),SLOT(Action()));


    CreateBoard();
    Initialize();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::Debug()
{
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= 20; ++j)
        {
           // board[i][j]->setText(QString::number(sons[i][j].x)+QString::number(sons[i][j].y));
            board[i][j]->setText(QString::number(meta[i][j]));
        }
}

void Widget::LoseMsg()
{
    t->stop();
    gameended = true;
    QMessageBox q(this);
    q.setText("You LOST!!");
    q.setWindowTitle("You crushed");
    q.exec();
}

void Widget::Action()
{
    this->setFocusPolicy(Qt::StrongFocus);



    if(jv == 0 || jv == 21 || iv == 0 || iv == 21)
    {
        //ui->debButton->setText("ok");
        LoseMsg();
        moved = true;
        gameended = true;
        t->stop();
        Initialize();
        return;
    }

    if(!gameended)
    {
        if(meta[iv][jv] == 1)
        {
            if((iv == sons[ci][cj].x && jv == sons[ci][cj].y) && !moved)
            {
                moved = true;
                //ui->debButton->setText("1");
                //Debug();
            }
            if((sons[iv][jv].x == -1 && sons[iv][jv].y == -1) && !moved)
            {
                moved = true;
                MoveHeadOverTail(iv, jv, ci,cj);
                //ui->debButton->setText("2");
               // Debug();
            }
            if(sons[iv][jv].x != 0 && sons[iv][jv].y != 0 && !moved)
            {
                LoseMsg();
                moved = true;
                Initialize();
            }
        }

        else if(meta[iv][jv] == 2 && !moved)
        {
            EatApple(iv,jv);
            moved = true;
            ci = iv;
            cj = jv;
            //Debug();
        }


        if( !moved )
        {
            moved = true;
            dcnt = 0;
            MoveSnake(ci,cj);   // schimba iv si jv
       //     Debug();
            //ui->debButton->setText("2");
            ci = ci + di[dir-1];
            cj = cj + dj[dir-1];
        }

        moved = false;
        t->stop();
        t->start();
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        ui->DebButon->setText(QString::number(iv) + ' ' + QString::number(jv));

    }


}

void Widget::keyPressEvent(QKeyEvent *e)
{

    moved = false;
    gameended = false;


    if(e->key() == Qt::Key_Up)
    {
        t->stop();
        dir = 1;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Action();

    }
    if(e->key() == Qt::Key_Right)
    {
        t->stop();
        dir = 2;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Action();


    }
    if(e->key() == Qt::Key_Down)
    {
        t->stop();
        dir = 3;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Action();

    }
    if(e->key() == Qt::Key_Left)
    {
        t->stop();
        dir = 4;
        iv = ci + di[dir-1];
        jv = cj + dj[dir-1];
        Action();

    }

    if(!gameended)
    {
        //ui->DebButon->setText("end");
    }



    /*
    board[ci][cj]->clear();
    board[ci][cj]->setStyleSheet("background-color: darkgreen");
    ui->label_3->clear();
    ui->label_3->setStyleSheet("background-color: darkgreen");
    */

    /*
    board[ci][cj]->setStyleSheet("");
   board[ci][cj]->setPixmap(mouth[0]);

   ui->label_3->setStyleSheet("");
    ui->label_3->setPixmap(shut);

    */

}

void Widget::MoveSnake(int i, int j)
{
    //ui->debButton->setText(QString::number(iv)+ ' ' +QString::number(jv));
    aux = board[iv][jv]->styleSheet();
    board[iv][jv]->setStyleSheet(board[i][j]->styleSheet());
    board[i][j]->setStyleSheet(aux);
   // ui->debButton->setText(board[iv][jv]->styleSheet());
    meta[iv][jv] = 1;



    if(sons[i][j].x == -1 && sons[i][j].y == -1)
    {
        sons[iv][jv].x = -1;
        sons[iv][jv].y = -1;
        sons[i][j].x = 0;
        sons[i][j].y = 0;
        meta[i][j] = 0;

        //ui->debButton->setText(QString::number(dcnt));
        return;
    }
    dcnt++;
    sons[iv][jv].x = i;
    sons[iv][jv].y = j;
    iv = i;
    jv = j;

    MoveSnake(sons[i][j].x, sons[i][j].y);


}

void Widget::MoveHeadOverTail(int it, int jt, int ih, int jh)
{
    aux = board[it][jt]->styleSheet();
    board[it][jt]->setStyleSheet(board[ih][jh]->styleSheet());
    board[ih][jh]->setStyleSheet(aux);

    int tjv, tiv;
    for(int i = 0; i <= 3; ++i)
    {
        tiv = it + di[i];
        tjv = jt + dj[i];
        if(sons[tiv][tjv].x == it && sons[tiv][tjv].y == jt)
        {
            sons[tiv][tjv].x = -1;
            sons[tiv][tjv].y = -1;
            break;
        }
    }
    sons[it][jt].x = ih;
    sons[it][jt].y = jh;

    ci = it;
    cj = jt;


}

void Widget::EatApple(int ia, int ja)
{
    sons[ia][ja].x = ci;
    sons[ia][ja].y = cj;
    board[ia][ja]->setStyleSheet("background-color: darkgreen");
    board[ci][cj]->setStyleSheet("background-color: lime");
    meta[ia][ja] = 1;
    cntscore++;
    ui->LScore->setText(QString::number(cntscore));
    AssingApple();

}

void Widget::AssingApple()
{
    int applei, applej;
    qsrand(QTime::currentTime().msec());
    do
    {
        applei = qrand() % 20 + 1;
        applej = qrand() % 20 + 1;
    }
    while(meta[applei][applej] != 0);

    board[applei][applej]->setStyleSheet("background-color:red");
    meta[applei][applej] = 2;


}
