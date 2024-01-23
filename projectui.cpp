#include "projectui.h"
#include "ui_projectui.h"

ProjectUi::ProjectUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectUi)
{
    ui->setupUi(this);
}

ProjectUi::~ProjectUi()
{
    delete ui;
}
