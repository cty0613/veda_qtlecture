#include "progressdiag.h"

ProgressDiag::ProgressDiag(QObject *parent)
    : QObject{parent}
{
    steps = 0;

    connect(&pd, &QProgressDialog::canceled,
            this, &ProgressDiag::cancel);


    connect(&pt, &QTimer::timeout,
            this, &ProgressDiag::perform);

    pt.start(1000);

}

void ProgressDiag::perform(){
    pd.setValue(steps);
    steps++;

    if(steps > pd.maximum()) pt.stop();
}

void ProgressDiag::cancel() {
    pt.stop();
}
