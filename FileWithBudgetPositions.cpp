#include "FileWithBudgetPositions.h"

using namespace std;

bool FileWithBudgetPositions::addBudgetPositions(BudgetPosition budgetPosition)
{
    CMarkup xmlFile;
    bool fileExists, fileSaved;

    fileExists = xmlFile.Load(getFileName().c_str());

     if (!fileExists)
    {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("BudgetPositions");
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("BudgetPosition");
    xmlFile.IntoElem();
    xmlFile.AddElem("Id", budgetPosition.getId());
    xmlFile.AddElem("UserId", budgetPosition.getUserId());
    xmlFile.AddElem("Date", OperationsOnDates::convertDateIntToString(budgetPosition.getDate()));
    xmlFile.AddElem("Item", budgetPosition.getItem());
    xmlFile.AddElem("Amount", AuxiliaryMethods::conversionDoubleToString(budgetPosition.getAmount()));

    fileSaved = xmlFile.Save(getFileName().c_str());

    if(fileSaved)
    {
        return true;
    }

    return false;
}

vector<BudgetPosition> FileWithBudgetPositions::getBudgetPositionsOfLoggedInUserFromFile(int idLoggedInUser)
{
    CMarkup xmlFile;
    bool fileExist;
    vector<BudgetPosition> budgetPositions;
    BudgetPosition budgetPosition;

    fileExist = xmlFile.Load(getFileName().c_str());

    if(!fileExist)
        return budgetPositions;

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem("BudgetPosition"))
    {
        xmlFile.IntoElem();
        xmlFile.FindElem("Id");
        budgetPosition.setId(AuxiliaryMethods::conversionStringToInt(MCD_2PCSZ(xmlFile.GetData())));
        xmlFile.FindElem("UserId");
        budgetPosition.setUserId(AuxiliaryMethods::conversionStringToInt(MCD_2PCSZ(xmlFile.GetData())));

        if(budgetPosition.getUserId() != idLoggedInUser)
        {
            xmlFile.OutOfElem();
            continue;
        }

        xmlFile.FindElem("Date");
        budgetPosition.setDate(OperationsOnDates::convertDateStringToInt(xmlFile.GetData()));
        xmlFile.FindElem("Item");
        budgetPosition.setItem(xmlFile.GetData());
        xmlFile.FindElem("Amount");
        budgetPosition.setAmount(atof(MCD_2PCSZ(xmlFile.GetData())));
        xmlFile.OutOfElem();

        budgetPositions.push_back(budgetPosition);
    }

    return budgetPositions;
}

int FileWithBudgetPositions::getLastBudgetPositionIdFromFile()
{
    CMarkup xmlFile;
    bool fileExist;
    int idOfLastBudgetPosition = 0;

    fileExist = xmlFile.Load(getFileName().c_str());

    if(!fileExist)
    {
        return 0;
    }

    xmlFile.FindElem();
    xmlFile.IntoElem();

    while(xmlFile.FindElem("BudgetPosition"))
    {
        xmlFile.IntoElem();
        xmlFile.FindElem("Id");
        idOfLastBudgetPosition = AuxiliaryMethods::conversionStringToInt(MCD_2PCSZ(xmlFile.GetData()));
        xmlFile.FindElem("UserId");
        xmlFile.FindElem("Date");
        xmlFile.FindElem("Item");
        xmlFile.FindElem("Amount");
        xmlFile.OutOfElem();
    }

    return idOfLastBudgetPosition;
}

