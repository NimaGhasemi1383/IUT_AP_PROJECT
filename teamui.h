#ifndef TEAMUI_H
#define TEAMUI_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class teamUi;
}

class teamUi : public QWidget
{
    Q_OBJECT

public:
    explicit teamUi(QWidget *parent = nullptr);
    ~teamUi();

private slots:
    void on_pushButton_add_clicked();

    void AddItem(QString);

    void projectui_btn_clicked();

    void on_pushButton_remove_clicked();

    void DeleteItem(QString);

    void on_pushButton_edit_clicked();

    void EditItem(QString , QString);

    void on_pushButton_clicked();

private:
    Ui::teamUi *ui;
    QPushButton **add_project;
    int num = 0;
    int _move = 165;
    int _move2 = 90;
};

#endif // TEAMUI_H
