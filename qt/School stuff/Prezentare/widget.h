#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QLabel* row[6];
    QTimer* t;
    ~Widget();

public slots:
    void Move();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
