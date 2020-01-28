#ifndef MANAGERUSER_H
#define MANAGERUSER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class ManagerUser
{
    int idOfLoggedInUser;
    vector<User> users;
    FileWithUsers fileWithUsers;

    User enterNewUserDetails();
    int getNewUserId();
    bool checkIfThereIsLogin(string);

public:
    ManagerUser(string FILENAMEWITHUSERS) : fileWithUsers(FILENAMEWITHUSERS) {
        idOfLoggedInUser = 0;
        users = fileWithUsers.getUsersFromFile();
    };
    void userRegistration();
    void viewAllUsers();
    int userLogin();
    void changingUserPasword();
    void userLogout();
    int getIdOfLoggedInUser();
    void setIdOfLoggedInUser(int noweId);
    bool checkIfUserIsLoggedIn();
};

#endif
