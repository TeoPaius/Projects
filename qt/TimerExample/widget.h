#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    //void UpdateLabel();
    QTimer *t;
    ~Widget();

public slots:
    void UpdateLabel();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
