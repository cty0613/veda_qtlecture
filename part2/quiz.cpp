#include "quiz.h"
// #include "ui_quiz.h"

#include <QString>
#include <QList>
#include <QChar>
#include <QSet>
#include <algorithm>

#define qd (qDebug())

Quiz::Quiz(QWidget *parent)
    : QWidget(parent) {

    #if 0
    QList<QString> words = {"Apple", "Banana", "Zebra", "Xylophone", "Night", "Quiet", "Zero"};

    QMap<QChar, int> result;

    for (int i = 0; i < words.length(); i++){
        QString lower = words[i].toLower();
        for (QChar &ch : lower){
            if(ch.isLetter()){
                result[ch] += 1;
            }
        }
    }

    for (auto it = result.begin(); it != result.end(); ++it){
        qd << it.key() << " : " << it.value();
    }
    #endif


    #if 0
    QList<QString> words = {"banana", "apple", "orange", "apple", "banana", "kiwi"};

    // QSet으로 중복제거
    QSet<QString> uniqueSet = QSet<QString>(words.begin(), words.end());

    // QList로 다시 변환 (std::sort 사용)
    QList<QString> uniqueList = uniqueSet.values();
    std::sort(uniqueList.begin(), uniqueList.end());

    for (auto &word : uniqueList){
        qd << word << "(" << word.length() << ")";
    }

    #endif


    #if 0
    QList<QString> records = {
        "Alice 80", "Bob 90", "Alice 70", "Charile 100", "Bob 85", "Juila 95", "Juila 75"
    };

    QMap< QString, QList<int> > scores;

    for(const QString& each : records){
        QStringList parts = each.split(" ");
        QString name = parts[0];
        int score = parts[1].toInt();
        scores[name].append(score);
    }

    for (auto it = scores.begin(); it != scores.end(); it++){
        int total = 0;
        for (int s : it.value()) {
            total += s;
        }

        double average = total / it.value().size();

        qd << it.key() << " >> total:" << total << "average:" << average;

    }

     qd << " ------------------- ";

    #endif

    #if 0
    QString text = "A curious cat, always alert, observed an ant, Another animal? Absolutely!";

    text.remove('.').remove(',').remove('?').remove('!');
    text = text.toLower();

    QStringList words = text.split(' ', Qt::SkipEmptyParts);
    QSet<QChar> uniqueChar;
    QSet<QString> uniqueWord;

    int count = 0;
    for (const QString& word: words){
        if(word.startsWith('a')){
            count++;
        }

        uniqueWord.insert(word);

        for(const QChar& alpha : word){
            uniqueChar.insert(alpha);
        }

    }

    qd << "a로 시작하는 단어 갯수 :" << count;


    int size_max = 0;
    QString char_max;
    for (auto i : uniqueWord) {
        if( size_max < i.length()) {
            size_max = i.length();
            char_max = i;
        }
    }

    qd << "가장 길이가 긴 단어:"<< char_max;




    qd << "등장하는 알파벳들 갯수 :" << uniqueChar.size();

    QList<QChar> listChar = uniqueChar.values();
    std::sort(listChar.begin(), listChar.end());

    qd << "등장하는 알파벳들: ";

    for(auto a : listChar){
        qd << a;
    }

    #endif

    QString origin = "listen silent enlist google inlets banana";

    QList<QString> words;
    QMap<QString, QList<QString> > anagram;

    words = origin.split(" ", Qt::SkipEmptyParts);
    for (const QString& word : words){
        QString eachWord = word;
        std::sort(eachWord.begin(), eachWord.end());
        anagram[eachWord].append(word);
    }

    // qd << anagram;

    for (auto it = anagram.begin(); it != anagram.end(); it++){
        qd << it.key() << ":" << it.value();
    }

}

Quiz::~Quiz()
{

}
