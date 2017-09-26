#ifndef HYPERLINK_H
#define HYPERLINK_H

#include <QLabel>
#include <QMenu>
#include <QAction>

class HyperLink : public QLabel
{
    Q_OBJECT
public:
    explicit HyperLink(QWidget *parent = 0);
    QMenu* RClMenu;
    QAction* ActOpen;
    QAction* Action2;
    QAction* Action3;

signals:
    void Activated(QString);

public slots:
    void mousePressEvent(QMouseEvent* e);
    void enterEvent(QEvent* e);
    void leaveEvent(QEvent* e);
    void EmitActivated();

};

#endif // HYPERLINK_H
