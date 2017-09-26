#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QLCDNumber>
#include <QSlider>
#include <QLabel>
#include "cannonfield.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <QThread>
#include <QtMultimedia/QSound>

void Widget::Initializations()
{
    angleLCD->display(45);
    shotsrLCD->display(10);
    shotsfLCD->display(0);
    pointsLCD->display(0);
    shotsf = 0;
    shotsr = 10;
    points = 0;
    spacescnt = 0;
    angleSlider->setFocusPolicy(Qt::NoFocus);
    forceSlider->setFocusPolicy(Qt::NoFocus);
    fireButton->setFocusPolicy(Qt::NoFocus);
    boxCheckBox->setFocusPolicy(Qt::NoFocus);
    boxCheckBox->setChecked(true);
    //this->setFocus();
    field->setFocus();
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    CreateObjects();
    CreateGrids();
    SetObjectSizes();
    CreateConnections();
    Initializations();


}

void Widget::CreateObjects()
{
    fireButton = new QPushButton("Fire!!");
    field = new CannonField(this);
    angleLabel = new QLabel("Angle");
    forceLabel = new QLabel("Force");
    shotsfLabel = new QLabel("Fired");
    shotsrLabel = new QLabel("Remaining");
    pointsLabel = new QLabel("Points");
    shotsfLCD = new QLCDNumber(2);
    shotsrLCD = new QLCDNumber(2);
    pointsLCD = new QLCDNumber(2);
    angleLCD = new QLCDNumber(2);
    forceLCD = new QLCDNumber(3);
    angleSlider = new QSlider(Qt::Horizontal);
    forceSlider = new QSlider(Qt::Horizontal);
    shotGrid = new QGridLayout();
    mainGrid = new QGridLayout();
    transGrid = new QGridLayout();



    extraGrid = new QGridLayout();
    boxCheckBox = new QCheckBox("Box mode");
    boxCheckBox->setChecked(true);
    addSpaceButton = new QPushButton("Add extra space");


    angleSlider->setMaximum(90);
    angleSlider->setValue(45);
    forceSlider->setMaximum(100);

    shotsfLCD->setSegmentStyle(QLCDNumber::Flat);
    shotsrLCD->setSegmentStyle(QLCDNumber::Flat);
    pointsLCD->setSegmentStyle(QLCDNumber::Flat);
    angleLCD->setSegmentStyle(QLCDNumber::Flat);
    forceLCD->setSegmentStyle(QLCDNumber::Flat);




}

void Widget::CreateGrids()
{
    shotGrid->addWidget(shotsfLabel,1,1,1,1);
    shotGrid->addWidget(shotsfLCD,2,1,1,1);
    shotGrid->addWidget(shotsrLabel,1,2,1,1);
    shotGrid->addWidget(shotsrLCD,2,2,1,1);
    shotGrid->addWidget(pointsLabel,1,3,1,1);
    shotGrid->addWidget(pointsLCD,2,3,1,1);

    transGrid->addWidget(angleLabel,1,1,1,1);
    transGrid->addWidget(angleLCD,2,1,1,1);
    transGrid->addWidget(angleSlider,3,1,1,1);
    transGrid->addWidget(forceLabel,4,1,1,1);
    transGrid->addWidget(forceLCD,5,1,1,1);
    transGrid->addWidget(forceSlider,6,1,1,1);

    extraGrid->addWidget(boxCheckBox,1,1,1,1);
  // extraGrid->addWidget(addSpaceButton,1,3,1,1);

    mainGrid->addWidget(fireButton,1,1,1,1);
    mainGrid->addLayout(shotGrid,1,2,1,3);
    mainGrid->addLayout(transGrid,2,1,3,1);
    mainGrid->addLayout(extraGrid,7,1,1,4);
    mainGrid->addWidget(field,2,2,3,3);

    this->setLayout(mainGrid);


}

void Widget::SetObjectSizes()
{

    fireButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    angleLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    angleLCD->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    angleSlider->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    forceLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    forceLCD->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    forceSlider->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    shotsfLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    shotsfLCD->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    shotsrLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    shotsrLCD->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pointsLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pointsLCD->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
   // field->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    angleSlider->setMinimumWidth(150);
    forceSlider->setMinimumWidth(150);
    field->setMinimumSize(300,300);



}

void Widget::CreateConnections()
{
    connect(angleSlider,SIGNAL(valueChanged(int)),angleLCD,SLOT(display(int)));
    connect(forceSlider,SIGNAL(valueChanged(int)),forceLCD,SLOT(display(int)));
    connect(angleSlider,SIGNAL(valueChanged(int)),field,SLOT(SetAngle(int)));
    connect(forceSlider,SIGNAL(valueChanged(int)),field,SLOT(SetForce(int)));
    connect(field,SIGNAL(AngleChanged(int)),angleSlider,SLOT(setValue(int)));
    connect(field,SIGNAL(ForceChanged(int)),forceSlider,SLOT(setValue(int)));
    connect(fireButton,SIGNAL(clicked()),field,SLOT(StartShot()));
    connect(field,SIGNAL(ShotStarted()),this,SLOT(DisableChanges()));
    connect(field,SIGNAL(ShotEnded()),this,SLOT(EnableChanges()));
    connect(field,SIGNAL(TargetWasHit()),this,SLOT(AddPoint()));
    connect(addSpaceButton,SIGNAL(clicked(bool)),field,SLOT(AddExtraSpace()));
    connect(boxCheckBox,SIGNAL(clicked(bool)),field,SLOT(ChangeMode()));


    connect(field,SIGNAL(ModeChanged(bool)),boxCheckBox,SLOT(setChecked(bool)));
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(!field->started)
    {
        if(e->key() == Qt::Key_Up)
        {
            angleSlider->setValue(angleSlider->value()+1);
        }
        if(e->key() == Qt::Key_Down)
        {
            angleSlider->setValue(angleSlider->value()-1);
        }

        if(e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter )
        {
            shotsfLabel->setText("debug");
            emit fireButton->clicked();
        }

    }
}

void Widget::EnableChanges()
{
    if(shotsr == 0)
    {
        QTimer::singleShot(1,this,SLOT(ShowGameEnded()));
        //field->setFocus();
    }

    angleSlider->setEnabled(true);
    forceSlider->setEnabled(true);
    fireButton->setEnabled(true);

}

void Widget::DisableChanges()
{

    shotsf++;
    shotsr--;
    shotsrLCD->display(shotsr);
    shotsfLCD->display(shotsf);

    angleSlider->setEnabled(false);
    forceSlider->setEnabled(false);
    fireButton->setEnabled(false);
}

void Widget::ShowGameEnded()
{
    Initializations();
    QMessageBox::critical(this,"Game over","You lost, you would have lost anyway");
}

void Widget::AddPoint()
{
    points++;
    pointsLCD->display(points);
}

Widget::~Widget()
{
    delete ui;
}



