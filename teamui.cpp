#include "teamui.h"
#include "ui_teamui.h"
#include "addproject.h"
#include "projectui.h"
#include "deleteproject.h"
#include "editproject.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
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

    QFile FOrg("C:/Qt/untitled2/projects.txt");
    FOrg.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&FOrg);
    while (!in.atEnd())
    {
        QPushButton *add_project = new QPushButton(this);

        add_project->setText(in.readLine());

        add_project->setCursor(Qt::OpenHandCursor);

        add_project->setStyleSheet("QPushButton{"
                               "font-size: 10px;"
                               "color: white;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius: 10px;"
                               "background-color: black;"
                               "border-color: yellow;"
                               "font: bold 15px}");

        project.append(add_project);

        connect(add_project,SIGNAL(clicked()),this,SLOT(projectui_btn_clicked()));

        add_project->resize(92,36);
        add_project->move(_move,_move2);
        add_project->show();
        _move += 100;
        if (_move >=700){
            _move = 165;
            _move2 += 40;
        }
    }
    FOrg.close();
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

    QPushButton* add_project = new QPushButton(this);

    add_project->setCursor(Qt::OpenHandCursor);

    add_project->setStyleSheet("QPushButton{"
                               "font-size: 10px;"
                               "color: white;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius: 10px;"
                               "background-color: black;"
                               "border-color: yellow;"
                               "font: bold 15px}");

    project.append(add_project);

    connect(add_project,SIGNAL(clicked()),this,SLOT(projectui_btn_clicked()));
    add_project->resize(92,36);
    add_project->move(_move,_move2);
    add_project->show();

    _move += 100;
    if (_move >=700){
        _move = 165;
        _move2 += 40;
    }
    connect(project_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddItem(QString)));
}


void teamUi::AddItem(QString item)
{
    project[project.size() -1]->setText(item);

    QFile fOrg("C:/Qt/untitled2/projects.txt");
    fOrg.open(QIODevice::WriteOnly | QFile::Text |QIODevice::Append);
    QTextStream out(&fOrg);
    out << item << "\n";
    fOrg.close();
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
    int test = 0;

    for(int i = 0; i < project.size(); i++)
    {
        if(project[i]->text() == item2)
        {
            delete(project[i]);
            for(int j = i + 1; j < project.size(); j++)
            {
                if(project[j]->x() > 170)
                {
                    project[j]->move(project[j]->x() - 100, project[j]->y());
                }
                else
                {
                    project[j]->move(640, project[j]->y() - 40);
                }
            }
            test = 1;
            project.erase(project.begin() + i);

            _move += 100;
            if (_move >=700){
                _move = 165;
                _move2 += 40;
            }
        }
    }
    if(!test)
        QMessageBox::critical(this,"Error!","There isn't any project with this name.");

    QFile fOrg("C:/Qt/untitled2/projects.txt");
    fOrg.open(QIODevice::ReadWrite | QFile::Text);
    QTextStream in(&fOrg);
    QStringList lines;
    while(!in.atEnd())
    {
        lines.append(in.readLine());
    }
    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i] == item2)
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


void teamUi::on_pushButton_edit_clicked()
{
    editProject *edit_widget = new editProject();
    edit_widget->show();
    connect(edit_widget,SIGNAL(ItemEdited(QString,QString)),this,SLOT(EditItem(QString,QString)));
}

void teamUi::EditItem(QString item1, QString item2)
{
    for (int i=0 ; i< project.size() ; i++){
        if(item1 == project[i]->text()){
            project[i]->setText(item2);
        }
    }

    QFile fOrg("C:/Qt/untitled2/projects.txt");
    fOrg.open(QIODevice::ReadWrite | QFile::Text);
    QTextStream in(&fOrg);
    QStringList lines;
    while(!in.atEnd())
    {
        lines.append(in.readLine());
    }
    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i] == item1)
        {
            lines[i] = item2;
        }
    }
    fOrg.resize(0);
    //herllo
    QTextStream out(&fOrg);
    foreach(const QString &line, lines)
    {
        out << line << "\n";
    }
    fOrg.close();
}


void teamUi::on_pushButton_clicked()
{
    personUi *person_widget = new personUi();
    person_widget->show();
}

