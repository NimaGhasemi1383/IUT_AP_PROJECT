#include "projectui.h"
#include "ui_projectui.h"
#include "addtask.h"
#include "deletetask.h"
#include "edittask.h"
#include <QFile>
#include <QTextStream>
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

    QFile FOrg("tasks.txt");
    FOrg.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&FOrg);
    while (!in.atEnd())
    {
        QPushButton *add_task = new QPushButton(this);

        add_task->setText(in.readLine());

        add_task->setCursor(Qt::OpenHandCursor);

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

        //connect(add_task,SIGNAL(clicked()),this,SLOT(orgui_btn_clicked()));

        add_task->resize(540,30);
        add_task->move(_move,_move2);
        add_task->show();
        _move2 += 40;
    }
    FOrg.close();
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

    add_task->setCursor(Qt::OpenHandCursor);

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

    QFile fOrg("tasks.txt");
    fOrg.open(QIODevice::WriteOnly | QFile::Text |QIODevice::Append);
    QTextStream out(&fOrg);
    out << "Name Of Task: " + item + "   Performer: " + item2 + "   Time: " + item3 << "\n";
    fOrg.close();
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


    QFile fOrg("tasks.txt");
    fOrg.open(QIODevice::ReadWrite | QFile::Text);
    QTextStream in(&fOrg);
    QStringList lines;
    while(!in.atEnd())
    {
        lines.append(in.readLine());
    }
    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i].contains(item2));
        {
            lines.removeAt(i);
        }
    }
    fOrg.resize(0);
    QTextStream out(&fOrg);
    foreach(const QString &line, lines)
    {
        out << line << "\n";
    }
    fOrg.close();
}


void ProjectUi::on_pushButton_edit_clicked()
{
    EditTask *edit_widget = new EditTask();
    edit_widget->show();
    connect(edit_widget,SIGNAL(ItemEdited(QString,QString,QString)),this,SLOT(EditItem(QString,QString,QString)));
}

void ProjectUi::EditItem(QString item1, QString item2 , QString item3)
{
    for (int i=0 ; i<task.size() ; i++){
        if(task[i]->text().contains(item3)){
            task[i]->setText("Name Of Task: " + item2 + "   Performer: " + item1 + "   Time: " + item3);
        }
    }

    QFile fOrg("tasks.txt");
    fOrg.open(QIODevice::ReadWrite | QFile::Text);
    QTextStream in(&fOrg);
    QStringList lines;
    while(!in.atEnd())
    {
        lines.append(in.readLine());
    }
    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i].contains(item1))
        {
            lines[i] = "Name Of Task: " + item2 + "   Performer: " + item1 + "   Time: " + item3;
        }
    }
    fOrg.resize(0);
    QTextStream out(&fOrg);
    foreach(const QString &line, lines)
    {
        out << line << "\n";
    }
    fOrg.close();
}

