#ifndef DELETETEAM_H
#define DELETETEAM_H

#include <QWidget>

namespace Ui {
class DeleteTeam;
}

class DeleteTeam : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteTeam(QWidget *parent = nullptr);
    ~DeleteTeam();

signals:
    void ItemDeleted(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::DeleteTeam *ui;
};

#endif // DELETETEAM_H
