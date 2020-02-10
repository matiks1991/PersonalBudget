#ifndef FILEWITHBUDGETPOSITIONS_H
#define FILEWITHBUDGETPOSITIONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string.h>

#include "BudgetPosition.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"
#include "Markup.h"
#include "OperationsOnDates.h"

using namespace std;

class FileWithBudgetPositions : public TextFile
{
    public:
    FileWithBudgetPositions(string FILENAMEWITHBUDGETPOSITIONS) : TextFile(FILENAMEWITHBUDGETPOSITIONS){};
    bool addBudgetPositions(BudgetPosition budgetPosition);
    vector<BudgetPosition> getBudgetPositionsOfLoggedInUserFromFile(int idLoggedInUser);
    int getLastBudgetPositionIdFromFile();
};

#endif
