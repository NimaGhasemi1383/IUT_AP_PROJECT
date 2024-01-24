#include "deleteperson.h"
#include "ui_deleteperson.h"
#include <QMessageBox>
#define ORG ":/Login/Login19.png"

deletePerson::deletePerson(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletePerson)
{
    ui->setupUi(this);

    //setWindowFlag(Qt::FramelessWindowHint);
    this->resize(626,177);

    QPixmap bkgnd(ORG);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    ui->lineEdit_nameorg->setStyleSheet("QLineEdit { border-radius: 10px;background-color: rgb(167, 151, 200); }");

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

deletePerson::~deletePerson()
{
    delete ui;
}

void deletePerson::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_nameorg->text() == "")
    {
        QMessageBox::critical(this,"Error!","Please Fill In The Blank.");
        return;
    }
    emit ItemDeleted(ui->lineEdit_nameorg->text());
    QWidget::close();
}

