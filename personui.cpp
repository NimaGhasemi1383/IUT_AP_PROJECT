#include "personui.h"
#include "ui_personui.h"
#include "addperson.h"
#include "deleteperson.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "editperson.h"
#include "teamui.h"
#define ORG ":/Login/Login19.png"

personUi::personUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::personUi)
{
    ui->setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);
    this->resize(800,700);

    QPixmap bkgnd(ORG);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QFile FOrg("persons.txt");
    FOrg.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&FOrg);
    while (!in.atEnd())
    {
        QPushButton *add_person = new QPushButton(this);

        add_person->setText(in.readLine());

        add_person->setCursor(Qt::OpenHandCursor);

        add_person->setStyleSheet("QPushButton{"
                               "font-size: 10px;"
                               "color: white;"
                               "border-style: solid;"
                               "border-width:2px;"
                               "border-radius: 10px;"
                               "background-color: black;"
                               "border-color: yellow;"
                               "font: bold 15px}");

        person.append(add_person);

        //connect(person_widget,SIGNAL(ItemAdded(QString,QString)),this,SLOT(AddItem(QString,QString)));

        add_person->resize(270,30);
        add_person->move(_move,_move2);
        add_person->show();

        _move += 280;
        if (_move >=600){
            _move = 165;
            _move2 += 40;
        }
    }
    FOrg.close();
}

personUi::~personUi()
{
    delete ui;
}

void personUi::on_pushButton_add_clicked()
{
    addPerson * person_widget = new addPerson();
    person_widget->show();
    //QWidget::close();

    QPushButton* add_person = new QPushButton(this);

    add_person->setCursor(Qt::OpenHandCursor);

    add_person->setStyleSheet("QPushButton{"
                                 "font-size: 10px;"
                                 "color: white;"
                                 "border-style: solid;"
                                 "border-width:2px;"
                                 "border-radius: 10px;"
                                 "background-color: black;"
                                 "border-color: yellow;"
                                 "font: bold 15px}");

    person.append(add_person);

    person[num]->resize(270,30);
    person[num]->move(_move,_move2);
    person[num]->show();
    num++;

    _move += 280;
    if (_move >=600){
        _move = 165;
        _move2 += 40;
    }
    connect(person_widget,SIGNAL(ItemAdded(QString,QString)),this,SLOT(AddItem(QString,QString)));

}


void personUi::AddItem(QString item , QString item2)
{
    person[person.size() -1]->setText("Name: " + item + "          Role: " + item2);

    QFile fOrg("persons.txt");
    fOrg.open(QIODevice::WriteOnly | QFile::Text |QIODevice::Append);
    QTextStream out(&fOrg);
    out << "Name: " + item + "          Role: " + item2 << "\n";
    fOrg.close();
}




void personUi::on_pushButton_remove_clicked()
{
    deletePerson * person_widget2 = new deletePerson();
    person_widget2->show();

    connect(person_widget2,SIGNAL(ItemDeleted(QString)),this,SLOT(DeleteItem(QString)));
}

void personUi::DeleteItem(QString item2)
{
    int test = 0;

    for(int i = 0; i < person.size(); i++)
    {
        if(person[i]->text().contains(item2))
        {
            delete(person[i]);
            for(int j = i + 1; j < person.size() ; j++)
            {
                if(person[j]->x() > 170)
                {
                    person[j]->move(person[j]->x() - 280, person[j]->y());
                }
                else
                {
                    person[j]->move(445, person[j]->y() - 40);
                }
            }
            test = 1;
            _move -= 280;
            if (_move >=600){
                _move = 165;
                _move2 -= 40;
            }
        }
    }
    if(!test)
        QMessageBox::critical(this,"Error!","There isn't any person with this name.");


    QFile fOrg("persons.txt");
    fOrg.open(QIODevice::ReadWrite | QFile::Text);
    QTextStream in(&fOrg);
    QStringList lines;
    while(!in.atEnd())
    {
        lines.append(in.readLine());
    }
    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i].contains(item2))
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


void personUi::on_pushButton_edit_clicked()
{
    editPerson *edit_widget = new editPerson();
    edit_widget->show();
    connect(edit_widget,SIGNAL(ItemEdited(QString,QString)),this,SLOT(EditItem(QString,QString)));
}

void personUi::EditItem(QString item1, QString item2)
{
    for (int i=0 ; i < person.size(); i++){
        if(person[i]->text().contains(item1)){
            person[i]->setText("Name: " + item1 + "          Role: " + item2);
        }
    }


    QFile fOrg("persons.txt");
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
            lines[i] = "Name: " + item1 + "          Role: " + item2;
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


void personUi::on_pushButton_Back_clicked()
{
    teamUi *s_in = new teamUi();
    s_in->show();
    QWidget::close();
}

