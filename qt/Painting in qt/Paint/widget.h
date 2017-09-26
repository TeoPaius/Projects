#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QPicture>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
