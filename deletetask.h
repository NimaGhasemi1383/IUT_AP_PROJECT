#ifndef DELETETASK_H
#define DELETETASK_H

#include <QWidget>

namespace Ui {
class deleteTask;
}

class deleteTask : public QWidget
{
    Q_OBJECT

public:
    explicit deleteTask(QWidget *parent = nullptr);
    ~deleteTask();

signals:
    void ItemDeleted(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::deleteTask *ui;
};

#endif // DELETETASK_H
