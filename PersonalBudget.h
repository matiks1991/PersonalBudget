#include <iostream>

#include "ManagerUser.h"
#include "ManagerBudget.h"

using namespace std;

class PersonalBudget
{
    ManagerUser managerUser;
    ManagerBudget *managerBudget;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPANSES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
    :managerUser(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPANSES(fileNameWithExpenses)
    {
        managerBudget = NULL;
    };
    ~PersonalBudget()
    {
        delete managerBudget;
        managerBudget = NULL;
    }

    void userRegistration();
    void viewAllUsers();
    void userLogin();
    void changingUserPasword();
    void userLogout();
    void addIncome();
    void addExpense();
    void viewBalanceForCurrentMonth();
    void viewBalanceForPreviousMonth();
    void viewBalanceForSelectedPeriod();
    int getIdOfLoggedInUser();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
};
