//
// Created by 2-17 on 25. 4. 10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include "widget.h"
#include "ui_Widget.h"

#include <random>

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    // main(vLayout) -> [ top(QHBoxLayout) | btn(QGridLayout) ]
    startBtn = new QPushButton(this);
    timer = new QElapsedTimer();
    sigTimer = new QTimer();
    timerLabel = new QLabel("00:00");
    timerLabel->setStyleSheet("font-size: 32pt; font-weight: bold;");
    connect(
        sigTimer,
        SIGNAL(timeout()),
        this,
        SLOT(slot_timerTimeout()));

    topLayout->addWidget(startBtn);
    topLayout->addWidget(timerLabel);

    vLayout->addLayout(topLayout);
    vLayout->addLayout(btnLayout);
    setLayout(vLayout);

    initRandNums();
    clearNums();


    connect(
        startBtn,
        SIGNAL(clicked()),
        this,
        SLOT(slot_startBtnClicked()));


    // for (int y = 0; y < 5; y++) { // 5X5= 25개 버튼 만들기
    //     QList<QPushButton*> row;
    //     for (int x = 0; x < 5; x++) {
    //         QPushButton *btn = new QPushButton();
    //         row.append(btn);
    //         btnLayout->addWidget(btn, y, x);
    //     }
    //     numBtns.append(row);
    // }

}

Widget::~Widget() {
    delete ui;
    delete startBtn;
    delete topLayout;
    delete btnLayout;

}

int Widget::getState() const {
    return state;
}

void Widget::setState(int newState) {
    state = newState;
    if (state == 0) { // 0 중지
        sigTimer->stop();
    } else {
        sigTimer->start();
    }
}

void Widget::slot_timerTimeout() {
    int ms = timer->elapsed();
    int seconds = ms / 1000;          // 초 단위 추출
    int milliseconds = ms % 1000;     // 남은 밀리초

    QString displayNum = QString::asprintf("%d:%03d", seconds, milliseconds);

    timerLabel->setText(displayNum);
}

void Widget::slot_startBtnClicked() {
    if (getState() == 1) { // 실행 -> 중지
        setState(0);

    } else { // 중지 -> 실행
        setState(1);
        initRandNums();
    }
}

void Widget::slot_eachBtnClicked() {
    QObject* obj = QObject::sender();

    if (QPushButton *button = qobject_cast<QPushButton *>(obj)) {
        // 현재 누른 버튼 번호 확인
        // 그 번호랑 targetNum랑 일치하는지 확인
        // 일치하지 않으면 > 잘못눌렀으니 방치
        // 일치하면 다음 클릭해야할 버튼 숫자 변경
        if (button->property("number").toInt() == targetNum) {
            qDebug() << targetNum;
            targetNum++;
            button->setText("");
            button->setDisabled(true);
            button->setStyleSheet("background-color: rgb(0, 0, 0);");
            disconnect(
                button,
                SIGNAL(clicked()),
                nullptr,
                nullptr);
        }

        // 모두 선택했을 경우
        if (targetNum == 26) {
            // QMessageBox::information(
            //     this,                     // 부모 위젯 없음
            //     "게임 종료",            // 타이틀
            //     "축하합니다! 모든 숫자를 눌렀습니다." // 메시지
            // );

            clearNums();
            setState(0);
        }
    }
}

void Widget::initRandNums() {
    targetNum = 1;
    timer->start();
    startBtn->setText("다시하기");
    std::random_device rd;
    std::mt19937 g(rd());
    QVector<int> nums;
    for (int i = 0; i < 25; i++) {
        nums.append(i+1);
    }
    std::shuffle(nums.begin(), nums.end(), g);

    for (int y = 0; y < 5; y++) { // 5X5= 25개 버튼 만들기
        QList<QPushButton*> row;
        for (int x = 0; x < 5; x++) {
            QString number = QString::number(nums[y*5+x]); // 배열로부터 숫자 가져오기
            QPushButton *btn = new QPushButton(number, this); // 숫자를 버튼에 할당
            btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // 사이즈 조정
            btn->setProperty("number", nums[y*5+x]); // 커스텀 프로퍼티 만들기
            btn->setStyleSheet("font-size: 24pt;");
            row.append(btn); // row에 버튼 추가 (5개)
            connect( // sig-slt 연결
                btn,
                SIGNAL(clicked()),
                this,
                SLOT(slot_eachBtnClicked())
                );
            btnLayout->addWidget(btn, y, x);  // 레이아웃에 버튼위젯 추가
        }
        numBtns.append(row);
    }
}

void Widget::clearNums() {
    int ms = timer->elapsed();  // 경과 시간(밀리초 단위)

    int seconds = ms / 1000;          // 초 단위 추출
    int milliseconds = ms % 1000;     // 남은 밀리초

    QString displayNum = QString::asprintf("%d:%03d", seconds, milliseconds);

    // QString::asprintf 또는 QString::sprintf 스타일로 포맷
    // QString displayNum = QString("%1 : %2").arg(seconds).arg(milliseconds);// 밀리초는 항상 3자리로 표시

    timerLabel->setText(displayNum);  // 라벨에 설정
    startBtn->setText("시작");
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            numBtns[y*5+x]->setEnabled(true);
            numBtns[y*5+x]->setText(" ");
        }
    }
}