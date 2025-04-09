#include "widget.h"
// #include "ui_widget.h"
#include <QByteArrayMatcher>
#include <QChar>
#define QD (qDebug())

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Number Manipulate
    #if 0
    int absValue;
    int myValue = -4;

    absValue = qAbs(myValue);

    auto boundValue = qBound(0.0, 0.10, 1.0);

    QD << absValue; // 4
    QD << boundValue; // 10

    double x = 0.1;
    double y = 0.2;
    double z = 0.3;

    QD << (x+y==z); // false
    QD << qFuzzyCompare(x+y, z); // true

    qreal valueA = 2.3;
    qreal valueB = 2.7;

    int rValA = qRound(valueA); // 2
    int rValB = qRound(valueB); // 3

    QD << rValA << rValB;

    #endif

    // String/Array Maniplate

    #if 0
    QByteArray ba("Q");
    ba.prepend("I Love ");
    ba.append("t -^^*");
    ba.replace(10, 1, "*"); // index, replace amount, replace string

    QD << ba; // "I Love Qt *^^*"

    ba.remove(9, 5); // start idx, remove amount

    QD << ba; // "I Love Qt"

    QByteArray ba2("hello Qt, nice to meet you.");
    QByteArray ba3("Qt");

    QByteArrayMatcher matcher(ba3);

    int index = matcher.indexIn(ba2, 0);

    qDebug( "index : %d", index);
    qDebug( "QByte : %c%c", ba2.at(index), ba2.at(index+1));
    #endif


    // QString

    QString str = "Hello Qt"; // 16bit(2byte) QChar string class
    QChar* qc = str.data(); // 16bit(2byte) unicode(UTF-16) literal class

    QD << qc[1]; // "e"

    while(!(qc->isNull())){
        QD << qc->unicode();//  "H" "e" "l" "l" ..."Q" "t"
        qc++;
    }

    static const QChar data[4] = {
            QChar(0x0055),
            QChar(0x006e),
            QChar(0x10e3),
            QChar(0x03a3)
    };

    QString str2(data, 4);

    QD << "String" << str2; // String "Un?Σ"

    str2.resize(2); // 강제로 '4'글자 스트링으로 줄이기 (앞글자부터만 살아남음)
    QD << "String Resized" << str2; // String Resized "Un"


    QString str3 = "I Love You Qt!";
    QStringList str_list =  str3.split(" ");

    QD << str_list.length(); // 4
    for (auto s : str_list){
        QD << s;
    }




}

Widget::~Widget()
{

}
