#include "FileWithUsers.h"

using namespace std;

void FileWithUsers::addUserToFile(User user)
{
    string lineWithUserData = "";
    fstream textFile;

    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = replaceUserDataOnRopeWithDataSeparatedByVerticalDashes(user);

        if (checkIfFileIsEmpty() == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << getFileName() << " i zapisac w nim danych." << endl;
    textFile.close();
}

string FileWithUsers::replaceUserDataOnRopeWithDataSeparatedByVerticalDashes(User user)
{
    string lineWithUserData = "";

    lineWithUserData += AuxiliaryMethods::conversionIntToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

vector <User> FileWithUsers::getUsersFromFile()
{
    string oneUserDataSeparatedByVerticalDashes = "";
    User user;
    vector <User> users;
    fstream textFile;

    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, oneUserDataSeparatedByVerticalDashes))
        {
            user = getUserData(oneUserDataSeparatedByVerticalDashes);
            users.push_back(user);
        }
    }
    textFile.close();

    return users;
}

User FileWithUsers::getUserData(string oneUserDataSeparatedByVerticalDashes)
{
    User user;
    string singleUserData = "";
    int singleUserDataNumber = 1;

    for (int characterPosition = 0; characterPosition < oneUserDataSeparatedByVerticalDashes.length(); characterPosition++)
    {
        if (oneUserDataSeparatedByVerticalDashes[characterPosition] != '|')
        {
            singleUserData += oneUserDataSeparatedByVerticalDashes[characterPosition];
        }
        else
        {
            switch(singleUserDataNumber)
            {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            singleUserDataNumber++;
        }
    }
    return user;
}

void FileWithUsers::saveAllUsersToFile(vector <User> &users)
{
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(getFileName().c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            lineWithUserData = replaceUserDataOnRopeWithDataSeparatedByVerticalDashes(*itr);

            if (itr == itrEnd)
            {
               textFile << lineWithUserData;
            }
            else
            {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << getFileName() << endl;
    }
    textFile.close();
}
