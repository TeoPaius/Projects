#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QPixmap>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void MoveSnake(int i, int j);
    void MoveHeadOverTail(int it, int jt, int ih, int jh);
    void EatApple(int ia, int ja );
    void AssingApple();

    ~Widget();
    QLabel *board[100][100];
    QPixmap open;
    QPixmap shut;
    QPixmap mouth[2];
    QPixmap zero;
    QTimer *t;

    void Initialize();
    void Debug();
    void CreateBoard();
    void LoseMsg();



public slots:
    void Action();

private:
    Ui::Widget *ui;

protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // WIDGET_H
