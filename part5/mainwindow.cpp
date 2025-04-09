#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this); // 액션 아이콘
    newAct->setShortcuts(QKeySequence::New); // 액션 단축키 (Ctrl+N)
    newAct->setStatusTip(tr("Create a New Project")); // 액션 툴팁
    newAct->setToolTip("Create a New Project");
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile())); // 액션을 선택했을때의 sig-slt

    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an Existing file"));
    openAct->setToolTip("Open an Existing file");
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    openList = new QAction(QIcon(":/images/copy.png"), tr("&Open List"), this);
    openAct->setShortcuts(QKeySequence::AddTab);
    openAct->setStatusTip(tr("Open an List Widget"));
    connect(openList, SIGNAL(triggered()), this, SLOT(open_list()));

    closeList = new QAction(QIcon(":/images/cut.png"), tr("&Close List"), this);
    openAct->setShortcuts(QKeySequence::Close);
    openAct->setStatusTip(tr("Close an List Widget"));
    connect(closeList, SIGNAL(triggered()), this, SLOT(close_list()));

    fileMenu = menuBar()->addMenu(tr("&File")); // 상단 메뉴바 항목 추가
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);

    prefMenu = menuBar()->addMenu(tr("&Option"));
    prefMenu->addAction(openList);
    prefMenu->addAction(closeList);

    QToolBar *fileToolBar;
    fileToolBar = addToolBar(tr("File")); // 툴바 항목 추가
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);

    dock = new QDockWidget(tr("Target"), this); // 위젯 레이아웃(독)
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea); // 허용 구역

    customerList = new QListWidget(dock); // 우측 리스트 위젯
    customerList->addItems(
        QStringList() << "One" << "Two" << "Three" << "Four" << "Five");

    dock->setWidget(customerList); // 우측 리스트 위젯 추가
    addDockWidget(Qt::RightDockWidgetArea, dock);
    setCentralWidget(new MDIMainWindow()); // 좌측에 MDI 윈도우 추가
    statusBar()->showMessage(tr("Ready")); // 상태바에 "Ready" 표시
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile(){
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::open(){
    qDebug() << Q_FUNC_INFO;
}

void MainWindow::open_list(){
    qDebug() << Q_FUNC_INFO;
    dock->show();
    dock->setFocus();

}

void MainWindow::close_list(){
    qDebug() << Q_FUNC_INFO;
    dock->hide();

}

