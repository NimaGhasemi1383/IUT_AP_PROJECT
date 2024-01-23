#ifndef EDITORG_H
#define EDITORG_H

#include <QWidget>

namespace Ui {
class EditOrg;
}

class EditOrg : public QWidget
{
    Q_OBJECT

public:
    explicit EditOrg(QWidget *parent = nullptr);
    ~EditOrg();
signals:
     void ItemAdded3(QString item1 , QString item2);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::EditOrg *ui;
};

#endif // EDITORG_H
