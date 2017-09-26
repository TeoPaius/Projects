#include "hyperlink.h"
#include <QMouseEvent>
#include <QEvent>
#include <QAction>
#include <QMenu>

HyperLink::HyperLink(QWidget *parent) :
    QLabel(parent)
{
    //setMouseTracking(true);
    RClMenu = new QMenu(this);
    ActOpen = RClMenu->addAction("Open link in new tab");
    Action2 = RClMenu->addAction("Action2");
    Action3 = RClMenu->addAction("Action3");
    connect(ActOpen,SIGNAL(triggered()),this,SLOT(EmitActivated()));
}

void HyperLink::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        RClMenu->move(this->mapToGlobal(e->pos()));
        RClMenu->exec();
    }

}

void HyperLink::enterEvent(QEvent *e)
{
    this->setStyleSheet("color:blue; text-decoration: underline;");
}

void HyperLink::leaveEvent(QEvent *e)
{
    this->setStyleSheet("");

}

void HyperLink::EmitActivated()
{
    emit Activated(this->text());
}
