#ifndef MYQSTACKEDWIDGET_H
#define MYQSTACKEDWIDGET_H

#include <QStackedWidget>
#include <QStackedWidget>

#include <QtGui>
#include <QWidget>
#include <QDebug>
#include <QEasingCurve>

class MyQStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit MyQStackedWidget(QWidget *parent = 0);
    enum t_direction{
        LEFT2RIGHT,
        RIGHT2LEFT
    };

signals:

protected:
    int m_speed;
    int m_active;
    int m_now;
    int m_next;
    QPoint m_pnow;
    QPoint m_pnext;

signals:
    void animationFinished(void);

public slots:
    void ShowLeft();
    void ShowRight();
    void SlideToIdx(QWidget *newWidget, t_direction direction);
    void AnimationDone();

};

#endif // MYQSTACKEDWIDGET_H
