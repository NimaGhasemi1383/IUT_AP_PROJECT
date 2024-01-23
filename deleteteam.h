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

private:
    Ui::DeleteTeam *ui;
};

#endif // DELETETEAM_H
