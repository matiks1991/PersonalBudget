#include "OperationsOnDates.h"

using namespace std;

int OperationsOnDates::enterDate()
{
    string enteredDateString;
    int enteredDateIntiger = 0;

    do
    {
        cout << "Wprowadz date w formacie rrrr-mm-dd: " << endl;
        enteredDateString = AuxiliaryMethods::loadLine();
    }while(!checkDateIsCorrect(enteredDateString));

    enteredDateIntiger = convertDateStringToInt(enteredDateString);

    return enteredDateIntiger;
}

bool OperationsOnDates::checkDateIsCorrect(string dateString)
{
    string singleData;
    int dateInt;
    int numberOfSingleData = 1;
    tm dateTm;

    dateString += '-';
    for (int characterPosition = 0; characterPosition < dateString.size(); characterPosition++)
    {
        if (dateString[characterPosition] != '-')
        {
            singleData += dateString[characterPosition];
        }
        else
        {
            switch(numberOfSingleData)
            {
            case 1:
                dateTm.tm_year = atoi(singleData.c_str()) - 1900;
                break;
            case 2:
                dateTm.tm_mon = atoi(singleData.c_str()) - 1;
                break;
            case 3:
                dateTm.tm_mday = atoi(singleData.c_str());
                break;
            }
            singleData = "";
            numberOfSingleData++;
        }
    }

    dateInt = (dateTm.tm_year+1900) * 10000 + (dateTm.tm_mon+1) * 100 + dateTm.tm_mday;

    if(getSystemDate()<dateInt || dateTm.tm_year<100 || dateTm.tm_mon>11 || dateTm.tm_mday>countHowManyDaysInMonth(dateTm))
        return false;

    return true;
}

int OperationsOnDates::convertDateStringToInt(string dateString)
{
    string singleData = "";
    int numberOfSingleData = 1;
    int dateInt = 0;
    tm dateTm;

    dateString += '-';
    for (int characterPosition = 0; characterPosition < dateString.size(); characterPosition++)
    {
        if (dateString[characterPosition] != '-')
        {
            singleData += dateString[characterPosition];
        }
        else
        {
            switch(numberOfSingleData)
            {
            case 1:
                dateTm.tm_year = atoi(singleData.c_str()) - 1900;
                break;
            case 2:
                dateTm.tm_mon = atoi(singleData.c_str()) - 1;
                break;
            case 3:
                dateTm.tm_mday = atoi(singleData.c_str());
                break;
            }
            singleData = "";
            numberOfSingleData++;
        }
    }

    dateInt = convertDateTmToInt(dateTm);

    return dateInt;
}

int OperationsOnDates::getSystemDate()
{
    time_t currentDate;
    tm currentDateTm;
    int currentDateIntiger = 0;

    time(&currentDate);
    currentDateTm = *localtime(&currentDate);

    currentDateIntiger = convertDateTmToInt(currentDateTm);

    return currentDateIntiger;
}

int OperationsOnDates::convertDateTmToInt(tm dateTm)
{
    int dateIntiger = 0;
    string dateString = "";

    dateString += AuxiliaryMethods::conversionIntToString(dateTm.tm_year + 1900);
    if(dateTm.tm_mon < 9)
        dateString += '0';
    dateString += AuxiliaryMethods::conversionIntToString(dateTm.tm_mon + 1);
    if(dateTm.tm_mday < 10)
        dateString += '0';
    dateString += AuxiliaryMethods::conversionIntToString(dateTm.tm_mday);

    dateIntiger = AuxiliaryMethods::conversionStringToInt(dateString);

    return dateIntiger;
}

string OperationsOnDates::convertDateIntToString(int dateInt)
{
    string dateString = "", dateStringWithoutDash = "";

    dateStringWithoutDash = AuxiliaryMethods::conversionIntToString(dateInt);

    for(int characterPosition = 0; characterPosition < dateStringWithoutDash.length(); characterPosition++)
    {
        dateString += dateStringWithoutDash[characterPosition];

        if(characterPosition==3 || characterPosition==5)
        {
            dateString += "-";
        }
    }

    return dateString;
}

bool OperationsOnDates::isItLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int OperationsOnDates::countHowManyDaysInMonth(tm dateTm)
{
    int month = dateTm.tm_mon+1;
    int year = dateTm.tm_year+1900;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 02)
    {
        if (isItLeapYear(year))
                return 29;
        else
                return 28;
    }
    else
    return 31;
}

bool OperationsOnDates::compareDates(BudgetPosition &firstDate, BudgetPosition &secondDate)
{
    return (firstDate.getDate()<secondDate.getDate());
}

vector<BudgetPosition> OperationsOnDates::sortingItemsByDate(vector<BudgetPosition> budgetPositions)
{
    sort(budgetPositions.begin(), budgetPositions.end(), compareDates);

    return budgetPositions;
}

int OperationsOnDates::getBeginningOfCurrentMonth()
{
    return getSystemDate() / 100 * 100 + 1;
}

int OperationsOnDates::getBeginningOfPreviousMonth()
{
    int beginningOfMonth;

    if(checkIfItIsJanuary())
    {
        beginningOfMonth = (getSystemDate()/10000-1)*10000+1201;
    }
    else
    {
        beginningOfMonth = (getSystemDate()/100-1)*100+1;
    }

    return beginningOfMonth;
}

bool OperationsOnDates::checkIfItIsJanuary()
{
    return (getSystemDate()%10000) < 132;
}

int OperationsOnDates::getEndOfPreviousMonth()
{
    int previousMonth;
    int endOfMonth;
    if(checkIfItIsJanuary())
    {
        endOfMonth = getSystemDate() / 10000 - 1 + 1231;
    }
    else
    {
        previousMonth = (getSystemDate()/100-1) * 100;
        endOfMonth = previousMonth + countHowManyDaysInMonth(convertDateIntToTm(previousMonth));
    }

    return endOfMonth;
}

tm OperationsOnDates::convertDateIntToTm(int dateInt)
{
    tm dateTm;

    dateTm.tm_year = dateInt / 10000 - 1900;
    dateTm.tm_mon = dateInt / 100 % 100 - 1;
    dateTm.tm_mday = dateInt % 100;

    return dateTm;
}
