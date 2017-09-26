/********************************************************************************
** Form generated from reading UI file 'eyedropper.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EYEDROPPER_H
#define UI_EYEDROPPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eyeDropper
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *eyeDropper)
    {
        if (eyeDropper->objectName().isEmpty())
            eyeDropper->setObjectName(QStringLiteral("eyeDropper"));
        eyeDropper->resize(400, 300);
        menuBar = new QMenuBar(eyeDropper);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        eyeDropper->setMenuBar(menuBar);
        mainToolBar = new QToolBar(eyeDropper);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        eyeDropper->addToolBar(mainToolBar);
        centralWidget = new QWidget(eyeDropper);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        eyeDropper->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(eyeDropper);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        eyeDropper->setStatusBar(statusBar);

        retranslateUi(eyeDropper);

        QMetaObject::connectSlotsByName(eyeDropper);
    } // setupUi

    void retranslateUi(QMainWindow *eyeDropper)
    {
        eyeDropper->setWindowTitle(QApplication::translate("eyeDropper", "eyeDropper", 0));
    } // retranslateUi

};

namespace Ui {
    class eyeDropper: public Ui_eyeDropper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EYEDROPPER_H
