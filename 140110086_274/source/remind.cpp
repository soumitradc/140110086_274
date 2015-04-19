#include "remind.h"
#include "ui_remind.h"
#include "mydialog.h"
#include "global.h"
#include "editreminder.h"
#include "confirmdelete.h"

//gets opened when a person clicks on a particluar date on calendar


Remind::Remind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Remind)
{
    ui->setupUi(this);
    search();
}

Remind::~Remind()
{
    delete ui;
}

void Remind::on_addReminder_clicked()//if add reminder button clicked shoots up a dialog to add a reminder
{
    MyDialog mdialog;
    mdialog.setModal(true);
    mdialog.exec();

    if (!mdialog.isActiveWindow())
    {
        search();
    }
}

void Remind::search()//searches the dateclicked on if there's a reminder
{
    for( s_no_displayed=1;s_no_displayed<=serial_no;s_no_displayed++)
    {    if (reminderdate[s_no_displayed]==dateselected)
        {
            display(s_no_displayed);//if yes it displayed the first reminder of that date
            return;
        }
    }
}

void Remind::display(int s_no_displayed)
{ ui->date->setText(dateselected.toString());
    if (reminderdate[s_no_displayed]!=dateselected)
    {   ui->remtime->setText("NO");
        ui->remcontent->setText("REMINDERS");
    }//if date of the reminder at that serial number in array not same as date clicked, doesnt display
    else
    {
        ui->remtime->setText(remindertime[s_no_displayed].toString());
        ui->remcontent->setText(content[s_no_displayed]);
    }//displays the reminder time and content
}
void Remind::on_nextReminder_clicked()
{
    s_no_displayed++;
    if (serial_no!=0)
    display(s_no_displayed);
    /*it displays the reminder in next serial number.
     *since it's sorted it can be next in same date or next date.
     * if next date doesnt get displayed (see display()) */
    else {
        ui->remtime->setText("NO");
    ui->remcontent->setText("REMINDER");
}}


void Remind::on_previousReminder_clicked()
{
    if (s_no_displayed>=1)//checks boundaryto prevent errors
        s_no_displayed--;
    if(s_no_displayed==0)
    {
        ui->remtime->setText("PRESS NEXT");
        ui->remcontent->setText("NO MORE REMINDERS");
    }
    if (s_no_displayed!=0)
        display(s_no_displayed);

}

void Remind::on_editReminder_clicked()
{if ((serial_no!=0) && (reminderdate[s_no_displayed]==dateselected))//error check
    {EditReminder edialog;//opens updialog to edit the reminder thats been displayed on screen
        edialog.setModal(true);
        edialog.exec();

        if (!edialog.isActiveWindow())//when edit reminder dialog is closed closes this dialog
            this->close();
    }
}
void Remind::on_deleteReminder_clicked()
{ confirmdelete mdialog;
    mdialog.setModal(true);
    mdialog.exec();
this->close();
}


void Remind::numberOfReminders()
{ int count=0;
    for( s_no_displayed=1;s_no_displayed<=serial_no;s_no_displayed++)
    {    if (reminderdate[s_no_displayed]==dateselected)
        {
            count++;
        }
    }

    QString s = QString::number(count);
    ui->noOfReminders->setText(s);
}
