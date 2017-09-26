#include "widget.h"
#include "ui_widget.h"
#include <cmath>
#include <QString>
#include <QTimer>
#include <QMessageBox>
#include <QToolTip>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QInputDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QTime>

char a[] = {'*', '*', '*', '*'};
int cnt;
int cnttime;
int raspcor;
bool timerstarted;
bool notr;
int cntwr, cntri;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString path;
    /*path = "F:";
    path+= "\qt";
    path+= "\project";
    path+= "\test";
    QDir a(path);
    bool res;
    a.setFilter( QDir::NoDotAndDotDot | QDir::Files );
    foreach( QString dirItem, a.entryList() )
        {
             res = a.remove(dirItem);
        }
    */
    ui->lineEdit->setValidator(new QIntValidator(0, 999999, this));
    ui->PBCls1->setToolTip("Operatii cu numere de doua cifre");
    ui->PBCls2->setToolTip("Operatii cu numere de trei cifre");
    ui->PBCls3->setToolTip("Operatii cu numere de patru cifre");
    ui->PBCls4->setToolTip("Operatii cu numere de cinci cifre");
    QFile q("text.txt");
    ui->BtnSave->setEnabled(true);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::SetScore()
{
    QMessageBox msg;
    msg.setWindowTitle("Felicitari");
    QString puncte;
    QString nota;
    nota.setNum((10*cntri)/(cntri+cntwr));
    if(nota == "10" )
        nota = "FB";
    if(nota == "9")
        nota = "-FB";
    if(nota == "8")
        nota = "B";
    if(nota == "7")
        nota = "-B";
    if(nota == "6")
        nota = "S";
    if(nota == "5")
        nota = "-S";
    if(nota == "4")
        nota = "I";
    if(nota == "3")
        nota = "I";
    if(nota == "2")
        nota = "I";
    if(nota == "1")
        nota = "I";
    if(nota == "0")
        nota = "I";


    puncte.setNum(cnt);
    msg.setIcon(QMessageBox::Question);
    msg.setText("Ati obtinut " + puncte + " puncte" + '\n' + "Nota "  + nota + '\n' + "Vreti sa incercati din nou?");
   // msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    QAbstractButton *Da = msg.addButton("Da", QMessageBox::ActionRole);
    QAbstractButton *Nu = msg.addButton("Nu", QMessageBox::ActionRole);
    msg.exec();
    if(msg.clickedButton()==Da)
    {
        QInputDialog dial;
        QString s = dial.getText(this, "Salvati scorul", "Nume");
        QString fin = s+ " a obtinut nota " + nota;
        ui->listWidget->addItem( fin);
        ui->BtnLoad->setEnabled(true);

        on_PBRestart_clicked();
    }
    if(msg.clickedButton()==Nu)
    {
        QInputDialog dial;
        QString s = dial.getText(this, "Salvati scorul", "Nume");
        QString fin = s+ " a obtinut " + puncte + " puncte";
        ui->listWidget->addItem( fin);
        QCoreApplication::exit();
    }
}

void Widget::LTime_Change()
{
    if (notr == false)
    {
    QString aux;
    int cntaux = 30;
    cnttime++;
    cntaux = 30 - cnttime;
    aux.clear();
    aux.setNum(cntaux);

        ui->LTime->setText(aux);
        if(ui->LTime->text() == "0")
        {
            SetScore();
        }
        else
            if(notr == false)
                 QTimer::singleShot(1000, this, SLOT(LTime_Change()));
    }
}

void Widget::on_RBDiff_clicked()
{
    if(ui->RBDiff->isChecked())
    {
        ui->PBCls1->setEnabled(1);
        ui->PBCls2->setEnabled(1);
        ui->PBCls3->setEnabled(1);
        ui->PBCls4->setEnabled(1);
    }
    else
    {
        ui->PBCls1->setEnabled(0);
        ui->PBCls2->setEnabled(0);
        ui->PBCls3->setEnabled(0);
        ui->PBCls4->setEnabled(0);
    }


}

