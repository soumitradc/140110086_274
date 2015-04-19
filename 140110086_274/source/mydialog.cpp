#include "mydialog.h"
#include "ui_mydialog.h"
#include <QString>
#include <QDateTime>
#include<QTimer>
#include "global.h"


MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    displayDate();
}

MyDialog::~MyDialog()
{
    delete ui;
}


void MyDialog::savedate()
{
    reminderdate[serial_no]=dateselected;
}

void MyDialog::savetime()
{
    remindertime[serial_no]=ui->timeEdit->time();

}
void MyDialog::savecontent()

{
    if (!ui->lineEdit->text().isEmpty())
        content[serial_no]= ui->lineEdit->text() ;
    else content[serial_no]= "Empty Reminder";

}
//repeat

void MyDialog::on_save_clicked()
{   serial_no++;
    savecontent();
    savedate();
    savetime();
    QTime time= QTime::currentTime();
    QDate date= QDate::currentDate();
    if (ui->none->isChecked())
        repeat[serial_no]=0;//none
    if (ui->daily->isChecked())
        repeat[serial_no]=1;//daily
    if(ui->weekly->isChecked())
        repeat[serial_no]=2;//weekly
    if (ui->monthly->isChecked())
        repeat[serial_no]=3;//monthly
    if (ui->yearly->isChecked())
        repeat[serial_no]=4;//yearly
    sort();

    this->close();
}

void MyDialog::displayDate()
{
    QDate date= dateselected;
    ui->dateText->setText(date.toString());
}

void MyDialog::sort()
{
    QDate swap; QString swapstring; QTime swaptime;int swaprepeat;
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
