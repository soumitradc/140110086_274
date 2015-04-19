#include "confirmdelete.h"
#include "ui_confirmdelete.h"
#include "global.h"
#include "remind.h"
#include "ui_remind.h"
#include "mydialog.h"
#include "global.h"
#include "editreminder.h"

confirmdelete::confirmdelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmdelete)
{
    ui->setupUi(this);
}

confirmdelete::~confirmdelete()
{
    delete ui;
}

void confirmdelete::on_pushButton_clicked()
{

        {  QDate swap; QString swapstring; QTime swaptime; int  swaprepeat;

            swap=reminderdate[serial_no];
            swapstring=content[serial_no];
            swaptime=remindertime[serial_no];
            swaprepeat=repeat[serial_no];
            reminderdate[serial_no]=reminderdate[s_no_displayed];
            remindertime[serial_no]=remindertime[s_no_displayed];
            content[serial_no]=content[s_no_displayed];
            repeat[serial_no]=repeat[s_no_displayed];
            reminderdate[s_no_displayed]=swap;
            remindertime[s_no_displayed]=swaptime;
            content[s_no_displayed]=swapstring;
            repeat[s_no_displayed]=swaprepeat;
            serial_no--;


            /* swaps the reminder with that at last stored serial_no
     then reduces the serial_no so that this reminder is not read
     and then sorts
     on adding a new reminder the one a
     */

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

        }//sorts
this->close();}


void confirmdelete::on_pushButton_2_clicked()
{
    this->close();
}
