#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QLabel *board[100][100];


private:
    Ui::Widget *ui;

protected:
    void keyPressEvent(QKeyEvent *e);

public slots:
    void Move();
};

#endif // WIDGET_H
