/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *connectButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwordLabel;
    QLineEdit *passwdLineEdit;
    QLabel *label;
    QPushButton *clearButton;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *userLabel;
    QLineEdit *userLineEdit;
    QPushButton *selectButton;
    QHBoxLayout *horizontalLayout;
    QLabel *dataBaseLabel;
    QLineEdit *dbLineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(448, 439);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(connectButton->sizePolicy().hasHeightForWidth());
        connectButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(connectButton, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        passwordLabel = new QLabel(centralWidget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(passwordLabel->sizePolicy().hasHeightForWidth());
        passwordLabel->setSizePolicy(sizePolicy1);
        passwordLabel->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(passwordLabel);

        passwdLineEdit = new QLineEdit(centralWidget);
        passwdLineEdit->setObjectName(QStringLiteral("passwdLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(passwdLineEdit->sizePolicy().hasHeightForWidth());
        passwdLineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(passwdLineEdit);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 5, 0, 1, 2);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(clearButton, 2, 1, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(tableWidget, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        userLabel = new QLabel(centralWidget);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        sizePolicy1.setHeightForWidth(userLabel->sizePolicy().hasHeightForWidth());
        userLabel->setSizePolicy(sizePolicy1);
        userLabel->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(userLabel);

        userLineEdit = new QLineEdit(centralWidget);
        userLineEdit->setObjectName(QStringLiteral("userLineEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(userLineEdit->sizePolicy().hasHeightForWidth());
        userLineEdit->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(userLineEdit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        sizePolicy.setHeightForWidth(selectButton->sizePolicy().hasHeightForWidth());
        selectButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(selectButton, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dataBaseLabel = new QLabel(centralWidget);
        dataBaseLabel->setObjectName(QStringLiteral("dataBaseLabel"));
        sizePolicy1.setHeightForWidth(dataBaseLabel->sizePolicy().hasHeightForWidth());
        dataBaseLabel->setSizePolicy(sizePolicy1);
        dataBaseLabel->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(dataBaseLabel);

        dbLineEdit = new QLineEdit(centralWidget);
        dbLineEdit->setObjectName(QStringLiteral("dbLineEdit"));
        sizePolicy2.setHeightForWidth(dbLineEdit->sizePolicy().hasHeightForWidth());
        dbLineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(dbLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 448, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(selectButton, SIGNAL(clicked()), MainWindow, SLOT(ChooseDatabaseFile()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        passwordLabel->setText(QApplication::translate("MainWindow", "Password:", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0));
        userLabel->setText(QApplication::translate("MainWindow", "User:", 0));
        selectButton->setText(QApplication::translate("MainWindow", "Select", 0));
        dataBaseLabel->setText(QApplication::translate("MainWindow", "Baza de date:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
