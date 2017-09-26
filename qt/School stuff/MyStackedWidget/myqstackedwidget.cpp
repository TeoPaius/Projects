#include "myqstackedwidget.h"
#include <QPoint>
#include <QStackedWidget>

#include <QtGui>
#include <QWidget>
#include <QDebug>
#include <QEasingCurve>


MyQStackedWidget::MyQStackedWidget(QWidget *parent) :
    QStackedWidget(parent)
{
    m_speed = 500;
    m_active = false;

}


void MyQStackedWidget::ShowLeft()
{
    if(m_active)
        return;
    int now = currentIndex();
    now+=1;
    if(now >count()- 1)
    {
        now = 0;
    }
    SlideToIdx(widget(now), RIGHT2LEFT);


}

void MyQStackedWidget::ShowRight()
{
    if(m_active)
        return;
    int now = currentIndex();
    now-=1;
    if(now < 0)
        now = count()-1;
    SlideToIdx(widget(now), LEFT2RIGHT);

}


void MyQStackedWidget::SlideToIdx(QWidget* newWidget, enum t_direction direction)
{
    int now = currentIndex();
    m_now = now;
    int next = indexOf(newWidget);
    m_next = next;


    if(now == next)
    {
        m_active = false;
        return;
    }

    int offsetx = frameRect().width();
    int offsety = frameRect().height();

    widget(next)->setGeometry(0,0,offsetx, offsety);

    if(direction == RIGHT2LEFT)
    {
        offsetx = -offsetx;
        offsety = 0;
    }
    else if(direction == LEFT2RIGHT)
    {
        offsety = 0;
    }
    QPoint pnow = widget(now)->pos();
    QPoint pnext = widget(next)->pos();
    m_pnow = pnow;

    widget(next)->move(pnow.x() - offsetx, pnow.y() - offsety);
    widget(next)->show();
    widget(next)->raise();

    QPropertyAnimation *animnow = new QPropertyAnimation(widget(now),"pos");
    animnow->setDuration(1000);
    animnow->setEasingCurve(QEasingCurve::OutBack);
    animnow->setStartValue(pnow);
    animnow->setEndValue(QPoint(offsetx+pnow.x(), offsety+pnow.y()));

    QPropertyAnimation *animnext = new QPropertyAnimation(widget(next),"pos");
    animnext->setDuration(1000);
    animnext->setEasingCurve(QEasingCurve::OutBack);
    animnext->setEndValue(pnext);
    animnext->setStartValue(QPoint(-offsetx+pnext.x(), offsety+pnext.y()));

    QParallelAnimationGroup* animgroup = new QParallelAnimationGroup;
    animgroup->addAnimation(animnow);
    animgroup->addAnimation(animnext);

    m_active = true;
    m_now = now;
    m_next =next;
    connect(animgroup,SIGNAL(finished()),this,SLOT(AnimationDone()));
    animgroup->start();



}


void MyQStackedWidget::AnimationDone()
{
    m_active = false;
    widget(m_now)->hide();
    widget(m_now)->move(m_pnow);
    setCurrentIndex(m_next);
    emit animationFinished();
}
