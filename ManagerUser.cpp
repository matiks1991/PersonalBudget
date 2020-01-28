#include "ManagerUser.h"

using namespace std;

void ManagerUser::userRegistration()
{
    User user = enterNewUserDetails();

    users.push_back(user);

    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User ManagerUser::enterNewUserDetails()
{
    User user;

    user.setId(getNewUserId());

    do
    {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while(checkIfThereIsLogin(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    return user;
}

bool ManagerUser::checkIfThereIsLogin(string login)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

int ManagerUser::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

void ManagerUser::viewAllUsers()
{
    for(int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

int ManagerUser::userLogin()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> User::getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> User::getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    idOfLoggedInUser = itr -> User::getId();
                    return itr -> User::getId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            idOfLoggedInUser = 0;
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    idOfLoggedInUser = 0;
    return 0;
}

void ManagerUser::changingUserPasword()
{
    string newPassword = "";

    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> User::getId() == idOfLoggedInUser)
        {
            itr -> User::setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}

void ManagerUser::userLogout()
{
    idOfLoggedInUser = 0;
}

int ManagerUser::getIdOfLoggedInUser(){
    return idOfLoggedInUser;
}

void ManagerUser::setIdOfLoggedInUser(int newId){
    idOfLoggedInUser = newId;
}

bool ManagerUser::checkIfUserIsLoggedIn()
{
    if(idOfLoggedInUser > 0)
        return true;
    else
        return false;
}
