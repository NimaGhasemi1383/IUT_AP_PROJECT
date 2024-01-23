#ifndef PROJECTUI_H
#define PROJECTUI_H

#include <QWidget>

namespace Ui {
class ProjectUi;
}

class ProjectUi : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectUi(QWidget *parent = nullptr);
    ~ProjectUi();

private:
    Ui::ProjectUi *ui;
};

#endif // PROJECTUI_H
