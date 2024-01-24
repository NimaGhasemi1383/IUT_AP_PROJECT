#include "editperson.h"
#include "ui_editperson.h"
#include <QMessageBox>
#define ORG ":/Login/Login19.png"

editPerson::editPerson(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editPerson)
{
    ui->setupUi(this);

    //setWindowFlag(Qt::FramelessWindowHint);
    this->resize(622,199);

    QPixmap bkgnd(ORG);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->lineEdit_nameorg->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_nameorg_2->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");
    ui->lineEdit_nameorg_3->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");

    ui->pushButton_ok->setStyleSheet("QPushButton{"
                                     "font-size: 25px;"
                                     "color: Blue;"
                                     "border-style: solid;"
                                     "border-width:2px;"
                                     "border-radius: 10px;"
                                     "background-color: Black;"
                                     "border-color: green;"
                                     "font: bold 20px}");
}

editPerson::~editPerson()
{
    delete ui;
}

void editPerson::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_nameorg_3->text() == "" || ui->lineEdit_nameorg_2->text() == "")
    {
        QMessageBox::critical(this,"Error!","Please Fill In The Blank.");
        return;
    }
    emit ItemEdited(ui->lineEdit_nameorg_3->text() , ui->lineEdit_nameorg_2->text());
    QWidget::close();
}

