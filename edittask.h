#ifndef EDITTASK_H
#define EDITTASK_H

#include <QWidget>

namespace Ui {
class EditTask;
}

class EditTask : public QWidget
{
    Q_OBJECT

public:
    explicit EditTask(QWidget *parent = nullptr);
    ~EditTask();

signals:
    void ItemEdited(QString item1 , QString item2 , QString item3);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::EditTask *ui;
};

#endif // EDITTASK_H
