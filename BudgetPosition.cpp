#include "BudgetPosition.h"

    void BudgetPosition::setId(int newId)
    {
        if(newId >= 0)
            id = newId;
    }

    void BudgetPosition::setUserId(int newUserId)
    {
        if(newUserId >= 0)
            userId = newUserId;
    }

    void BudgetPosition::setDate(string newDate)
    {
        if(newDate.size() == 8)
            date = newDate;
    }

    void BudgetPosition::setItem(string newItem)
    {
        item = newItem;
    }

    void BudgetPosition::setAmount(double newAmount)
    {
        if(newAmount >= 0)
            amount = newAmount;
    }

    int BudgetPosition::getId()
    {
        return id;
    }

    int BudgetPosition::getUserId()
    {
        return userId;
    }

    string BudgetPosition::getDate()
    {
        return date;
    }

    string BudgetPosition::getItem()
    {
        return item;
    }

    double BudgetPosition::getAmount()
    {
        return amount;
    }
