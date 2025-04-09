#ifndef DATETIME_H
#define DATETIME_H

#include <QWidget>
#include <QDate>
#include <QDateEdit>
#include <QTime>
#include <QTimeEdit>
#include <QLabel>

namespace Ui {
class dateTime;
}

class dateTime : public QWidget
{
    Q_OBJECT

public:
    explicit dateTime(QWidget *parent = nullptr);
    ~dateTime();

private:
    Ui::dateTime *ui;

    QDateEdit* dateEdit[4];
    QLabel* date_label;
    QLabel* time_label;

    void date_changed();
    void time_changed();
};

#endif // DATETIME_H
