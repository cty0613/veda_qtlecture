#include "layoutwidget.h"
#include "ui_layoutwidget.h"

#include <QVBoxLayout>

LayoutWidget::LayoutWidget(QWidget *parent)
    : QWidget(parent)
{
    QWidget* w1 = new QWidget(this);
    w1->setStyleSheet(
        "background-color : red");

    QWidget* w2 = new QWidget(this);
    w2->setStyleSheet(
        "background-color : blue");

    QWidget* w3 = new QWidget(this);
    w3->setStyleSheet(
        "background-color : green");

    QWidget* w4 = new QWidget(this);
    w4->setStyleSheet(
        "background-color : yellow");


    // QVBoxLayout *vLayout = new QVBoxLayout();
    // vLayout->addWidget(w1);
    // vLayout->addWidget(w2);
    // vLayout->addWidget(w3);
    // vLayout->addWidget(w4);

    // this->setLayout(vLayout);

    // QHBoxLayout* hLayout = new QHBoxLayout();
    // hLayout->addWidget(w1);
    // hLayout->addWidget(w2);
    // hLayout->addWidget(w3);
    // hLayout->addWidget(w4);

    QWidget* Widgets[] = {w1, w2, w3, w4};

    // for (auto w: Widgets){
    //     w->setFixedWidth(100);
    // }

    // this->setLayout(hLayout);


    QGridLayout* gLayout = new QGridLayout();
    gLayout->addWidget(w1, 0, 0, 1, 1); // widget, xpos, ypos, row-span(세로 확장), col-span(가로 확장)
    gLayout->addWidget(w2, 1, 0, 1, 1);
    gLayout->addWidget(w3, 0, 1, 1, 1);
    gLayout->addWidget(w4, 1, 1, 1, 1);

    for (auto w: Widgets){
        w->setFixedSize(200, 200);
    }

    this->setLayout(gLayout);

}

LayoutWidget::~LayoutWidget()
{
    delete ui;
}
