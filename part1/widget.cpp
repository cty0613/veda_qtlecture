#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    int xpos = 30;
    int ypos = 30;

    dtWidget = new dateTime(this); // render child (dateTime)
    dtWidget->setGeometry(xpos, ypos+200, 300, 300); // set Position


    QString str1[3] = {"Game", "Office", "Develop"};
    QString str2[3] = {"Programing", "Qt", "OS"};



    m_chk_group[0] = new QButtonGroup(this); // Game Office Develop ChkButtonGroup
    m_chk_group[1] = new QButtonGroup(this); // Programing Qt OS ChkButtonGroup



    for(int i=0; i<3; i++){
        m_exclusive[i] = new QCheckBox(str1[i], this); // Game Office Develop each, CheckBox Obj.
        m_exclusive[i]->setGeometry(xpos, ypos, 120, 30); // Obj Position, Size
        m_chk_group[0]->addButton(m_exclusive[i]); // add CheckBoxes Obj to ChkButtonGroup

        m_non_exclusive[i] = new QCheckBox(str2[i], this); // Programing Qt OS
        m_non_exclusive[i]->setGeometry(xpos+120, ypos, 120, 30); // UI Position, Size
        m_chk_group[1]->addButton(m_exclusive[i]);

        connect( // Event Listener Connect
            m_exclusive[i],
            SIGNAL(clicked()),
            this,
            SLOT(slot_chkChanged()));

        ypos += 40;
    }

    m_chk_group[0]->setExclusive(false);
    m_chk_group[1]->setExclusive(true);

    m_exclusive[0]->setIcon(QIcon("://res/users.png"));
    m_exclusive[1]->setIcon(QIcon("://res/calendar.png"));
    m_exclusive[2]->setIcon(QIcon("://res/chat.png"));

    m_non_exclusive[0]->setIcon(QIcon("://res/editor.png"));
    m_non_exclusive[1]->setIcon(QIcon("://res/mail.png"));
    m_non_exclusive[2]->setIcon(QIcon("://res/users.png"));

    ui->comboBox->addItem(QIcon("://res/browser.png"), "Application");
    ui->comboBox->addItem(QIcon("://res/mail.png"), "Graphics");
    ui->comboBox->addItem(QIcon("://res/browser.png"), "Database");
    ui->comboBox->addItem(QIcon("://res/browser.png"), "Networks");

    connect( //  일종의 이벤트 리스너
        ui->pushButton1,
        &QPushButton::clicked,
        this,
        [this](){ // callback
            qDebug() << "pushButton 1 clicked" ;
        }
    );

    connect(
        ui->pushButton2,
        SIGNAL(clicked()), // 이벤트 리스너
        this,
        SLOT(btn_clicked()) // 이벤트 발생시 실행되는 함수
        );
}

void Widget::slot_chkChanged()
{
    for(int i = 0 ; i < 3 ; i++) {
        if(m_exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ", i+1);
        }
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::btn_clicked(){
    qDebug() << "pushButton 2 clicked";
}
