#include "signalslot.h"

SignalSlot::SignalSlot(QObject *parent)
    : QObject{parent}
{}

void SignalSlot::mySignalTrigger(int v) {

    if(m_value != v) { // 무한 재귀 signal 발생 방지
        m_value = v;
        emit mySIGNAL(v); // mySignal 호출시 valueChanged signal 발동
    }

};
