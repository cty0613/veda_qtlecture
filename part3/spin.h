#ifndef SPIN_H
#define SPIN_H

#include <QObject>
#include <QLabel>
#include <QPushButton>

class spin : public QWidget
{
    Q_OBJECT
public:
    explicit spin(QWidget *parent = nullptr);

private:
    QLabel* label;
    QPushButton* upButton;
    QPushButton* downButton;

signals:
    void signalWidgetLabel(int);

private slots:
    void upButtonClicked();
    void downButtonClicked();
    void setLabel(int);
};

#endif // SPIN_H

