#ifndef BUDGETPOSITION_H
#define BUDGETPOSITION_H

#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetPosition
{
    int id, userId, date;
    string item;
    double amount;

public:
    BudgetPosition(int id=0, int userId=0, int date=0, string item="", double amount=0)
    {
        this->id = id;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif

