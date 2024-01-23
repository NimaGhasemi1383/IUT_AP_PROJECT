#include "organization.h"
#include "ui_organization.h"
#include "inorg.h"
#include "outorg.h"
#include "orgui.h"
#include "editorg.h"
#include <QMessageBox>
#include <QPixmap>
#define ORG ":/Login/Login19.png"

Organization::Organization(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Organization)
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

Organization::~Organization()
{
    delete ui;
}


void Organization::on_pushButton_add_clicked()
{
    inOrg * org_widget = new inOrg();
    org_widget->show();
    //QWidget::close();

    if(num == 0)
    {
        add_org = new QPushButton*[100];
        for(int i = 0; i < 100; i++)
        {
            add_org[i] = new QPushButton(this);
            add_org[i]->setStyleSheet("QPushButton{"
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
    connect(add_org[num],SIGNAL(clicked()),this,SLOT(orgui_btn_clicked()));
    add_org[num]->resize(92,36);
    add_org[num]->move(_move,_move2);
    add_org[num]->show();
    num++;
    _move += 100;
    if (_move >=700){
        _move = 165;
        _move2 += 40;
    }
    connect(org_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddItem(QString)));
}


void Organization::on_pushButton_remove_clicked()
{
    outorg * org_widget2 = new outorg();
    org_widget2->show();

    connect(org_widget2,SIGNAL(ItemAdded2(QString)),this,SLOT(DeleteItem(QString)));
}

void Organization::AddItem(QString item)
{
    add_org[num -1]->setText(item);
}

void Organization::DeleteItem(QString item2)
{
    for(int i = 0; i < 100; i++)
    {
        if(add_org[i]->text() == item2)
        {
            delete(add_org[i]);
            for(int j = i + 1; j < 100 ; j++)
            {
                if(add_org[j]->x() > 170)
                {
                    add_org[j]->move(add_org[j]->x() - 100, add_org[j]->y());
                }
                else
                {
                    add_org[j]->move(640, add_org[j]->y() - 40);
                }
            }
            return;
        }

    }
    QMessageBox::critical(this,"Error!","There isn't any organization with this name.");
}

void Organization::orgui_btn_clicked()
{
    OrgUi *orgui_widget = new OrgUi();
    orgui_widget->show();
}


void Organization::on_pushButton_edit_clicked()
{
    EditOrg *edit_widget = new EditOrg();
    edit_widget->show();
    connect(edit_widget,SIGNAL(ItemAdded3(QString,QString)),this,SLOT(EditItem(QString,QString)));
}

void Organization::EditItem(QString item1, QString item2)
{
    for (int i=0 ; i<100 ; i++){
        if(item1 == add_org[i]->text()){
            add_org[i]->setText(item2);
        }
    }
}

