#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCheckBox>
#include <QButtonGroup>

#include "datetime.h"

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
    QButtonGroup    *m_chk_group[2];
    QCheckBox       *m_exclusive[3];
    QCheckBox       *m_non_exclusive[3];

    dateTime* dtWidget; // dateTime Widget


private slots:
    void btn_clicked();
    void slot_chkChanged();
};
#endif // WIDGET_H
