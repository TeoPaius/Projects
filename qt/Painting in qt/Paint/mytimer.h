#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>

namespace Ui
{
class MyTimer : public QTimer
{
    Q_OBJECT
public:
    explicit MyTimer(QWidget *parent = 0);

signals:

public slots:

private:
    Ui::MyTimer *ui1;

};
}
#endif // MYTIMER_H
