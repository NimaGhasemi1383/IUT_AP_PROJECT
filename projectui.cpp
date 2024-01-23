#include "projectui.h"
#include "ui_projectui.h"
#define ORG ":/Login/Login19.png"

ProjectUi::ProjectUi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectUi)
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

ProjectUi::~ProjectUi()
{
    delete ui;
}
