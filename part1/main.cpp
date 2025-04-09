#include "widget.h"
#include "layoutwidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // Widget w;
    LayoutWidget lw;
    lw.show();
    return a.exec();
}
