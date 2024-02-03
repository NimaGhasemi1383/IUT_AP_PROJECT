#ifndef ORGUI_H
#define ORGUI_H

#include <QWidget>
#include <QPushButton>
#include "inorg.h"
#include "organization.h"

namespace Ui {
class OrgUi;
}

class OrgUi : public QWidget
{
    Q_OBJECT

public:
    explicit OrgUi(QWidget *parent = nullptr);
    ~OrgUi();

private slots:
    void on_pushButton_add_2_clicked();

    void AddItem(QString);

    void teamui_btn_2_clicked();

    void on_pushButton_remove_clicked();

    void DeleteItem(QString);

    void EditItem(QString , QString);

    void on_pushButton_edit_2_clicked();

    void on_pushButton_Back_clicked();

private:
    Ui::OrgUi *ui;
    QVector<QPushButton*> team;
    int num = 0;
    int _move = 165;
    int _move2 = 90;
    int count=0;
};

#endif // ORGUI_H
