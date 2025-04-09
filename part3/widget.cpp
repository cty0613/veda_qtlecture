#include "widget.h"
// #include "ui_widget.h"
#include "signalslot.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lbl = new QLabel(" ", this);
    lbl->setGeometry(10, 10, 250, 40);

    SignalSlot myObject;
    myspin = new spin(this);

    myspin->setGeometry(0, 50, 100, 100);



    // New Style
    connect(
        &myObject, // signal을 발생시키는 객체
        &SignalSlot::mySIGNAL, // signal (=event)
        this, // slot을 가지고있는 객체
        &Widget::setValue // widget.h .cpp 에 선언됨
    );

    connect(
        myspin, // signal을 발생시키는 객체
        &spin::signalWidgetLabel, // signal(=event) : spin의 signal 멤버함수
        this,
        &Widget::setValue
    );

    myObject.mySignalTrigger(50); // signal (=event) 발생시키는 놈
                                  // conncet에 의해 Widget::setValue() 실행
}

void Widget::setValue(int val){
    QString text = QString("Signal Emmit!, Value: %1").arg(val);
    lbl->setText(text);
}

Widget::~Widget()
{

}
