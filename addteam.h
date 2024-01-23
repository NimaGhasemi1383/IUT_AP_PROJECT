#ifndef ADDTEAM_H
#define ADDTEAM_H

#include <QWidget>

namespace Ui {
class AddTeam;
}

class AddTeam : public QWidget
{
    Q_OBJECT

public:
    explicit AddTeam(QWidget *parent = nullptr);
    ~AddTeam();

signals:
    void ItemAdded(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::AddTeam *ui;
};

#endif // ADDTEAM_H
