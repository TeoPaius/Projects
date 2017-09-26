#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    int w;
    int h;
    int cntrot;
    QTimer* t;
    int sign;
    ~Widget();
public slots:
    void paintEvent(QPaintEvent *e);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
