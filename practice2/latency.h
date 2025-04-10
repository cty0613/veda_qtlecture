//
// Created by 2-17 on 25. 4. 10.
//

#ifndef LATENCY_H
#define LATENCY_H


#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QElapsedTimer>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Latency; }
QT_END_NAMESPACE

class Latency : public QWidget {
Q_OBJECT

public:
    explicit Latency(QWidget *parent = nullptr);
    ~Latency() override;

private:
    // State
    int state; // 0:Ready, 1:Red, 2:Blue

    Ui::Latency *ui;

    // Layout
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* headerLayout = new QHBoxLayout();
    QGridLayout* bodyLayout = new QGridLayout();

    // Btns
    // QPushButton* resetBtn = new QPushButton("리셋", this);
    QPushButton* mainBtn = new QPushButton(" READY ", this);

    // Timer Label
    QLabel* timerLabel = new QLabel();

    // Timer
    QTimer* timer = new QTimer();
    QElapsedTimer* timerElapsed = new QElapsedTimer();

    QTime time1;
    QTime time2;

private:
    int getState();
    void setState(int newState);

private slots:
    void slot_startRedMission();
    void slot_redTimeOut();
    void slot_redMission();

    void slot_startBlueMission();
    void slot_blueTimeOut();
    void slot_blueMission();


};


#endif //LATENCY_H
