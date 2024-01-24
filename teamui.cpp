#include "teamui.h"
#include "ui_teamui.h"
#include "addproject.h"
#include "projectui.h"
#include "deleteproject.h"
#include "editproject.h"
#include <QMessageBox>
#include "personui.h"
#define ORG ":/Login/Login19.png"

teamUi::teamUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::teamUi)
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

teamUi::~teamUi()
{
    delete ui;
}

void teamUi::on_pushButton_add_clicked()
{
    addProject * project_widget = new addProject();
    project_widget->show();
    //QWidget::close();

    if(num == 0)
    {
        add_project = new QPushButton*[100];
        for(int i = 0; i < 100; i++)
        {
            add_project[i] = new QPushButton(this);
            add_project[i]->setStyleSheet("QPushButton{"
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
    connect(add_project[num],SIGNAL(clicked()),this,SLOT(projectui_btn_clicked()));
    add_project[num]->resize(92,36);
    add_project[num]->move(_move,_move2);
    add_project[num]->show();
    num++;
    _move += 100;
    if (_move >=700){
        _move = 165;
        _move2 += 40;
    }
    connect(project_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddItem(QString)));
}


void teamUi::AddItem(QString item)
{
    add_project[num -1]->setText(item);
}

void teamUi::projectui_btn_clicked()
{
    ProjectUi *projectui_widget = new ProjectUi();
    projectui_widget->show();
}


void teamUi::on_pushButton_remove_clicked()
{
    deleteProject * project_widget2 = new deleteProject();
    project_widget2->show();

    connect(project_widget2,SIGNAL(ItemDeleted(QString)),this,SLOT(DeleteItem(QString)));
}

void teamUi::DeleteItem(QString item2)
{
    for(int i = 0; i < 100; i++)
    {
        if(add_project[i]->text() == item2)
        {
            delete(add_project[i]);
            for(int j = i + 1; j < 100 ; j++)
            {
                if(add_project[j]->x() > 170)
                {
                    add_project[j]->move(add_project[j]->x() - 100, add_project[j]->y());
                }
                else
                {
                    add_project[j]->move(640, add_project[j]->y() - 40);
                }
            }
            return;
        }
    }
    QMessageBox::critical(this,"Error!","There isn't any project with this name.");
}


void teamUi::on_pushButton_edit_clicked()
{
    editProject *edit_widget = new editProject();
    edit_widget->show();
    connect(edit_widget,SIGNAL(ItemEdited(QString,QString)),this,SLOT(EditItem(QString,QString)));
}

void teamUi::EditItem(QString item1, QString item2)
{
    for (int i=0 ; i<100 ; i++){
        if(item1 == add_project[i]->text()){
            add_project[i]->setText(item2);
        }
    }
}


void teamUi::on_pushButton_clicked()
{
    personUi *person_widget = new personUi();
    person_widget->show();
}

