#include "eyedropper.h"
#include "ui_eyedropper.h"

eyeDropper::eyeDropper(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eyeDropper)
{
    ui->setupUi(this);
    button = new QPushButton;
    label = new myLabel(0, button);
    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);
    layout = new QHBoxLayout;
    layout->addWidget(button);
    layout->addWidget(label);
    centralWidget->setLayout(layout);
}

eyeDropper::~eyeDropper()
{
    delete ui;
}
