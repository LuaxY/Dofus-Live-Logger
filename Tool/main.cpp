#include "networkinspector.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NetworkInspector w;
    w.show();

    return a.exec();
}
