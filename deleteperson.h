#ifndef DELETEPERSON_H
#define DELETEPERSON_H

#include <QWidget>

namespace Ui {
class deletePerson;
}

class deletePerson : public QWidget
{
    Q_OBJECT

public:
    explicit deletePerson(QWidget *parent = nullptr);
    ~deletePerson();

signals:
    void ItemDeleted(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::deletePerson *ui;
};

#endif // DELETEPERSON_H
