#include "reminddialog.h"
#include "ui_reminddialog.h"
#include <QString>
#include <QDateTime>
#include <QTimer>
#include "global.h"
#include <QMediaPlayer>

//Gets popped up when reminder time is reached

RemindDialog::RemindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemindDialog)
{
    ui->setupUi(this);
    music= new QMediaPlayer(this);
    music->setMedia(QUrl("qrc:sounds/ringer.mp3"));
    music->setVolume(100);
    music->play();//Plays Ringer tone on pop up( reminder reached)

    displaydatetimecontent();
}

RemindDialog::~RemindDialog()
{
    delete ui;
}

void RemindDialog:: displaydatetimecontent()//Displays date time and content of the reminder
{
    QDate date= QDate::currentDate();
    ui->reminddate->setText(date.toString());
    ui->dateEdit->setDate(date);
    QTime time= QTime::currentTime();
    ui->remindtime->setText(time.toString());
    ui->timeEdit->setTime(time);
    ui->remindcontent->setText(content[checktime]);

}

void RemindDialog::on_close_clicked()//CLOSE AND RETAIN. RRetains this reminer, and saves a new one if repeat
{QDate date= QDate::currentDate();
    
    if (repeat[checktime]==1)
    {serial_no++;
        dateselected=date.addDays(1);
        reminderdate[serial_no]=dateselected;
        remindertime[serial_no]=remindertime[checktime];
        content[serial_no]=content[checktime];
        repeat[serial_no]=repeat[checktime];
        sort();
    }//IF 'DAILY REPEAT' - save a reminder next day  
    if (repeat[checktime]==2)
    {serial_no++;
        dateselected=date.addDays(7);
        reminderdate[serial_no]=dateselected;
        remindertime[serial_no]=remindertime[checktime];
        content[serial_no]=content[checktime];
        repeat[serial_no]=repeat[checktime];
        sort();
    }//IF WEEKLY REPEAT, save next week
    if (repeat[checktime]==3)
    {serial_no++;
        dateselected=date.addMonths(checktime);
        reminderdate[serial_no]=dateselected;
        remindertime[serial_no]=remindertime[checktime];
        content[serial_no]=content[checktime];
        repeat[serial_no]=repeat[checktime];
        sort();
    }//IF MONTHLY SAVES NEXT MONTH
    if (repeat[checktime]==4)
    {serial_no++;
        dateselected=date.addYears(checktime);
        reminderdate[serial_no]=dateselected;
        remindertime[serial_no]=remindertime[checktime];
        content[serial_no]=content[checktime];
        repeat[serial_no]=repeat[checktime];
        sort();
    }//IF YEARLYSAVES NEXT YEAR
    music->stop();
    this->close();
}

void RemindDialog::on_snoozeButton_clicked()
{
    snooze();
    music->stop();
    this->close();
}

void RemindDialog:: snooze()//Takes in nexw date/time and replaces the present reminder entres with that
{
    reminderdate[checktime]=ui->dateEdit->date();
    dateselected=ui->dateEdit->date();
    remindertime[checktime]=ui->timeEdit->time();
    sort();

}



void RemindDialog::on_closeDelete_clicked()//REMOVES this reminder but saves repeat entry
{   QDate date= QDate::currentDate();
    QDate swap; QString swapstring; QTime swaptime; int  swaprepeat;
    if (repeat[checktime]==0)
        closedeleteall();
    if (repeat[checktime]==1)
    {
        dateselected=date.addDays(checktime);
        reminderdate[checktime]=dateselected;
        sort();
    }//if daily,replaces date
    if (repeat[checktime]==2)
    {
        dateselected=reminderdate[checktime].addDays(7);
        reminderdate[checktime]=dateselected;
        sort();
    }//if weekly, adds week
    if (repeat[checktime]==3)
    {
        dateselected=reminderdate[checktime].addMonths(checktime);
        reminderdate[checktime]=dateselected;
        sort();
    }//if monthly, adds month
    if (repeat[checktime]==4)
    {
        dateselected=reminderdate[checktime].addYears(checktime);
        reminderdate[checktime]=dateselected;
        sort();
    }//if yearly, adds year
    music->stop();
    this->close();
}

void RemindDialog::on_mute_clicked()
{
    music->stop();
}
void RemindDialog::closedeleteall()//REMOVES REMINDER AND DOESNT STORE ITS REPEAT
{  QDate swap; QString swapstring; QTime swaptime; int  swaprepeat;

    swap=reminderdate[serial_no];
    swapstring=content[serial_no];
    swaptime=remindertime[serial_no];
    swaprepeat=repeat[serial_no];
    reminderdate[serial_no]=reminderdate[checktime];
    remindertime[serial_no]=remindertime[checktime];
    content[serial_no]=content[checktime];
    repeat[serial_no]=repeat[checktime];
    reminderdate[checktime]=swap;
    remindertime[checktime]=swaptime;
    content[checktime]=swapstring;
    repeat[checktime]=swaprepeat;
    serial_no--;
   sort();

}
void RemindDialog::on_closeDeleteAll_clicked()
{
    closedeleteall();
}
void RemindDialog::sort()//Sort Function
{
    QDate swap; QString swapstring; QTime swaptime; int  swaprepeat;
    for(int c=1;c<=serial_no;c++)
    {
        for(int d=c;d<=serial_no;d++)
        {
            if ((reminderdate[c]>reminderdate[d])||((reminderdate[c]==reminderdate[d])&&(remindertime[c]>remindertime[d])))
            {
                swap=reminderdate[c];
                swapstring=content[c];
                swaptime=remindertime[c];
                swaprepeat=repeat[c];
                reminderdate[c]=reminderdate[d];
                remindertime[c]=remindertime[d];
                content[c]=content[d];
                repeat[c]=repeat[d];
                reminderdate[d]=swap;
                remindertime[d]=swaptime;
                content[d]=swapstring;
                repeat[d]=swaprepeat;
            }
        }
    }
}
