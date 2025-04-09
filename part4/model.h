#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class model : public QObject
{
    Q_OBJECT
public:
    explicit model(QObject *parent = nullptr);
    void setValue(int index, int v);
    int getValue(int index) const;

signals:
    void valueChanged(int index, int v);

private:
    int value0, value1, value2;

};

#endif // MODEL_H
