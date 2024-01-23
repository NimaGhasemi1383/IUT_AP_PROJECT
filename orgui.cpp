#include "orgui.h"
#include "ui_orgui.h"
#include "addteam.h"
#include <QPixmap>
#include "teamui.h"
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

    if(num == 0)
    {
        add_team = new QPushButton*[100];
        for(int i = 0; i < 100; i++)
        {
            add_team[i] = new QPushButton(this);
            add_team[i]->setStyleSheet("QPushButton{"
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
    connect(add_team[num],SIGNAL(clicked()),this,SLOT(teamui_btn_2_clicked()));
    add_team[num]->resize(92,36);
    add_team[num]->move(_move,_move2);
    add_team[num]->show();
    num++;
    _move += 100;
    if (_move >=700){
        _move = 165;
        _move2 += 40;
    }
    connect(team_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddItem(QString)));
}

void OrgUi::AddItem(QString item)
{
    add_team[num -1]->setText(item);
}

void OrgUi::teamui_btn_2_clicked()
{
    teamUi *teamui_widget = new teamUi();
    teamui_widget->show();
}
