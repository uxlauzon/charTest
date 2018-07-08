#include "drawtest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawTest w;
    w.show();

    return a.exec();
}
