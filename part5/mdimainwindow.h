#ifndef MDIMAINWINDOW_H
#define MDIMAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>

class MDIMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MDIMainWindow(QWidget *parent = nullptr);

signals:
};

#endif // MDIMAINWINDOW_H
