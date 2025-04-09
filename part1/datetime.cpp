#include "datetime.h"
#include "ui_datetime.h"

dateTime::dateTime(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::dateTime)
{
    ui->setupUi(this);

    QDate dt1 = QDate::currentDate();

    dateEdit[0] = new QDateEdit(dt1, this);
    dateEdit[0]->setGeometry(10, 10, 140, 40);

    date_label = new QLabel(this);
    date_label->setGeometry(10, 110, 140, 40);

    // timeEdit = new QTimeEdit(qt1, this);

    connect(
        dateEdit[0],
        &QDateEdit::dateChanged,
        this,
        &dateTime::date_changed
    );

    connect(
        ui->pushButton,
        &QPushButton::clicked,
        this,
        &dateTime::time_changed
    );

    date_changed();
    time_changed();


}

dateTime::~dateTime()
{
    delete ui;
}

void dateTime::date_changed() {
    auto str = dateEdit[0]->date().toString("yyyy년 MM월 dd일");
    date_label->setText(str);
}

void dateTime::time_changed() {
    QTime qt1 = QTime::currentTime();
    auto hour = qt1.hour();
    auto minutes = qt1.minute();
    auto second = qt1.second();
    qDebug() << hour << " : " << minutes << " : " << second;
    ui->lcdNumberH->display(hour);
    ui->lcdNumberM->display(minutes);
    ui->lcdNumberS->display(second);

}



