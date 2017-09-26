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
    ~Widget();

protected:
    void paintEvent(QPaintEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);

private slots:
    void on_PointButton_clicked();

    void on_LineButton_clicked();

    void on_UPointButton_clicked();

    void on_ULineButton_clicked();



    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
