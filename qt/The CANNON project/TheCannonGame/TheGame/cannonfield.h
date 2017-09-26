#ifndef CANNONFIELD_H
#define CANNONFIELD_H

#include <QWidget>
#include "extraspace.h"

class CannonField : public QWidget
{
    Q_OBJECT
public:
    explicit  CannonField(QWidget *parent = 0);
    int w;
    int h;
    int cntrot;
    double cntforce;
    QTimer* t;
    QTimer* shotTimer;
    int speed;
    int sign;
    double G;
    double targetCx;
    double targetCy;
    bool targetHit;
    double targetsize;

    double shotx;
    double shoty;
    double previousx;
    double previousy;
    int constant;
    double startx;
    double starty;

    double Vx;
    double Vy;
    double trajectory_angle;
    double auxcntrot;

    bool started;
    bool isBox;
    int time_elapsed;

    ExtraSpace* spaces[100];
    int spacescnt;

    ~CannonField();

    void BoxChangeXY();
    void AddExtraSpace();
protected:

public slots:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void SetAngle(int val);
    void SetForce(int val);
    void StartShot();
    void EndShot();
    void ChangeXY();
    void ChangeTarget();
    void DrawTarget(QPainter* xp);

signals:
    void AngleChanged(int val);
    void ForceChanged(int val);
    void ShotStarted();
    void ShotEnded();
    void TargetWasHit();
    void ModeChanged(bool val);

    
public slots:
    
};

#endif // CANNONFIELD_H
