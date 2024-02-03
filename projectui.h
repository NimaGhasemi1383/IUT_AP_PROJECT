#ifndef PROJECTUI_H
#define PROJECTUI_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class ProjectUi;
}

class ProjectUi : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectUi(QWidget *parent = nullptr);
    ~ProjectUi();

private slots:
    void on_pushButton_add_clicked();

    void AddItem(QString,QString,QString);

    void DeleteItem(QString);

    void on_pushButton_remove_clicked();

private:
    Ui::ProjectUi *ui;
    QVector<QPushButton*>task;
    int num = 0;
    int _move = 165;
    int _move2 = 90;
};

#endif // PROJECTUI_H