void Widget::on_PBStart_clicked()
{

    int nr1, nr2, sign;
    int int1, int2;
    ui->lineEdit->setText("");
    int nrcif = ui->HSlider->value() - 1;
    int1 = pow(10, nrcif);
    int2 = pow(10, nrcif+1) - 1;
    QTime ti = QTime::currentTime();
    qsrand((uint)ti.msec());
    nr1 = qrand() % ((int2+1) - int1) + int1;
    nr2 = qrand() % ((int2+1) - int1) + int1;

    QString aux1, aux2;
    aux1.setNum(nr1);
    ui->LNr1->setText(aux1);
    aux2.setNum(nr2);
    ui->LNr2->setText(aux2);
    sign = qrand() % 2;
    aux1.clear();
    aux1.append(a[sign]);
    ui->LSign->setText(aux1);
    notr = false;
    ui->lineEdit->setFocus();
    if(timerstarted == false && notr == false)
    {
        ui->PBStart->setEnabled(false);
        timerstarted = true;
        QTimer::singleShot(1000, this, SLOT(LTime_Change()));
    }
    //timer = new Time(this);
   // connect(timer,SIGNAL(timeout()),this,SLOT(LTime_Change()));
   // timer->start(1000);

}

void Widget::on_PBCls1_clicked()
{
    ui->HSlider->setValue(1);
}


void Widget::on_PBCls2_clicked()
{
    ui->HSlider->setValue(2);
}


void Widget::on_PBCls3_clicked()
{
    ui->HSlider->setValue(3);
}

void Widget::on_PBCls4_clicked()
{
    ui->HSlider->setValue(4);
}

void Widget::on_lineEdit_returnPressed()
{
    double answ;
    QString au;
    if(ui->LSign->text() == "+")
        answ = ui->LNr1->text().toDouble() + ui->LNr2->text().toDouble();
    if(ui->LSign->text() == "-")
        answ = ui->LNr1->text().toDouble() - ui->LNr2->text().toDouble();
    if(ui->LSign->text() == "*")
        answ = ui->LNr1->text().toDouble() * ui->LNr2->text().toDouble();
    if(ui->LSign->text() == "/")
        answ = ui->LNr1->text().toDouble() * ui->LNr2->text().toDouble();
    if(answ != ui->lineEdit->text().toDouble())
    {
        //au.setNum(answ);
       // ui->lineEdit->setText(au);
        ui->lineEdit->setText("");
        ui->lineEdit->setStyleSheet("background-color : red");
        cntwr++;
        on_PBStart_clicked();
    }
    else
    {
        cnt++;
        au.clear();
        au.setNum(cnt);
        ui->LCnt->setText(au);
        ui->lineEdit->setStyleSheet("background-color : green");
        cntri++;
        on_PBStart_clicked();
    }
}

void Widget::on_PBRestart_clicked()
{
    ui->HSlider->setValue(1);
    ui->LCnt->setText("0");
    ui->lineEdit->setText("0");
    ui->LNr1->setText("0");
    ui->LNr2->setText("0");
    ui->LTime->setText("30");
    ui->lineEdit->setStyleSheet("background-color : white");
    ui->pushButton->setEnabled(false);
    cntri = 0;
    cntwr = 0;
    cnttime = 0;
    cnt = 0;
    timerstarted = false;
    notr = true;
    ui->PBStart->setEnabled(true);

   // timer->stop();

}



void Widget::on_pushButton_clicked()
{
    notr = true;
    QMessageBox auxm;
    auxm.setText("Esti sigur ca vrei sa renunti?");
    QAbstractButton *da = auxm.addButton("Da", QMessageBox::AcceptRole);
    QAbstractButton *nu = auxm.addButton("Nu", QMessageBox::RejectRole);
    auxm.exec();

    if(auxm.clickedButton() == da)
    {
        notr = false;
        SetScore();
    }
    if(auxm.clickedButton() == nu)
    {
        notr = false;
        QTimer::singleShot(1000, this, SLOT(LTime_Change()));
    }
}



void Widget::on_BtnSave_clicked()
{
    // asta e load
    ui->listWidget->clear();
    QFile q("text.txt");
    q.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream os(&q);
    while(!os.atEnd())
    {
        QString line = os.readLine(100);
        ui->listWidget->addItem(line);
    }
    q.close();
    ui->BtnSave->setEnabled(false);
}

void Widget::on_BtnDel_clicked()
{
    QFile q("text.txt");
    q.open(QIODevice::ReadWrite |QIODevice::Truncate | QIODevice::Text);
    QTextStream os(&q);
    QString f;
    f.resize(0);
    os << f;
    q.close();
}


void Widget::on_BtnLoad_clicked()
{
    //asta e save
    QString aux;
    for(int i = 0; i < ui->listWidget->count(); ++i)
    {
        aux = ui->listWidget->item(i)->text();
        aux += '\n';
        QFile q("text.txt");
        if(i == 0)
            q.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        else
            q.open(QIODevice::Append | QIODevice::Text);
        QTextStream os(&q);
            os << aux;
        q.close();
    }
    ui->BtnLoad->setEnabled(false);
}
