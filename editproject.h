#ifndef EDITPROJECT_H
#define EDITPROJECT_H

#include <QWidget>

namespace Ui {
class editProject;
}

class editProject : public QWidget
{
    Q_OBJECT

public:
    explicit editProject(QWidget *parent = nullptr);
    ~editProject();

signals:
    void ItemEdited(QString item1 , QString item2);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::editProject *ui;
};

#endif // EDITPROJECT_H
