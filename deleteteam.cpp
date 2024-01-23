#include "deleteteam.h"
#include "ui_deleteteam.h"

DeleteTeam::DeleteTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteTeam)
{
    ui->setupUi(this);
}

DeleteTeam::~DeleteTeam()
{
    delete ui;
}
