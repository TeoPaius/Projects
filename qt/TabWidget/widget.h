#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QVBoxLayout>
#include <QWebView>
#include "hyperlink.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QString aux;
    QUrl* url;
    QWidget* next;
    QVBoxLayout* lay;
    QWebView* Wview;
    HyperLink* Site1;
    HyperLink* Site2;
    ~Widget();

protected:


public slots:
    void RTab(int idx);
    void keyPressEvent(QKeyEvent* e);
    void CreateNewTab(QString title);


private slots:
    void on_searchBtn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
