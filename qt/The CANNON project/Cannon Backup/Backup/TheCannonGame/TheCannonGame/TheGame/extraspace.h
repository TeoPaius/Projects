#ifndef EXTRASPACE_H
#define EXTRASPACE_H

#include <QWidget>
#include <QPoint>

class ExtraSpace : public QWidget
{
    Q_OBJECT
public:
    explicit ExtraSpace(QWidget *parent = 0);

    QPoint shotPoint;
    bool isShotHere;

signals:

public slots:
    void paintEvent(QPaintEvent *e);
    void DrawDotOnPoint(QPoint point);

};

#endif // EXTRASPACE_H
