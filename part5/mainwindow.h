#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mdimainwindow.h"

#include <QMainWindow>

#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QStatusBar>
#include <QDebug>
#include <QMdiSubWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QMenu* fileMenu;
    QMenu* prefMenu;
    QAction* newAct; // 프로그램 액션 (보통 상단 메뉴에서 등장)
    QAction* openAct;
    QAction* openList;
    QAction* closeList;

    QDockWidget *dock;
    QListWidget *customerList;

private slots:
    void newFile();
    void open();
    void open_list();
    void close_list();
};
#endif // MAINWINDOW_H
