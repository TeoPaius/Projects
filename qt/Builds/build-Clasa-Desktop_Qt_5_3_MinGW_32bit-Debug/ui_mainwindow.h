/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_6;
    QSplitter *splitter_5;
    QSplitter *splitter_4;
    QSlider *HSlider;
    QSplitter *splitter_3;
    QRadioButton *RDiff;
    QSplitter *splitter_2;
    QPushButton *PBCls1;
    QPushButton *PBCls2;
    QPushButton *PBCls3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(632, 329);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        splitter_6 = new QSplitter(centralWidget);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(splitter_6->sizePolicy().hasHeightForWidth());
        splitter_6->setSizePolicy(sizePolicy1);
        splitter_6->setOrientation(Qt::Horizontal);
        splitter_5 = new QSplitter(splitter_6);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        sizePolicy1.setHeightForWidth(splitter_5->sizePolicy().hasHeightForWidth());
        splitter_5->setSizePolicy(sizePolicy1);
        splitter_5->setOrientation(Qt::Vertical);
        splitter_4 = new QSplitter(splitter_5);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        sizePolicy1.setHeightForWidth(splitter_4->sizePolicy().hasHeightForWidth());
        splitter_4->setSizePolicy(sizePolicy1);
        splitter_4->setOrientation(Qt::Vertical);
        HSlider = new QSlider(splitter_4);
        HSlider->setObjectName(QStringLiteral("HSlider"));
        sizePolicy1.setHeightForWidth(HSlider->sizePolicy().hasHeightForWidth());
        HSlider->setSizePolicy(sizePolicy1);
        HSlider->setMinimum(1);
        HSlider->setMaximum(4);
        HSlider->setOrientation(Qt::Horizontal);
        splitter_4->addWidget(HSlider);
        splitter_5->addWidget(splitter_4);
        splitter_6->addWidget(splitter_5);
        splitter_3 = new QSplitter(splitter_6);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        sizePolicy1.setHeightForWidth(splitter_3->sizePolicy().hasHeightForWidth());
        splitter_3->setSizePolicy(sizePolicy1);
        splitter_3->setOrientation(Qt::Vertical);
        RDiff = new QRadioButton(splitter_3);
        RDiff->setObjectName(QStringLiteral("RDiff"));
        sizePolicy1.setHeightForWidth(RDiff->sizePolicy().hasHeightForWidth());
        RDiff->setSizePolicy(sizePolicy1);
        RDiff->setMouseTracking(false);
        splitter_3->addWidget(RDiff);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        sizePolicy1.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy1);
        splitter_2->setOrientation(Qt::Vertical);
        PBCls1 = new QPushButton(splitter_2);
        PBCls1->setObjectName(QStringLiteral("PBCls1"));
        PBCls1->setEnabled(true);
        sizePolicy1.setHeightForWidth(PBCls1->sizePolicy().hasHeightForWidth());
        PBCls1->setSizePolicy(sizePolicy1);
        splitter_2->addWidget(PBCls1);
        PBCls2 = new QPushButton(splitter_2);
        PBCls2->setObjectName(QStringLiteral("PBCls2"));
        PBCls2->setEnabled(true);
        sizePolicy1.setHeightForWidth(PBCls2->sizePolicy().hasHeightForWidth());
        PBCls2->setSizePolicy(sizePolicy1);
        splitter_2->addWidget(PBCls2);
        PBCls3 = new QPushButton(splitter_2);
        PBCls3->setObjectName(QStringLiteral("PBCls3"));
        sizePolicy1.setHeightForWidth(PBCls3->sizePolicy().hasHeightForWidth());
        PBCls3->setSizePolicy(sizePolicy1);
        splitter_2->addWidget(PBCls3);
        splitter_3->addWidget(splitter_2);
        splitter_6->addWidget(splitter_3);

        horizontalLayout->addWidget(splitter_6);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        RDiff->setText(QApplication::translate("MainWindow", "Dificultati predefinite", 0));
        PBCls1->setText(QApplication::translate("MainWindow", "Clasa I", 0));
        PBCls2->setText(QApplication::translate("MainWindow", "Clasa a II-a", 0));
        PBCls3->setText(QApplication::translate("MainWindow", "Clasa a III-a", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
