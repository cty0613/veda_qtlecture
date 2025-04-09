#ifndef LAYOUTWIDGET_H
#define LAYOUTWIDGET_H

#include <QWidget>

namespace Ui {
class LayoutWidget;
}

class LayoutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LayoutWidget(QWidget *parent = nullptr);
    ~LayoutWidget();

private:
    Ui::LayoutWidget *ui;
};

#endif // LAYOUTWIDGET_H
