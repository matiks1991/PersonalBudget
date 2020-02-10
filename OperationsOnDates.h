#ifndef OPERATIONSONDATES_H
#define OPERATIONSONDATES_H

#include <iostream>
#include <time.h>
#include <ctype.h>
#include <algorithm>
#include <vector>

#include "AuxiliaryMethods.h"
#include "BudgetPosition.h"

class OperationsOnDates
{
    static int convertDateTmToInt(tm dateTm);
    static bool checkDateIsCorrect(string date);
    static bool isItLeapYear(int year);
    static int countHowManyDaysInMonth(tm dateTm);
    static bool compareDates(BudgetPosition &first, BudgetPosition &second);

public:
    static int enterDate();
    static int getSystemDate();
    static int convertDateStringToInt(string dateString);
    static string convertDateIntToString(int dateInt);
    static vector<BudgetPosition> sortingItemsByDate(vector<BudgetPosition> budgetPositions);
};
#endif
