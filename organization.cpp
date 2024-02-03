#include "organization.h"
#include "ui_organization.h"
#include "inorg.h"
#include "outorg.h"
#include "orgui.h"
#include "editorg.h"
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
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

    QFile FOrg("organizations.txt");
    FOrg.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&FOrg);
    while (!in.atEnd())
    {
        QPushButton *add_org = new QPushButton(this);

        add_org->setText(in.readLine());

        add_org->setCursor(Qt::OpenHandCursor);

        add_org->setStyleSheet("QPushButton{"
                               "font-size: 10px;"
                               "color: white;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius: 10px;"
                               "background-color: black;"
                               "border-color: yellow;"
                               "font: bold 15px}");

        org.append(add_org);

        connect(add_org,SIGNAL(clicked()),this,SLOT(orgui_btn_clicked()));

        add_org->resize(92,36);
        add_org->move(_move,_move2);
        add_org->show();
        _move += 100;
        if (_move >=700){
            _move = 165;
            _move2 += 40;
        }
    }
    FOrg.close();
}

Organization::~Organization()
{
    delete ui;
}

int n =0;
void Organization::on_pushButton_add_clicked()
{
    inOrg * org_widget = new inOrg();
    org_widget->show();
    //QWidget::close();

    QPushButton *add_org = new QPushButton(this);

    add_org->setCursor(Qt::OpenHandCursor);

    org.push_back(add_org);

    add_org->setStyleSheet("QPushButton{"
                              "font-size: 10px;"
                              "color: white;"
                              "border-style: solid;"
                              "border-width:2px;"
                              "border-radius: 10px;"
                              "background-color: black;"
                              "border-color: yellow;"
                              "font: bold 15px}");

    //connect(add_org,SIGNAL(clicked()),org_widget,SIGNAL(ItemAdded(QString)));

    connect(org_widget,SIGNAL(ItemAdded(QString)),this,SLOT(AddItem(QString)));

    connect(org[n],SIGNAL(clicked()),this,SLOT(orgui_btn_clicked()));

    //org.push_back(add_org);


    add_org->resize(92,36);
    add_org->move(_move,_move2);
    add_org->show();
    _move += 100;
    if (_move >=700){
        _move = 165;
        _move2 += 40;
    }
}


void Organization::on_pushButton_remove_clicked()
{
    outorg * org_widget2 = new outorg();
    org_widget2->show();

    connect(org_widget2,SIGNAL(ItemAdded2(QString)),this,SLOT(DeleteItem(QString)));
}

void Organization::AddItem(QString item)
{
    org[org.size() - 1]->setText(item);
    //n++;

    QFile fOrg("organizations.txt");
    fOrg.open(QIODevice::WriteOnly | QFile::Text |QIODevice::Append);
    QTextStream out(&fOrg);
    out << item << "\n";
    fOrg.close();
}

void Organization::DeleteItem(QString item2)
{
    int i = 0;
    int test=0;
    for(i = 0; i < org.size(); i++)
    {
        if(org[i]->text() == item2)
        {
            test=1;
            delete(org[i]);
            for(int j = i + 1; j < org.size(); j++)
            {
                if(org[j]->x() > 170)
                {
                    org[j]->move(org[j]->x() - 100, org[j]->y());
                }
                else
                {
                    org[j]->move(665, org[j]->y() - 40);
                }
            }
             org.erase(org.begin()+i);
            _move-=100;
             if (_move >= 700){
                 _move = 165;
                 _move2 -= 40;
             }
        }
    }
    if (!test)
    {
        QMessageBox::critical(this,"Error!","There isn't any organization with this name.");
    }


    QFile fOrg("organizations.txt");
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

    // int k =0;
    // for(int i = 0; i < org.size() + 2; i++)
    // {
    //     if(org[i]->text() == item2)
    //     {
    //         //org.remove(i);
    //         delete(org[i]);
    //         for(int j = i + 1; j < org.size(); j++)
    //         {
    //             if(org[j]->x() > 170)
    //             {
    //                 org[j]->move(org[j]->x() - 100, org[j]->y());
    //             }
    //             else
    //             {
    //                 org[j]->move(665, org[j]->y() - 40);
    //             }
    //         }
    //         k++;
    //         return;
    //     }

    // }
    // QMessageBox::critical(this,"Error!","There isn't any organization with this name.");
}

void Organization::orgui_btn_clicked()
{
    //QPushButton *golabi = qobject_cast<QPushButton *>(sender());
    //if(golabi){
    OrgUi *org_widget = new OrgUi();
    org_widget->show();
        //orgui_widget->setWindowTitle(QString::number(n));
   // vec_org.append(org_widget);
   // vec_org[n]->show();
    n++;
    //orgui_widget->show();
    //setFocus();
    //n++;
    //}
}


void Organization::on_pushButton_edit_clicked()
{
    EditOrg *edit_widget = new EditOrg();
    edit_widget->show();
    connect(edit_widget,SIGNAL(ItemAdded3(QString,QString)),this,SLOT(EditItem(QString,QString)));
}

void Organization::EditItem(QString item1, QString item2)
{
    for (int i=0 ; i < org.size() ; i++){
        if(item1 == org[i]->text()){
            org[i]->setText(item2);
        }
    }

    QFile fOrg("organizations.txt");
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

