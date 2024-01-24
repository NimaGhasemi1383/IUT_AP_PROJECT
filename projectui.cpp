#include "projectui.h"
#include "ui_projectui.h"
#include "addtask.h"
#define ORG ":/Login/Login19.png"

ProjectUi::ProjectUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectUi)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(800,700);

    QPixmap bkgnd(ORG);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

ProjectUi::~ProjectUi()
{
    delete ui;
}

void ProjectUi::on_pushButton_add_clicked()
{
    addTask * task_widget = new addTask();
    task_widget->show();
    //QWidget::close();

    if(num == 0)
    {
        add_task = new QPushButton*[100];
        for(int i = 0; i < 100; i++)
        {
            add_task[i] = new QPushButton(this);
            add_task[i]->setStyleSheet("QPushButton{"
                                          "font-size: 10px;"
                                          "color: Black;"
                                          "border-style: solid;"
                                          "border-width:2px;"
                                          "border-radius: 10px;"
                                          "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));"
                                          "border-color: black;"
                                          "font: bold 15px}");
        }
    }
    add_task[num]->resize(540,30);
    add_task[num]->move(_move,_move2);
    add_task[num]->show();
    num++;
    _move += 280;
    if (_move >=300){
        _move = 165;
        _move2 += 40;
    }
    connect(task_widget,SIGNAL(ItemAdded(QString,QString,QString)),this,SLOT(AddItem(QString,QString,QString)));
}



void ProjectUi::AddItem(QString item , QString item2 , QString item3)
{
    add_task[num -1]->setText("Name Of Task: " + item + "   Performer: " + item2 + "   Time: " + item3);
}

