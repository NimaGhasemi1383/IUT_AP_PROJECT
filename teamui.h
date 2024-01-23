#ifndef TEAMUI_H
#define TEAMUI_H

#include <QWidget>

namespace Ui {
class teamUi;
}

class teamUi : public QWidget
{
    Q_OBJECT

public:
    explicit teamUi(QWidget *parent = nullptr);
    ~teamUi();

private:
    Ui::teamUi *ui;
};

#endif // TEAMUI_H
