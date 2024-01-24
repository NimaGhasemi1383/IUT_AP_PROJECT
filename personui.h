#ifndef PERSONUI_H
#define PERSONUI_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class personUi;
}

class personUi : public QWidget
{
    Q_OBJECT

public:
    explicit personUi(QWidget *parent = nullptr);
    ~personUi();

private slots:
    void on_pushButton_add_clicked();

    void AddItem(QString,QString);

    void on_pushButton_remove_clicked();

    void DeleteItem(QString);

private:
    Ui::personUi *ui;
    QPushButton **add_person;
    int num = 0;
    int _move = 165;
    int _move2 = 90;
};

#endif // PERSONUI_H
