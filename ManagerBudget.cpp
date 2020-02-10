#include "ManagerBudget.h"

using namespace std;

void ManagerBudget::addIncome()
{
    BudgetPosition income;
    int lastId;

    lastId = fileWithIncomes.getLastBudgetPositionIdFromFile();

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = enterDataForNewPosition(lastId);

    incomes.push_back(income);

    if(fileWithIncomes.addBudgetPositions(income))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

void ManagerBudget::addExpense()
{
    BudgetPosition expense;
    int lastId;

    lastId = fileWithExpenses.getLastBudgetPositionIdFromFile();

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = enterDataForNewPosition(lastId);

    expenses.push_back(expense);

    if(fileWithExpenses.addBudgetPositions(expense))
        cout << "Nowy wydatek zostal dodany" << endl;
    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku." << endl;
    system("pause");
}

BudgetPosition ManagerBudget::enterDataForNewPosition(int lastId)
{
    BudgetPosition budgetPosition;
    int date;
    double amount;

    budgetPosition.setId(lastId+1);
    budgetPosition.setUserId(ID_OF_LOGGED_IN_USER);

    date = dateInputMenu();
    budgetPosition.setDate(date);

    cout << "Podaj czego dotyczy: ";
    budgetPosition.setItem(AuxiliaryMethods::loadLine());

    amount = amountInputMenu();
    budgetPosition.setAmount(amount);

    return budgetPosition;
}

int ManagerBudget::dateInputMenu()
{
    char choice;
    int date = 0;

    do
    {
        cout << "Czy chcesz wprowadzic dzisiejsza date? (t/n) ";
        choice = AuxiliaryMethods::loadCharacter();
    }while(choice!='t' && choice!='n');

    if(choice == 'n')
    {
        date = OperationsOnDates::enterDate();
    }
    else
        date = OperationsOnDates::getSystemDate();

    return date;
}

double ManagerBudget::amountInputMenu()
{
    string amountString;
    double amountDouble;

    cout << "Wprowadz kwote: ";
    amountString = AuxiliaryMethods::loadLine();
    amountString = changeCommaToDot(amountString);
    amountDouble = atof(amountString.c_str());

    return amountDouble;
}

string ManagerBudget::changeCommaToDot(string amount)
{
    string amountWithDot = "";

    for(int characterPosition = 0; characterPosition < amount.size(); characterPosition++)
    {
        if(amount[characterPosition] == ',')
        {
            amountWithDot += ".";
            continue;
        }
            amountWithDot += amount[characterPosition];
    }
    return amountWithDot;
}

void ManagerBudget::viewBalance(int startingDate, int endDate)
{
    double totalIncome=0, totalExpense=0, endResult=0;

    incomes = OperationsOnDates::sortingItemsByDate(incomes);
    expenses = OperationsOnDates::sortingItemsByDate(expenses);

    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << endl << "----------------PRZYCHODY-----------------" << endl << endl;

    for(vector<BudgetPosition>::iterator itr=incomes.begin(); itr!=incomes.end(); itr++)
    {
        if(startingDate<=itr->getDate() &&  itr->getDate()<=endDate)
        {
            cout << OperationsOnDates::convertDateIntToString(itr->getDate()) << "  Kwota:" <<
            itr->getAmount()<< endl;
            cout << "            Pozycja:" << itr->getItem() << endl;
            totalIncome += itr->getAmount();
        }
    }

    cout << endl << "-----------------WYDATKI------------------" << endl << endl;

    for(vector<BudgetPosition>::iterator itr=expenses.begin(); itr!=expenses.end(); itr++)
    {
        if(startingDate<=itr->getDate() &&  itr->getDate()<=endDate)
        {
            cout << OperationsOnDates::convertDateIntToString(itr->getDate()) << "  Kwota:" <<
            itr->getAmount()<< endl;
            cout << "            Pozycja:" << itr->getItem() << endl;
            totalExpense += itr->getAmount();
        }
    }

    endResult = totalIncome - totalExpense;
    cout << endl << "---------------PODSUMOWANIE---------------" << endl;
    cout << endl << "Przychody: " << totalIncome << endl;
    cout << "Wydatki:   " << totalExpense << endl;
    cout << "Bilans:    " << endResult << endl;
}

void ManagerBudget::viewBalanceForCurrentMonth()
{
    system("cls");
    if(!incomes.empty() || !expenses.empty())
    {
        cout << "$~~~~~~~~BILANS Z AKTUALNEGO MIESIACA~~~~~~~~$" << endl;

        viewBalance(OperationsOnDates::getBeginningOfCurrentMonth(), OperationsOnDates::getSystemDate());
    }
    else
        cout << endl << "Nie wprowadzono zadnych pozycji w budzecie osobistym!" << endl << endl;

    system("pause");
}

void ManagerBudget::viewBalanceForPreviousMonth()
{
    system("cls");
    if(!incomes.empty() || !expenses.empty())
    {
        cout << "$~~~~~~~~BILANS Z POPRZEDNIEGO MIESIACA~~~~~~~~$" << endl;

        viewBalance(OperationsOnDates::getBeginningOfPreviousMonth(), OperationsOnDates::getEndOfPreviousMonth());
    }
    else
        cout << endl << "Nie wprowadzono zadnych pozycji w budzecie osobistym!" << endl << endl;

    system("pause");
}

void ManagerBudget::viewBalanceForSelectedPeriod()
{
    int startingDate = 0, endDate = 0;

    system("cls");
    if(!incomes.empty() || !expenses.empty())
    {
        cout << "Data poczatkowa" << endl << endl;
        startingDate = OperationsOnDates::enterDate();

        cout << endl << "Data koncowa" << endl << endl;
        endDate = OperationsOnDates::enterDate();

        system("cls");

        cout << "$~~~~~BILANS OD " << OperationsOnDates::convertDateIntToString(startingDate)
        << " DO " << OperationsOnDates::convertDateIntToString(endDate) << "~~~~~$" << endl;
        viewBalance(startingDate, endDate);
    }
    else
        cout << endl << "Nie wprowadzono zadnych pozycji w budzecie osobistym!" << endl << endl;

    system("pause");
}




