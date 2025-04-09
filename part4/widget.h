#ifndef WIDGET_H
#define WIDGET_H

#include "model.h"
#include "progressdiag.h"

#include <QWidget>
#include <QProgressDialog>

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

private:
    Ui::Widget *ui;

    // Model
    model* data;

    // ProgressDialog
    ProgressDiag* dia;


private slots:
    void slider1_valueChanged(int v);
    void slider2_valueChanged(int v);
    void slider3_valueChanged(int v);

    void spin1_valueChanged(int v);
    void spin2_valueChanged(int v);
    void spin3_valueChanged(int v);

    void btn1_clicked();
    void btn2_clicked();
    void btn3_clicked();
    void btn4_clicked();

    // void valueChangedByModel(model &model);
};
#endif // WIDGET_H
