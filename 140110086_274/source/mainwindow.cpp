#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "remind.h"
#include "global.h"
#include "reminddialog.h"
#include <QTextCharFormat>
#include <QInputDialog>
#include <QDate>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer= new QTimer (this);
    connect( ui->calendarWidget, SIGNAL( activated( const QDate & )),
             this, SLOT( remind( const QDate & )));
    connect (timer, SIGNAL(timeout()), this, SLOT( checkTime()));
    timer->start();     //runs a timeer
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::remind( const QDate &date )//on clicking on a date this is activated
{
    dateselected= date;

    Remind mdialog;//it shoots up a dialog "remind"
    mdialog.setModal(true);
    mdialog.exec();


    if (!mdialog.isActiveWindow())//when dialog is closed
    {int flag=0;

        for(int i=0;i<=serial_no;i++)
        {    if (reminderdate[i]==date)
                flag=1;
        }//if there has been a reminder stored on the date clicled

        if (flag==1)
        {    QBrush brush;
            brush.setColor( Qt::green );
            QTextCharFormat cf = ui->calendarWidget->dateTextFormat( date );
            cf.setBackground( brush );
            ui->calendarWidget->setDateTextFormat( date, cf );
        }//the respective cell is coloured green
        else
        {     QBrush brush;
            brush.setColor( Qt::white );
            QTextCharFormat cf = ui->calendarWidget->dateTextFormat( date );
            cf.setBackground( brush );
            ui->calendarWidget->setDateTextFormat( date, cf );
        }//else it remains white

        if (!mdialog.isActiveWindow())//when dialog is closed
        {int flag=0;
            for(int i=0;i<=serial_no;i++)
            {    if (reminderdate[i]==dateselected)
                    flag=1;
            }//if reminder is stored on a date other than that clicked ( dateselected is a global that takes the value of that date)

            if (flag==1)
            {    QBrush brush;
                brush.setColor( Qt::green );
                QTextCharFormat cf = ui->calendarWidget->dateTextFormat( dateselected );
                cf.setBackground( brush );
                ui->calendarWidget->setDateTextFormat( dateselected, cf );
            }//that cell is coloured green
            else
            {     QBrush brush;
                brush.setColor( Qt::white );
                QTextCharFormat cf = ui->calendarWidget->dateTextFormat( dateselected );
                cf.setBackground( brush );
                ui->calendarWidget->setDateTextFormat( dateselected, cf );
            }//else it is coloured white
        }
    }

}

void MainWindow::checkTime()//this checks the current time and compares it with the time of the closest reminder

{QDate date= QDate::currentDate();
    QTime time= QTime::currentTime();

    if (serial_no>0)//error check
    {
        if (time == remindertime[1])//if time is same as reminder's a dialog reminding user  shoots up
        {
            RemindDialog rdialog;
            rdialog.setModal(true);
            rdialog.exec();



    if (!rdialog.isActiveWindow())//when dialog is closed
    {int flag=0;

        for(int i=0;i<=serial_no;i++)
        {    if (reminderdate[i]==date)
                flag=1;
        }//checks if reminder is present on that date

        if (flag==1)//colours green
        {    QBrush brush;
            brush.setColor( Qt::green );
            QTextCharFormat cf = ui->calendarWidget->dateTextFormat( date );
            cf.setBackground( brush );
            ui->calendarWidget->setDateTextFormat( date, cf );
        }
        else//colours white
        {     QBrush brush;
            brush.setColor( Qt::white );
            QTextCharFormat cf = ui->calendarWidget->dateTextFormat( date );
            cf.setBackground( brush );
            ui->calendarWidget->setDateTextFormat( date, cf );
        }

        if (!rdialog.isActiveWindow())//when dialog is closed
        {int flag=0;
            for(int i=0;i<=serial_no;i++)
            {    if (reminderdate[i]==dateselected)
                    flag=1;
            }//checks if snoozed to a different date, saved as 'dateselected'

            if (flag==1)
            {    QBrush brush;
                brush.setColor( Qt::green );
                QTextCharFormat cf = ui->calendarWidget->dateTextFormat( dateselected );
                cf.setBackground( brush );
                ui->calendarWidget->setDateTextFormat( dateselected, cf );
            }
            else
            {     QBrush brush;
                brush.setColor( Qt::white );
                QTextCharFormat cf = ui->calendarWidget->dateTextFormat( dateselected );
                cf.setBackground( brush );
                ui->calendarWidget->setDateTextFormat( dateselected, cf );
            }
        }
    }
}}}
