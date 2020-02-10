#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "User.h"
#include "TextFile.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers : public TextFile
{
    public:
    FileWithUsers(string fileNameWithUsers): TextFile(fileNameWithUsers){};
    void addUserToFile(User user);
    vector <User> getUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif
