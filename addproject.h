#ifndef ADDPROJECT_H
#define ADDPROJECT_H

#include <QWidget>

namespace Ui {
class addProject;
}

class addProject : public QWidget
{
    Q_OBJECT

public:
    explicit addProject(QWidget *parent = nullptr);
    ~addProject();

signals:
    void ItemAdded(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::addProject *ui;
};

#endif // ADDPROJECT_H
