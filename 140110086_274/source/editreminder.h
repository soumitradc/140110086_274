#ifndef EDITREMINDER_H
#define EDITREMINDER_H

#include <QDialog>

namespace Ui {
class EditReminder;
}

class EditReminder : public QDialog
{
    Q_OBJECT

public:
    explicit EditReminder(QWidget *parent = 0);
    ~EditReminder();
    void sort();

private slots:
    void on_save_clicked();

private:
    Ui::EditReminder *ui;
};

#endif // EDITREMINDER_H
