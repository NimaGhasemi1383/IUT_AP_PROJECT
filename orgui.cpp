#include "orgui.h"
#include "ui_orgui.h"
#include "addteam.h"
#include <QPixmap>
#include "teamui.h"
#include "deleteteam.h"
#include "editteam.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
//#include "inorg.h"
#define ORG ":/Login/Login19.png"

OrgUi::OrgUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrgUi)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(800,700);

    QPixmap bkgnd(ORG);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QFile file("C:/Qt/untitled2/New Text Document.txt");
    file.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&file);
    //while(!in.atEnd())
    //{

        QString line = in.readLine();
        QDir().mkdir(line);
        QFile Org_file(line + "/file.txt");
        Org_file.open(QIODevice::ReadOnly | QFile::Text);
        QTextStream in2(&Org_file);
        while (!in2.atEnd())
        {
            QPushButton *add_team = new QPushButton(this);

            add_team->setText(in2.readLine());

            add_team->setCursor(Qt::OpenHandCursor);

            add_team->setStyleSheet("QPushButton{"
                                   "font-size: 10px;"
                                   "color: white;"
                                   "border-style: solid;"
                                   "border-width:2px;"
                                   "border-radius: 10px;"
                                   "background-color: black;"
                                   "border-color: yellow;"
                                   "font: bold 15px}");

            team.append(add_team);

            connect(add_team,SIGNAL(clicked()),this,SLOT(teamui_btn_2_clicked()));

            add_team->resize(92,36);
            add_team->move(_move,_move2);
            add_team->show();
            _move += 100;
            if (_move >=700){
                _move = 165;
                _move2 += 40;
            }
        }
        Org_file.close();
    //}
    file.close();

    // QFile FOrg("C:/Qt/untitled2/teams.txt");
    // FOrg.open(QIODevice::ReadOnly | QFile::Text);
    // QTextStream in(&FOrg);
    // while (!in.atEnd())
    // {
    //     QPushButton *add_team = new QPushButton(this);

    //     add_team->setText(in.readLine());

    //     add_team->setStyleSheet("QPushButton{"
    //                            "font-size: 10px;"
    //                            "color: white;"
    //                            "border-style: solid;"
    //                            "border-width:2px;"
    //                            "border-radius: 10px;"
    //                            "background-color: black;"
    //                            "border-color: yellow;"
    //                            "font: bold 15px}");

    //     team.append(add_team);

    //     connect(add_team,SIGNAL(clicked()),this,SLOT(teamui_btn_2_clicked()));

    //     add_team->resize(92,36);
    //     add_team->move(_move,_move2);
    //     add_team->show();
    //     _move += 100;
    //     if (_move >=700){
    //         _move = 165;
    //         _move2 += 40;
    //     }
    // }
    // FOrg.close();
    //connect(org_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddName(QString)));
}

OrgUi::~OrgUi()
{
    delete ui;
}

void OrgUi::on_pushButton_add_2_clicked()
{
    AddTeam * team_widget = new AddTeam();
    team_widget->show();
    //QWidget::close();

    QPushButton* add_team = new QPushButton(this);

    add_team->setCursor(Qt::OpenHandCursor);

    add_team->setStyleSheet("QPushButton{"
                               "font-size: 10px;"
                               "color: Black;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius: 10px;"
                               "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));"
                               "border-color: black;"
                               "font: bold 15px}");

    team.append(add_team);

    connect(add_team,SIGNAL(clicked()),this,SLOT(teamui_btn_2_clicked()));
    add_team->resize(92,36);
    add_team->move(_move,_move2);
    add_team->show();

    _move += 100;
    if (_move >=700){
        _move = 165;
        _move2 += 40;
    }
    connect(team_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddItem(QString)));
}

void OrgUi::AddItem(QString item)
{
    team[team.size() -1]->setText(item);

    QFile file("C:/Qt/untitled2/New Text Document.txt");
    file.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&file);
    // while(!in.atEnd())
    // {
    QString line;
    //for(int i = 0; i <= count; i++)
        line = in.readLine();
    //count++;

        QDir().mkdir(line);
        QFile Org_file(line + "/file.txt");
        Org_file.open(QIODevice::WriteOnly | QFile::Text | QIODevice::Append);
        QTextStream out(&Org_file);
        out << item << "\n";
        Org_file.close();
    }

    // QFile fOrg("C:/Qt/untitled2/teams.txt");
    // fOrg.open(QIODevice::WriteOnly | QFile::Text |QIODevice::Append);
    // QTextStream out(&fOrg);
    // out << item << "\n";
    // fOrg.close();
//}

void OrgUi::teamui_btn_2_clicked()
{
    teamUi *teamui_widget = new teamUi();
    teamui_widget->show();
}

void OrgUi::on_pushButton_remove_clicked()
{
    DeleteTeam * team_widget2 = new DeleteTeam();
    team_widget2->show();

    connect(team_widget2,SIGNAL(ItemDeleted(QString)),this,SLOT(DeleteItem(QString)));
}

void OrgUi::DeleteItem(QString item2)
{
    int test = 0;
    for(int i = 0; i < team.size(); i++)
    {
        if(team[i]->text() == item2)
        {
            delete(team[i]);
            for(int j = i + 1; j < team.size(); j++)
            {
                if(team[j]->x() > 170)
                {
                    team[j]->move(team[j]->x() - 100, team[j]->y());
                }
                else
                {
                    team[j]->move(640, team[j]->y() - 40);
                }
            }
            test = 1;
            team.erase(team.begin() + i);

            _move += 100;
            if (_move >=700){
                _move = 165;
                _move2 += 40;
            }

        }
    }
    if(!test)
        QMessageBox::critical(this,"Error!","There isn't any team with this name.");


    QFile fOrg("C:/Qt/untitled2/teams.txt");
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

void OrgUi::EditItem(QString item1, QString item2)
{
    for (int i=0 ; i< team.size() ; i++){
        if(item1 == team[i]->text()){
            team[i]->setText(item2);
        }
    }


    QFile fOrg("C:/Qt/untitled2/teams.txt");
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
    QTextStream out(&fOrg);
    foreach(const QString &line, lines)
    {
        out << line << "\n";
    }
    fOrg.close();
}

void OrgUi::on_pushButton_edit_2_clicked()
{
    EditTeam *edit_widget = new EditTeam();
    edit_widget->show();
    connect(edit_widget,SIGNAL(ItemEdited(QString,QString)),this,SLOT(EditItem(QString,QString)));
}

