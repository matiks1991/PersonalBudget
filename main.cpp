#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while(true)
    {
        if(personalBudget.getIdOfLoggedInUser() == 0)
        {
            choice = personalBudget.chooseOptionFromMainMenu();

            switch(choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl;
                system("pause");
                break;
            }
        }else
        {
            choice = personalBudget.chooseOptionFromUserMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.viewBalanceForCurrentMonth();
                break;
            case '4':
                personalBudget.viewBalanceForPreviousMonth();
                break;
            case '5':
                personalBudget.viewBalanceForSelectedPeriod();
                break;
            case '6':
                personalBudget.changingUserPasword();
                break;
            case '7':
                personalBudget.userLogout();
                break;
            }
        }
    }

    return 0;
}
