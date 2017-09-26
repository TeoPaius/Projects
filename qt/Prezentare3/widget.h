#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QLabel;
class QTimer;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void Move();

private:
    Ui::Widget *ui;
    QLabel* row[6];
    QTimer* t;
};

#endif // WIDGET_H
