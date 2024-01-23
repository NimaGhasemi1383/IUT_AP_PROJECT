#ifndef OUTORG_H
#define OUTORG_H

#include <QWidget>

namespace Ui {
class outorg;
}

class outorg : public QWidget
{
    Q_OBJECT

public:
    explicit outorg(QWidget *parent = nullptr);
    ~outorg();

signals:
    void ItemAdded2(QString item);

private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::outorg *ui;
};

#endif // OUTORG_H
