#include <QApplication>
#include <QPushButton>

#include "latency.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Latency l;
    l.show();
    return a.exec();
}