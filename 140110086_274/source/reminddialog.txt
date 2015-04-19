#ifndef REMINDDIALOG_H
#define REMINDDIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QDebug>
namespace Ui {
class RemindDialog;
}

class RemindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemindDialog(QWidget *parent = 0);
    ~RemindDialog();\
    void displaydatetimecontent();
void snooze();
void closedeleteall();
void sort();

private slots:
    void on_close_clicked();

    void on_snoozeButton_clicked();

    void on_closeDelete_clicked();

    void on_mute_clicked();

    void on_closeDeleteAll_clicked();

private:
    Ui::RemindDialog *ui;
    QMediaPlayer *music;

};

#endif // REMINDDIALOG_H
