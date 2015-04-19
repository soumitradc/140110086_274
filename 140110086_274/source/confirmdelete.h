#ifndef CONFIRMDELETE_H
#define CONFIRMDELETE_H

#include <QDialog>

namespace Ui {
class confirmdelete;
}

class confirmdelete : public QDialog
{
    Q_OBJECT

public:
    explicit confirmdelete(QWidget *parent = 0);
    ~confirmdelete();

private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::confirmdelete *ui;
};

#endif // CONFIRMDELETE_H
