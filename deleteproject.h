#ifndef DELETEPROJECT_H
#define DELETEPROJECT_H

#include <QWidget>

namespace Ui {
class deleteProject;
}

class deleteProject : public QWidget
{
    Q_OBJECT

public:
    explicit deleteProject(QWidget *parent = nullptr);
    ~deleteProject();

signals:
    void ItemDeleted(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::deleteProject *ui;
};

#endif // DELETEPROJECT_H
