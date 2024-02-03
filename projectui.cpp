#include "projectui.h"
#include "ui_projectui.h"
#include "addtask.h"
#include "deletetask.h"
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
    //QWidget::close()

    QPushButton* add_task = new QPushButton(this);

    add_task->setStyleSheet("QPushButton{"
                            "font-size: 10px;"
                            "color: white;"
                            "border-style: solid;"
                            "border-width:2px;"
                            "border-radius: 10px;"
                            "background-color: black;"
                            "border-color: yellow;"
                            "font: bold 15px}");

    task.append(add_task);

    add_task->resize(540,30);
    add_task->move(_move,_move2);
    add_task->show();
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
    task[task.size() -1]->setText("Name Of Task: " + item + "   Performer: " + item2 + "   Time: " + item3);
}


void ProjectUi::on_pushButton_remove_clicked()
{
    deleteTask * task_widget2 = new deleteTask();
    task_widget2->show();

    connect(task_widget2,SIGNAL(ItemDeleted(QString)),this,SLOT(DeleteItem(QString)));
}

void ProjectUi::DeleteItem(QString item2)
{
    int test = 0;
    for(int i = 0; i < task.size(); i++)
    {
        if(task[i]->text().contains(item2))
        {
            delete(task[i]);
            for(int j = i + 1; j < task.size(); j++)
            {
                if(task[j]->x() < 170)
                {
                    task[j]->move(165, task[j]->y() - 40);
                }
            }
            test = 1;
            task.erase(task.begin() + i);
            _move2 -= 40;
        }

    }
    if(!test)
        QMessageBox::critical(this,"Error!","There isn't any task with this name.");
}

