#ifndef GLOBAL
#define GLOBAL
#include <QString>
#include <QDate>
#include <QTime>

extern QDate reminderdate[1000];
extern QTime remindertime[1000];
extern QString content [1000];
extern int serial_no;
extern int s_no_displayed;
extern QDate dateselected;
extern int repeat[1000];
extern int checktime;

#endif // GLOBAL

