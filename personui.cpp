#include "personui.h"
#include "ui_personui.h"
#include "addperson.h"
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
    if(num == 0)
    {
        add_person = new QPushButton*[100];
        for(int i = 0; i < 100; i++)
        {
            add_person[i] = new QPushButton(this);
            add_person[i]->setStyleSheet("QPushButton{"
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
    add_person[num]->resize(270,30);
    add_person[num]->move(_move,_move2);
    add_person[num]->show();
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
    add_person[num -1]->setText("Name: " + item + "          Role: " + item2);
}



