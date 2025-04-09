#include "widget.h"
#include "spin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    // spin w;
    w.setGeometry(100, 100, 200, 150);
    w.show();
    return a.exec();
}
