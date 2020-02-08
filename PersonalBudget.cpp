#include "PersonalBudget.h"

char PersonalBudget::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "$--------------------------$" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "$--------------------------$" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char PersonalBudget::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "$--------------------------------$" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "$--------------------------------$" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "$--------------------------------$" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

void PersonalBudget::userRegistration()
{
    managerUser.userRegistration();
}

void PersonalBudget::viewAllUsers()
{
    managerUser.viewAllUsers();
}

void PersonalBudget::userLogin()
{
    managerUser.userLogin();
    if(managerUser.checkIfUserIsLoggedIn())
    {
        managerBudget = new ManagerBudget(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPANSES, managerUser.getIdOfLoggedInUser());
    }
}

void PersonalBudget::changingUserPasword()
{
    managerUser.changingUserPasword();
}

void PersonalBudget::userLogout()
{
    managerUser.userLogout();
    delete managerBudget;
    managerBudget = NULL;
}

void PersonalBudget::addIncome()
{
    if(managerUser.checkIfUserIsLoggedIn())
    {
        managerBudget->addIncome();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense()
{
    if(managerUser.checkIfUserIsLoggedIn())
    {
        managerBudget->addExpense();
    }
    else
    {
        cout << "Aby dodac przychod, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::balanceFromCurrentMonth()
{
    if(managerUser.checkIfUserIsLoggedIn())
    {
//        managerBudget->balanceFromCurrentMonth();
    }
    else
    {
        cout << "Aby wyswietlic bilans za ostatni miesiac, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::balanceFromPreviousMonth()
{
    if(managerUser.checkIfUserIsLoggedIn())
    {
//        managerBudget->balanceFromPreviousMonth();
    }
    else
    {
        cout << "Aby wyswietlic bilans za poprzedni miesiac, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::balanceFromSelectedPeriod()
{
    if(managerUser.checkIfUserIsLoggedIn())
    {
//        managerBudget->balanceFromSelectedPeriod();
    }
    else
    {
        cout << "Aby wyswietlic bilans za wybrany okres, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

int PersonalBudget::getIdOfLoggedInUser()
{
    managerUser.getIdOfLoggedInUser();
}

