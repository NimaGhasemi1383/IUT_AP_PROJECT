#ifndef EDITTEAM_H
#define EDITTEAM_H

#include <QWidget>

namespace Ui {
class EditTeam;
}

class EditTeam : public QWidget
{
    Q_OBJECT

public:
    explicit EditTeam(QWidget *parent = nullptr);
    ~EditTeam();

signals:
    void ItemEdited(QString item1 , QString item2);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::EditTeam *ui;
};

#endif // EDITTEAM_H
