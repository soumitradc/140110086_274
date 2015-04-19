#ifndef REMIND_H
#define REMIND_H

#include <QDialog>
namespace Ui {
class Remind;
}

class Remind : public QDialog
{
    Q_OBJECT

public:
    explicit Remind(QWidget *parent = 0);
    ~Remind();

private slots:
    void on_addReminder_clicked();
    void search();
    void numberOfReminders();
void display (int i);

void on_nextReminder_clicked();

void on_previousReminder_clicked();



void on_editReminder_clicked();

void on_deleteReminder_clicked();


private:
    Ui::Remind *ui;
};

#endif // REMIND_H
