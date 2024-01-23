#include "teamui.h"
#include "ui_teamui.h"

teamUi::teamUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::teamUi)
{
    ui->setupUi(this);
}

teamUi::~teamUi()
{
    delete ui;
}
