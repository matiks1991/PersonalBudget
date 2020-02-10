#ifndef MANAGERBUDGET_H
#define MANAGERBUDGET_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "BudgetPosition.h"
#include "FileWithBudgetPositions.h"
#include "OperationsOnDates.h"

using namespace std;

class ManagerBudget
{
    const int ID_OF_LOGGED_IN_USER;
    vector<BudgetPosition> incomes;
    vector<BudgetPosition> expenses;
    FileWithBudgetPositions fileWithIncomes;
    FileWithBudgetPositions fileWithExpenses;

    BudgetPosition enterDataForNewPosition(int lastId);
    int dateInputMenu();
    double amountInputMenu();
    string changeCommaToDot(string amountString);
    void viewBalance(int startingDate, int endDate);


//    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();
    void podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();
//    void zaktualizujDaneWybranegoAdresata(Adresat adresat);+

public:
    ManagerBudget(string FILENAMEWITHINCOMES, string FILENAMEWITHEXPENSES, int idOfLoggedInUser)
        : fileWithIncomes(FILENAMEWITHINCOMES), fileWithExpenses(FILENAMEWITHEXPENSES), ID_OF_LOGGED_IN_USER(idOfLoggedInUser)
    {
        incomes = fileWithIncomes.getBudgetPositionsOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
        expenses = fileWithExpenses.getBudgetPositionsOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
    };
    void addIncome();
    void addExpense();
    void viewBalanceForCurrentMonth();
    void viewBalanceForPreviousMonth();
    void viewBalanceForSelectedPeriod();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void usunAdresata();
    void edytujAdresata();
};

#endif
