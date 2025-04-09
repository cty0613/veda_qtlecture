#include "mdimainwindow.h"
#include "form.h"

MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setWindowTitle(QString::fromUtf8("My MDI"));

    QMdiArea* area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QMdiSubWindow* subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300, 200);
    QPushButton *btn = new QPushButton(QString("Button"));
    subWindow1->setWidget(btn);

    QMdiSubWindow* subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300, 200);
    Form* insideForm = new Form();
    subWindow2->setWidget(insideForm);


    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);

    setCentralWidget(area);
}

// MainWindow(QMainWindow) > MDIMainWindow(QWidget) > area(QMdiArea) > subWindow...(QMdiSunWindow) > btn/insideForm ...
