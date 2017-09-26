/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *upBtn;
    QPushButton *downBtn;
    QPushButton *leftBtn;
    QPushButton *rightBtn;
    QPushButton *rotleftBtn;
    QPushButton *rotrightBtn;
    QPushButton *placeBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1200, 800);
        upBtn = new QPushButton(Widget);
        upBtn->setObjectName(QStringLiteral("upBtn"));
        upBtn->setGeometry(QRect(410, 20, 75, 23));
        downBtn = new QPushButton(Widget);
        downBtn->setObjectName(QStringLiteral("downBtn"));
        downBtn->setGeometry(QRect(410, 80, 75, 23));
        leftBtn = new QPushButton(Widget);
        leftBtn->setObjectName(QStringLiteral("leftBtn"));
        leftBtn->setGeometry(QRect(330, 50, 75, 23));
        rightBtn = new QPushButton(Widget);
        rightBtn->setObjectName(QStringLiteral("rightBtn"));
        rightBtn->setGeometry(QRect(490, 50, 75, 23));
        rotleftBtn = new QPushButton(Widget);
        rotleftBtn->setObjectName(QStringLiteral("rotleftBtn"));
        rotleftBtn->setGeometry(QRect(330, 80, 75, 23));
        rotrightBtn = new QPushButton(Widget);
        rotrightBtn->setObjectName(QStringLiteral("rotrightBtn"));
        rotrightBtn->setGeometry(QRect(490, 80, 75, 23));
        placeBtn = new QPushButton(Widget);
        placeBtn->setObjectName(QStringLiteral("placeBtn"));
        placeBtn->setGeometry(QRect(410, 50, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        upBtn->setText(QApplication::translate("Widget", "Go up", 0));
        downBtn->setText(QApplication::translate("Widget", "Go down", 0));
        leftBtn->setText(QApplication::translate("Widget", "Go left", 0));
        rightBtn->setText(QApplication::translate("Widget", "Go right", 0));
        rotleftBtn->setText(QApplication::translate("Widget", "Rotate left", 0));
        rotrightBtn->setText(QApplication::translate("Widget", "Rotate right", 0));
        placeBtn->setText(QApplication::translate("Widget", "PLACE", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
