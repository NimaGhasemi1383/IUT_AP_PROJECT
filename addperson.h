#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QWidget>

namespace Ui {
class addPerson;
}

class addPerson : public QWidget
{
    Q_OBJECT

public:
    explicit addPerson(QWidget *parent = nullptr);
    ~addPerson();

private slots:
    void on_pushButton_ok_clicked();

signals:
    void ItemAdded(QString item1 , QString item2);

private:
    Ui::addPerson *ui;
};

#endif // ADDPERSON_H
