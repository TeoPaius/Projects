#ifndef EYEDROPPER_H
#define EYEDROPPER_H

#include "mylabel.h"
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>

namespace Ui {
class eyeDropper;
}

class eyeDropper : public QMainWindow
{
    Q_OBJECT

public:
    explicit eyeDropper(QWidget *parent = 0);
    ~eyeDropper();

private:
    Ui::eyeDropper *ui;
    QPushButton *button;
    myLabel *label;
    QHBoxLayout *layout;
};

#endif // EYEDROPPER_H
