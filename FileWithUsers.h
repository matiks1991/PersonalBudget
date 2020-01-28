#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithUsers : public TextFile
{
    string replaceUserDataOnRopeWithDataSeparatedByVerticalDashes(User user);
    User getUserData(string oneUserDataSeparatedByVerticalDashes);

    public:
    FileWithUsers(string fileNameWithUsers): TextFile(fileNameWithUsers){};
    void addUserToFile(User user);
    vector <User> getUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif
