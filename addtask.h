#ifndef ADDTASK_H
#define ADDTASK_H

#include <QWidget>

namespace Ui {
class addTask;
}

class addTask : public QWidget
{
    Q_OBJECT

public:
    explicit addTask(QWidget *parent = nullptr);
    ~addTask();

signals:
    void ItemAdded(QString item1 , QString item2 , QString item3);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::addTask *ui;
};

#endif // ADDTASK_H
