#include "eyedropper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    eyeDropper w;
    w.show();

    return a.exec();
}
