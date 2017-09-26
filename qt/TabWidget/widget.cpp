#include "widget.h"
#include "ui_widget.h"
#include "hyperlink.h"
#include <QUrl>
#include <QString>
#include <QtWebKitWidgets/QWebView>
#include <QWidget>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QString>
#include <string>
#include <string.h>
#include <QFont>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Site1 = new HyperLink();
    Site2 = new HyperLink();
    Site1->setText("www.google.com");
    Site2->setText("www.wikipedia.org");
    QFont auxf;
    auxf.setPointSize(13);
    Site1->setFont(auxf);
    Site2->setFont(auxf);
    ui->verticalLayout_2->addWidget(Site1);
    ui->verticalLayout_2->addWidget(Site2);
    setFocusPolicy(Qt::NoFocus);
    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(RTab(int)));
    connect(Site1, SIGNAL(Activated(QString)),this,SLOT(CreateNewTab(QString)));
    connect(Site2, SIGNAL(Activated(QString)),this,SLOT(CreateNewTab(QString)));
    //connect(ui->SiteL1,SIGNAL(linkActivated(QString)),this,SLOT(CreateNewTab(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::CreateNewTab(QString title)
{
    next = new QWidget();
    Wview = new QWebView();
    lay = new QVBoxLayout();
    lay->addWidget(Wview);
    next->setLayout(lay);
    //Wview->setUrl(url);
    Wview->load(QUrl("http://" + title));
    Wview->show();
    if(title.left(4) == "www.")
        title.remove(0,4);
    title[0] = title[0].toUpper();
    title.remove(title.indexOf("."),title.size()-title.indexOf("."));
    ui->tabWidget->addTab(next,title);
    ui->tabWidget->setCurrentWidget(next);
    //ui->tabWidget->setCurrentIndex(ui->tabWidget->count());

}

void Widget::RTab(int idx)
{
    ui->tabWidget->removeTab(idx);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return);
        on_searchBtn_clicked();
}

void Widget::on_searchBtn_clicked()
{
    url = new QUrl(ui->searchLE->text());
    if(url->isValid())
        CreateNewTab(ui->searchLE->text());

}
