// #include "widget.h"
#include "quiz.h"
#include <QApplication>
#define QD (qDebug())

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Quiz q;

    return a.exec();
}
