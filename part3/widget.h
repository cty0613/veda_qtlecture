#ifndef WIDGET_H
#define WIDGET_H

#include "spin.h"

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void setValue(int val);

private:
    Ui::Widget *ui;
    QLabel* lbl;
    spin* myspin;
};
#endif // WIDGET_H
