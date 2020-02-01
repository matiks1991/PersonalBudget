#ifndef BUDGETPOSITION_H
#define BUDGETPOSITION_H

#include <iostream>

using namespace std;

class BudgetPosition
{
    int id, userId;
    string date, item;
    double amount;

public:
    BudgetPosition(int id=0, int userId=0, string date="", string item="", double amount=0)
    {
        this->id = id;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }

    void setId(int newId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();
};

#endif

