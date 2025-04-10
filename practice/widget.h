//
// Created by 2-17 on 25. 4. 10.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <QElapsedTimer>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QTime>
#include <QTimer>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;

    // 타이머 상태 : 0 중지 1 실행
    int state = 0;

    // 현재 눌러야할 버튼 번호
    int targetNum;

    // 타이머 라벨
    QLabel *timerLabel;

    // 타이머
    QElapsedTimer *timer; // 총 경과시간
    QTimer *sigTimer; // 표시용 타이머

    // 시작버튼
    QPushButton *startBtn;

    // 25개 숫자 버튼
    QList<QPushButton *> numBtns;

    // main(vLayout) -> [ top(QHBoxLayout) | btn(QGridLayout) ]
    QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *topLayout = new QHBoxLayout();
    QGridLayout *btnLayout = new QGridLayout();

    void initRandNums();
    void clearNums();
    int getState() const;
    void setState(int state);

private slots:
    void slot_startBtnClicked();
    void slot_eachBtnClicked();
    void slot_timerTimeout();

};


#endif //WIDGET_H
