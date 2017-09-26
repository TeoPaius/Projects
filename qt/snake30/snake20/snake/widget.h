#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QPixmap>
#include <QTimer>
#include <QPushButton>
#include <QComboBox>

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
    QPixmap mouthclosed;
    QPixmap mouthstates[5];
    QPixmap nul;
    QTimer *t;
    QPushButton *loadButton;
    QComboBox *inputs;

    void Initialize();
    void Debug();
    void CreateBoard();
    void LoseMsg();



    void CreateMouths();
public slots:
    void Action();

private:
    Ui::Widget *ui;

protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // WIDGET_H
