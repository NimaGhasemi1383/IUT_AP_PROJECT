#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Organization;
}

class Organization : public QWidget
{
    Q_OBJECT

public:
    explicit Organization(QWidget *parent = nullptr);
    ~Organization();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void AddItem(QString);

    void DeleteItem(QString);

    void orgui_btn_clicked();

    void on_pushButton_edit_clicked();

    void EditItem(QString , QString);

private:
    Ui::Organization *ui;
    QPushButton **add_org;
    int num = 0;
    int _move = 165;
    int _move2 = 90;
};

#endif // ORGANIZATION_H
