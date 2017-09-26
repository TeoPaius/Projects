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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QSlider *HSlider;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *RBDiff;
    QPushButton *PBCls1;
    QPushButton *PBCls2;
    QPushButton *PBCls3;
    QPushButton *PBCls4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *PBStart;
    QPushButton *PBRestart;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *LCorect;
    QLabel *LCnt;
    QHBoxLayout *horizontalLayout_3;
    QLabel *LNr1;
    QLabel *LSign;
    QLabel *LNr2;
    QLabel *LEqual;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *LAux1;
    QLabel *LTime;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QListWidget *listWidget;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *BtnSave;
    QPushButton *BtnDel;
    QPushButton *BtnLoad;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(538, 448);
        verticalLayout_12 = new QVBoxLayout(Widget);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        HSlider = new QSlider(Widget);
        HSlider->setObjectName(QStringLiteral("HSlider"));
        HSlider->setMinimum(1);
        HSlider->setMaximum(4);
        HSlider->setPageStep(0);
        HSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(HSlider);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        RBDiff = new QRadioButton(Widget);
        RBDiff->setObjectName(QStringLiteral("RBDiff"));

        verticalLayout->addWidget(RBDiff);

        PBCls1 = new QPushButton(Widget);
        PBCls1->setObjectName(QStringLiteral("PBCls1"));
        PBCls1->setEnabled(false);

        verticalLayout->addWidget(PBCls1);

        PBCls2 = new QPushButton(Widget);
        PBCls2->setObjectName(QStringLiteral("PBCls2"));
        PBCls2->setEnabled(false);

        verticalLayout->addWidget(PBCls2);

        PBCls3 = new QPushButton(Widget);
        PBCls3->setObjectName(QStringLiteral("PBCls3"));
        PBCls3->setEnabled(false);

        verticalLayout->addWidget(PBCls3);

        PBCls4 = new QPushButton(Widget);
        PBCls4->setObjectName(QStringLiteral("PBCls4"));
        PBCls4->setEnabled(false);

        verticalLayout->addWidget(PBCls4);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        PBStart = new QPushButton(Widget);
        PBStart->setObjectName(QStringLiteral("PBStart"));

        verticalLayout_4->addWidget(PBStart);

        PBRestart = new QPushButton(Widget);
        PBRestart->setObjectName(QStringLiteral("PBRestart"));

        verticalLayout_4->addWidget(PBRestart);


        horizontalLayout->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        LCorect = new QLabel(Widget);
        LCorect->setObjectName(QStringLiteral("LCorect"));
        QFont font;
        font.setPointSize(14);
        LCorect->setFont(font);

        horizontalLayout_4->addWidget(LCorect);

        LCnt = new QLabel(Widget);
        LCnt->setObjectName(QStringLiteral("LCnt"));
        LCnt->setFont(font);
        LCnt->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(LCnt);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        LNr1 = new QLabel(Widget);
        LNr1->setObjectName(QStringLiteral("LNr1"));
        LNr1->setFont(font);
        LNr1->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(LNr1);

        LSign = new QLabel(Widget);
        LSign->setObjectName(QStringLiteral("LSign"));
        LSign->setFont(font);
        LSign->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(LSign);

        LNr2 = new QLabel(Widget);
        LNr2->setObjectName(QStringLiteral("LNr2"));
        LNr2->setFont(font);
        LNr2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(LNr2);

        LEqual = new QLabel(Widget);
        LEqual->setObjectName(QStringLiteral("LEqual"));
        LEqual->setFont(font);
        LEqual->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(LEqual);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(12);
        lineEdit->setFont(font1);

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color:red"));

        horizontalLayout_6->addWidget(label_2);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QLatin1String("background-color:green\n"
""));

        horizontalLayout_7->addWidget(label_5);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(label_4);


        verticalLayout_5->addLayout(horizontalLayout_7);


        horizontalLayout_8->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        LAux1 = new QLabel(Widget);
        LAux1->setObjectName(QStringLiteral("LAux1"));
        LAux1->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(LAux1);

        LTime = new QLabel(Widget);
        LTime->setObjectName(QStringLiteral("LTime"));
        LTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(LTime);

        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_9);


        verticalLayout_10->addLayout(verticalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font2;
        font2.setPointSize(15);
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_6);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setModelColumn(0);
        listWidget->setSortingEnabled(false);

        verticalLayout_9->addWidget(listWidget);


        horizontalLayout_10->addLayout(verticalLayout_9);

        horizontalSpacer_4 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);
        pushButton->setFont(font1);

        horizontalLayout_10->addWidget(pushButton);


        verticalLayout_10->addLayout(horizontalLayout_10);


        verticalLayout_11->addLayout(verticalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        BtnSave = new QPushButton(Widget);
        BtnSave->setObjectName(QStringLiteral("BtnSave"));

        horizontalLayout_11->addWidget(BtnSave);

        BtnDel = new QPushButton(Widget);
        BtnDel->setObjectName(QStringLiteral("BtnDel"));

        horizontalLayout_11->addWidget(BtnDel);

        BtnLoad = new QPushButton(Widget);
        BtnLoad->setObjectName(QStringLiteral("BtnLoad"));
        BtnLoad->setEnabled(false);

        horizontalLayout_11->addWidget(BtnLoad);


        verticalLayout_11->addLayout(horizontalLayout_11);


        verticalLayout_12->addLayout(verticalLayout_11);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        RBDiff->setText(QApplication::translate("Widget", "Dificultati predefinite", 0));
        PBCls1->setText(QApplication::translate("Widget", "Clasa I", 0));
        PBCls2->setText(QApplication::translate("Widget", "Clasa a II-a", 0));
        PBCls3->setText(QApplication::translate("Widget", "Clasa a III-a", 0));
        PBCls4->setText(QApplication::translate("Widget", "Clasa a IV-a", 0));
        PBStart->setText(QApplication::translate("Widget", "Start", 0));
        PBRestart->setText(QApplication::translate("Widget", "Restart", 0));
        LCorect->setText(QApplication::translate("Widget", "Raspunsuri corecte :", 0));
        LCnt->setText(QApplication::translate("Widget", "0", 0));
        LNr1->setText(QApplication::translate("Widget", "0", 0));
        LSign->setText(QApplication::translate("Widget", "+", 0));
        LNr2->setText(QApplication::translate("Widget", "0", 0));
        LEqual->setText(QApplication::translate("Widget", "=", 0));
        lineEdit->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("Widget", ": Raspuns gresit", 0));
        label_5->setText(QString());
        label_4->setText(QApplication::translate("Widget", ": Raspuns corect", 0));
        LAux1->setText(QApplication::translate("Widget", "Mai ai :", 0));
        LTime->setText(QApplication::translate("Widget", "30", 0));
        label->setText(QApplication::translate("Widget", "de secunde", 0));
        label_6->setText(QApplication::translate("Widget", "Rezultate recente", 0));
        pushButton->setText(QApplication::translate("Widget", "Ma dau batut", 0));
        BtnSave->setText(QApplication::translate("Widget", "Afiseaza istoric", 0));
        BtnDel->setText(QApplication::translate("Widget", "Sterge istoric", 0));
        BtnLoad->setText(QApplication::translate("Widget", "Salveaza", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
