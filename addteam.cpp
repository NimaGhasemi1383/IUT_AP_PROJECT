#include "addteam.h"
#include "ui_addteam.h"
#include <QMessageBox>

AddTeam::AddTeam(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddTeam)
{
    ui->setupUi(this);
}

AddTeam::~AddTeam()
{
    delete ui;
}

void AddTeam::on_pushButton_ok_clicked()
{
    if(ui->lineEdit_nameorg->text() == "")
    {
        QMessageBox::critical(this,"Error!","Please Enter The Name Of Team.");
        return;
    }
    emit ItemAdded(ui->lineEdit_nameorg->text());
    QWidget::close();
}
