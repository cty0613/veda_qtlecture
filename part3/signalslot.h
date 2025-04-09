#ifndef SIGNALSLOT_H
#define SIGNALSLOT_H

#include <QObject>

class SignalSlot : public QObject
{
    Q_OBJECT
public:
    explicit SignalSlot(QObject *parent = nullptr);

    void mySignalTrigger(int val);

signals:
    void mySIGNAL(int newValue);

private:
    int m_value;
};

#endif // SIGNALSLOT_H
