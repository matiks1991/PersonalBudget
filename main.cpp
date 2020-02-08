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
                personalBudget.balanceFromCurrentMonth();
                break;
            case '4':
                personalBudget.balanceFromPreviousMonth();
                break;
            case '5':
                personalBudget.balanceFromSelectedPeriod();
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
//    personalBudget.viewAllUsers();

    return 0;
}

#include "FileWithBudgetPositions.h"

int fmain()
{
    vector<BudgetPosition> budgetPositions;
    FileWithBudgetPositions fileWithBudgetPositions("incomes.xml");

    //BudgetPosition budgetPosition(1,1,"2011-02-24", "Przerabalem siano", 127.12);

//    fileWithBudgetPositions.addBudgetPositions(budgetPosition);

    budgetPositions = fileWithBudgetPositions.getBudgetPositionsOfLoggedInUserFromFile(2);

//    for(vector<BudgetPosition>::iterator itr = budgetPositions.begin(); itr!=budgetPositions.end(); itr++)
//    {
//        cout << itr -> getId() << endl;
//        cout << itr -> getUserId() << endl;
//        cout << itr -> getDate() << endl;
//        cout << itr -> getItem() << endl;
//        cout << itr -> getAmount() << endl << endl;
//    }

    cout << "ID ostatnie: " << endl << fileWithBudgetPositions.getLastBudgetPositionIdFromFile() << endl;

    return 0;
}

#include "OperationsOnDates.h"

int dmain()
{

    cout << "Data: " << endl << OperationsOnDates::getSystemDate() << endl;

    return 0;
}
