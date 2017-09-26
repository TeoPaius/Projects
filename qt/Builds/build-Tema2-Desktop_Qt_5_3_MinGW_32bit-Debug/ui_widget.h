/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *PointButton;
    QPushButton *UPointButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *LineButton;
    QPushButton *ULineButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        Widget->setCursor(QCursor(Qt::OpenHandCursor));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(300, 90, 71, 21));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        comboBox->setFont(font);
        comboBox->setStyleSheet(QStringLiteral("background-color:red;"));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(221, 11, 159, 66));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PointButton = new QPushButton(layoutWidget);
        PointButton->setObjectName(QStringLiteral("PointButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PointButton->sizePolicy().hasHeightForWidth());
        PointButton->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        PointButton->setFont(font1);
        PointButton->setCursor(QCursor(Qt::PointingHandCursor));
        PointButton->setStyleSheet(QLatin1String("border: 4px solid;\n"
"border-radius: 4px;\n"
"border-color: red;\n"
"background-color:qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));"));

        horizontalLayout_2->addWidget(PointButton);

        UPointButton = new QPushButton(layoutWidget);
        UPointButton->setObjectName(QStringLiteral("UPointButton"));
        sizePolicy.setHeightForWidth(UPointButton->sizePolicy().hasHeightForWidth());
        UPointButton->setSizePolicy(sizePolicy);
        UPointButton->setFont(font);
        UPointButton->setCursor(QCursor(Qt::PointingHandCursor));
        UPointButton->setStyleSheet(QLatin1String("border: 4px solid;\n"
"border-radius: 4px;\n"
"border-color: red;\n"
"background-color:qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));"));

        horizontalLayout_2->addWidget(UPointButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        LineButton = new QPushButton(layoutWidget);
        LineButton->setObjectName(QStringLiteral("LineButton"));
        LineButton->setFont(font);
        LineButton->setCursor(QCursor(Qt::PointingHandCursor));
        LineButton->setStyleSheet(QLatin1String("border: 4px solid;\n"
"border-radius: 4px;\n"
"border-color: red;\n"
"background-color:qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));"));

        horizontalLayout->addWidget(LineButton);

        ULineButton = new QPushButton(layoutWidget);
        ULineButton->setObjectName(QStringLiteral("ULineButton"));
        ULineButton->setFont(font);
        ULineButton->setCursor(QCursor(Qt::PointingHandCursor));
        ULineButton->setStyleSheet(QLatin1String("border: 4px solid;\n"
"border-radius: 4px;\n"
"border-color: red;\n"
"background-color:qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));"));

        horizontalLayout->addWidget(ULineButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Rosu", 0)
         << QApplication::translate("Widget", "Albastru", 0)
         << QApplication::translate("Widget", "Verde", 0)
        );
        PointButton->setText(QApplication::translate("Widget", "Point", 0));
        UPointButton->setText(QApplication::translate("Widget", "Undo Point", 0));
        LineButton->setText(QApplication::translate("Widget", "Line", 0));
        ULineButton->setText(QApplication::translate("Widget", "Undo Line", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
