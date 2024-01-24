#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QWidget>

namespace Ui {
class editPerson;
}

class editPerson : public QWidget
{
    Q_OBJECT

public:
    explicit editPerson(QWidget *parent = nullptr);
    ~editPerson();

signals:
    void ItemEdited(QString item1 , QString item2);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::editPerson *ui;
};

#endif // EDITPERSON_H
