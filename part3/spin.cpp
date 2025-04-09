#include "spin.h"
#include <QGridLayout>
spin::spin(QWidget *parent)
    : QWidget{parent}
{
    label = new QLabel(this);
    upButton = new QPushButton("▲", this);
    downButton = new QPushButton("▼", this);

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(label, 0, 0, 2, 1);
    layout->addWidget(upButton, 0, 1);
    layout->addWidget(downButton, 1, 1);

    label->setText("0");
    label->setFixedSize(100, 100);

    setLayout(layout);

    connect(
        upButton,
        &QPushButton::clicked,
        this,
        &spin::upButtonClicked
    );

    connect(
        downButton,
        &QPushButton::clicked,
        this,
        &spin::downButtonClicked
    );
}

void spin::upButtonClicked(){
    qDebug() << "Up Btn";
    int current = label->text().toInt();
    // label->setText(QString::number(++current));
    setLabel(++current);
}

void spin::downButtonClicked(){
    qDebug() << "Down Btn";
    int current = label->text().toInt();
    // label->setText(QString::number(--current));
    setLabel(--current);
}

void spin::setLabel(int v){
    label->setNum(v);
    emit signalWidgetLabel(v);  // 여기서 spin의 signal 발동시킴
                                // -> widget의 connect에서 감지
}
