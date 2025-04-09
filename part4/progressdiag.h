#ifndef PROGRESSDIAG_H
#define PROGRESSDIAG_H

#include <QObject>
#include <QProgressDialog>
#include <QTimer>

class ProgressDiag : public QObject
{
    Q_OBJECT
public:
    explicit ProgressDiag(QObject *parent = nullptr);

private:
    QProgressDialog pd = QProgressDialog(
        "현재 진행상황",
        "취소",
        0, 100);
    QTimer pt = QTimer(this);
    int steps;


signals:

public slots:
    void perform();
    void cancel();
};

#endif // PROGRESSDIAG_H
