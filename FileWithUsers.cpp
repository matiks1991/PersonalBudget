#include "FileWithUsers.h"

using namespace std;

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(getFileName().c_str());

     if (!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("Users");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("User");
    xmlFile.IntoElem();
    xmlFile.AddElem("UserId", user.getId());
    xmlFile.AddElem("Login", user.getLogin());
    xmlFile.AddElem("Password", user.getPassword());

    xmlFile.Save(getFileName().c_str());
}

vector <User> FileWithUsers::getUsersFromFile()
{
    User user;
    vector<User> users;
    CMarkup xmlFile;

    xmlFile.Load(getFileName().c_str());

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem("User"))
    {
        xmlFile.IntoElem();
        xmlFile.FindElem("UserId");
        user.setId(AuxiliaryMethods::conversionStringToInt(MCD_2PCSZ(xmlFile.GetData())));
        xmlFile.FindElem("Login");
        user.setLogin(xmlFile.GetData());
        xmlFile.FindElem("Password");
        user.setPassword(xmlFile.GetData());
        xmlFile.OutOfElem();

        users.push_back(user);
    }

    return users;
}

void FileWithUsers::saveAllUsersToFile(vector <User> &users)
{
    CMarkup xmlFile;

    xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xmlFile.AddElem("Users");
    xmlFile.IntoElem();

    for(vector<User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        xmlFile.AddElem("User");
        xmlFile.IntoElem();
        xmlFile.AddElem("UserId", itr -> getId());
        xmlFile.AddElem("Login", itr -> getLogin());
        xmlFile.AddElem("Password", itr -> getPassword());
        xmlFile.OutOfElem();
    }

        xmlFile.Save(getFileName().c_str());
}
