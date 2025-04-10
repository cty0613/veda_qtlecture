//
// Created by 2-17 on 25. 4. 10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_latency.h" resolved

#include "latency.h"
#include "ui_latency.h"

#include <QRandomGenerator>
#include <QTime>

Latency::Latency(QWidget *parent) :
    QWidget(parent), ui(new Ui::Latency) {
    ui->setupUi(this);

    // Set Layouts & UI Sizes
    // headerLayout->addWidget(resetBtn);
    headerLayout->addWidget(timerLabel);

    bodyLayout->addWidget(mainBtn);
    mainBtn->setFixedSize(540,400);
    mainBtn->setStyleSheet("font-size:32pt;");

    mainLayout->addLayout(headerLayout);
    mainLayout->addLayout(bodyLayout);

    setLayout(mainLayout);

    // initialize instances
    state = 0;

    const QTime baseTime(0, 0, 0); // 기준은 00:00:00

    // 1 ~ 10 사이의 무작위 초값 생성
    const int randTime1 = QRandomGenerator::global()->bounded(1, 11); // 1 이상 11 미만 → 1~10
    const int randTime2 = QRandomGenerator::global()->bounded(1, 11);


    // 랜덤 시간 생성
    time1 = baseTime.addSecs(randTime1);
    time2 = baseTime.addSecs(randTime2);

    qDebug() << time1.second() * 1000 + time1.msec();
    qDebug() << time2.second();

    connect(
        mainBtn,
        SIGNAL(clicked()),
        this,
        SLOT(slot_startRedMission()));
}

Latency::~Latency() {
    delete ui;
}

int Latency::getState() {
    return state;
}

void Latency::setState(int newState) {
    state = newState;
    if (state == 1) {
        // Red (Next : Blue)
        mainBtn->setStyleSheet("background-color: red;");
        mainBtn->setText("파란색이 되면 누르세요");

        disconnect(
        mainBtn, SIGNAL(clicked()),
        this,SLOT(slot_startRedMission()));

        connect(mainBtn, SIGNAL(clicked()),
        this,SLOT(slot_redMission())); // Red일 때 미션

        connect(timer, &QTimer::timeout,
        this, &Latency::slot_redTimeOut); // Red Timeout

    } else if (state == 2) {
        // Blue (Next : Finish)
        mainBtn->setStyleSheet("background-color: blue;");
        mainBtn->setText("초록색이 되면 누르세요");

        disconnect(
        mainBtn, SIGNAL(clicked()),
        this,SLOT(slot_startBlueMission()));

        connect(mainBtn, SIGNAL(clicked()),
        this,SLOT(slot_blueMission()));

        connect(timer, &QTimer::timeout,
        this, &Latency::slot_blueTimeOut); // Blue Timeout
    }// Blue일 때 미션
}

void Latency::slot_startRedMission() {
    setState(1); // now Red
    mainBtn->setDisabled(true);
    timer->start(time1.second()*1000);
}

void Latency::slot_redTimeOut() {
    mainBtn->setStyleSheet("background-color: blue;");
    mainBtn->setText("지금 누르세요!");
    mainBtn->setEnabled(true);
    timerElapsed->start();

    connect(
        mainBtn, SIGNAL(clicked()),
        this, SLOT(slot_redMission()));

}

void Latency::slot_redMission() {
    mainBtn->setText(QString::number(timerElapsed->elapsed()));
    timer->stop();

    disconnect( // Red 미션 완료
        mainBtn, SIGNAL(clicked()),
        this,SLOT(slot_redMission()));

    connect( // 다시 누르면 Blue 미션으로
        mainBtn, SIGNAL(clicked()),
        this, SLOT(slot_startBlueMission()));
}

void Latency::slot_startBlueMission() {
    setState(2); // now Blue
    mainBtn->setDisabled(true);
    timer->start(time2.second()*1000);
}

void Latency::slot_blueTimeOut() {
    mainBtn->setStyleSheet("background-color: green;");
    mainBtn->setText("지금 누르세요!");
    mainBtn->setEnabled(true);
    timerElapsed->start();

    connect(
        mainBtn, SIGNAL(clicked()),
        this, SLOT(slot_blueMission()));
}

void Latency::slot_blueMission() {
    mainBtn->setText(QString::number(timerElapsed->elapsed()));
    timer->stop();

    disconnect( // Red 미션 완료
        mainBtn, SIGNAL(clicked()),
        this,SLOT(slot_blueMission()));

    // connect( // 다시 누르면 Blue 미션으로
    //     mainBtn, SIGNAL(clicked()),
    //     this, SLOT(slot_finishMission()));
}


