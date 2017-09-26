#include <QApplication>
#include "mywindow.h"
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QPixmap>
#include <QTimer>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    int height = 350, width = 550;
    int W, H; // latimea si inaltimea ecranului

    QPixmap pix(":/Animals/dog.jpeg");
    QSplashScreen splash(pix.scaled(width, height,
                                    Qt::KeepAspectRatio));
    splash.show();

    QDesktopWidget *desktop = a.desktop();
    W = desktop->width();
    H = desktop->height();

    MyWindow w;
    w.resize(width, height);
    w.move((W - width) / 2, (H - height) / 2);

    QTimer::singleShot(5000, &splash, SLOT(close()));
    QTimer::singleShot(5000, &w, SLOT(show()));

    return a.exec();
}
