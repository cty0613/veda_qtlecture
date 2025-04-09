#include "widget.h"
#include "ui_widget.h"

#include <QInputDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    data = new model();

    connect(
        ui->pushButton_1,
        &QPushButton::clicked,
        this,
        &Widget::btn1_clicked);

    connect(
        ui->pushButton_2,
        &QPushButton::clicked,
        this,
        &Widget::btn2_clicked);

    connect(
        ui->pushButton_3,
        &QPushButton::clicked,
        this,
        &Widget::btn3_clicked);

    connect(
        ui->pushButton_timer,
        &QPushButton::clicked,
        this,
        &Widget::btn4_clicked);

    connect(
        ui->horizontalSlider_1,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(slider1_valueChanged(int))
        );

    connect(
        ui->horizontalSlider_2,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(slider2_valueChanged(int))
        );

    connect(
        ui->horizontalSlider_3,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(slider3_valueChanged(int))
        );

    connect(
        ui->spinBox_1,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(spin1_valueChanged(int))
        );

    connect(
        ui->spinBox_2,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(spin2_valueChanged(int))
        );

    connect(
        ui->spinBox_3,
        SIGNAL(valueChanged(int)),
        this,
        SLOT(spin3_valueChanged(int))
        );


    // connect( 포기함, 잘못된 내용일 가능성 매우 높음.
    //     data,
    //     &model::valueChanged,
    //     this,
    //     &Widget::valueChangedByModel
    //     );

}


void Widget::slider1_valueChanged(int v){
    ui->spinBox_1->setValue(v);
};

void Widget::slider2_valueChanged(int v){
    ui->spinBox_2->setValue(v);
};

void Widget::slider3_valueChanged(int v){
    ui->spinBox_3->setValue(v);
};

void Widget::spin1_valueChanged(int v){
    ui->spinBox_1->setValue(v);
    ui->horizontalSlider_1->setValue(v);
};

void Widget::spin2_valueChanged(int v){
    ui->spinBox_2->setValue(v);
    ui->horizontalSlider_2->setValue(v);
};


void Widget::spin3_valueChanged(int v){
    ui->spinBox_3->setValue(v);
    ui->horizontalSlider_3->setValue(v);
};

// void Widget::valueChangedByModel(model &changedData){
//     ui->spinBox_1->setValue(changedData.getValue());

// };


void Widget::btn1_clicked(){ // 모달 등장
    bool retValue;
    int i = QInputDialog::getInt(
        this,
        "정수입력",
        "퍼센트",
        25, 0, 100, 1,
        &retValue);
    if(retValue){
        qDebug("True, %d", i);
    }
    QString label_text = QString("Selected : %1").arg(i);
    ui->label_1->setText(label_text);

}

void Widget::btn2_clicked(){ // 모달 등장
    QStringList items;
    items << "봄" << "여름" << "가을" << "겨울";
    bool ok;
    QString item = QInputDialog::getItem(
        this,
        "항목선택",
        "계절선택",
        items, 0, false,
        &ok);
    QString label_text = QString("Selected : %1").arg(item);
    ui->label_2->setText(label_text);
}

void Widget::btn3_clicked(){ // 메시지 박스 등장
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(
        this,
        "그렇구만",
        "햄부기부기 햄북스딱스 햄부기온엔온을 낋여오거라",
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);


}

void Widget::btn4_clicked(){
    dia = new ProgressDiag;
}


Widget::~Widget()
{
    delete ui;
}
