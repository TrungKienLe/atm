#ifndef _CASH_DISPENSER_H__
#define _CASH_DISPENSER_H__

#include "Log.h"
#include "Money.h"

#include <iostream>
/*
    Keep track of cash on hand, starting with initial amount
    Report whether enough cash is available
    Dispense cash
*/

class CashDispenser
{
public:
    CashDispenser(Log* log): log_{log}, cashOnHand_{}
    {}
    ~CashDispenser() {};

    void setInitialCash(Money init_cashi);


    bool checkCashOnHand(Money amount);

    void dispenseCash(Money amount);

private:
    Log* log_;
    Money cashOnHand_;
};


#endif // _CASH_DISPENSER_H__
