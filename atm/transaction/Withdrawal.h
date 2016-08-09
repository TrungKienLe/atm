#ifndef __WITHDRAWAL_H__
#define __WITHDRAWAL_H__

#include "Transaction.h"
#include <iostream>

class Message;
class Receipt;

class Withdrawal : public Transaction
{
public:
    Withdrawal() {};
    ~Withdrawal() {};

    Message* getSpecificsFromCustomer() {};
    Receipt* completeTransaction() {};

};

#endif //__WITHDRAWAL_H__
