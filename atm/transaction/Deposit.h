#ifndef __DEPOSIT__H
#define __DEPOSIT__H

#include "Transaction.h"
#include <iostream>

class Message;
class Receipt;

class Deposit : public Transaction
{
public:
    Deposit(){};
    ~Deposit(){};
    Message* getSpecificsFromCustomer() {};
    Receipt* completeTransaction() {};

};

#endif
