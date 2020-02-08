#ifndef OPERATIONSONDATES_H
#define OPERATIONSONDATES_H

#include <iostream>
#include <time.h>
#include <ctype.h>

#include "AuxiliaryMethods.h"

class OperationsOnDates
{
    static int convertDateTmToInt(tm dateTm);
    static bool checkDateIsCorrect(string date);
    static bool isItLeapYear(int year);
    static int howManyDaysInMonth(tm dateTm);

public:
    static int enterDate();
    static int getSystemDate();
    static int convertDateStringToInt(string dateString);
    static string convertDateIntToString(int dateInt);
};
#endif
