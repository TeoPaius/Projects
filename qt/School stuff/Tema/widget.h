#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class Widget;
class Time;
}





class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QTime *timer;
    ~Widget();

    void SetScore();
public slots:
    void LTime_Change();
    void on_PBRestart_clicked();

private slots:

    void on_PBCls1_clicked();

    void on_RBDiff_clicked();

    void on_PBStart_clicked();

    void on_PBCls2_clicked();

    void on_PBCls3_clicked();

    void on_PBCls4_clicked();

    void on_lineEdit_returnPressed();



    void on_pushButton_clicked();


    void on_BtnSave_clicked();

    void on_BtnDel_clicked();



    void on_BtnLoad_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
