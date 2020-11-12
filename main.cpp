#include "poid.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    poid w;
    w.show();
    return a.exec();
}
