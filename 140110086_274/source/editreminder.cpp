#include "editreminder.h"
#include "ui_editreminder.h"
#include "global.h"

EditReminder::EditReminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditReminder)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(reminderdate[s_no_displayed]);
    ui->timeEdit->setTime(remindertime[s_no_displayed]);
    ui->lineEdit->setText(content[s_no_displayed]);
}

EditReminder::~EditReminder()
{
    delete ui;
}

void EditReminder::on_save_clicked()
{
    reminderdate[s_no_displayed]=ui->dateEdit->date();
    dateselected=ui->dateEdit->date();
    remindertime[s_no_displayed]=ui->timeEdit->time();
    if (!ui->lineEdit->text().isEmpty())
         content[s_no_displayed]= ui->lineEdit->text() ;
    else content[s_no_displayed]= "Empty Reminder";
    sort();

    this->close();
}

void EditReminder::sort()
{ QDate swap; QString swapstring; QTime swaptime;
    for(int c=1;c<=serial_no;c++)
      {
        for(int d=c;d<=serial_no;d++)
        {
          if ((reminderdate[c]>reminderdate[d])||((reminderdate[c]==reminderdate[d])&&(remindertime[c]>remindertime[d])))
          {
            swap=reminderdate[c];
            swapstring=content[c];
            swaptime=remindertime[c];
            reminderdate[c]=reminderdate[d];
            remindertime[c]=remindertime[d];
            content[c]=content[d];
            reminderdate[d]=swap;
            remindertime[d]=swaptime;
            content[d]=swapstring;
          }
        }
      }
}
