#ifndef __TRANSFER_H__
#define __TRANSFER_H__

#include "Transaction.h"
#include <iostream>

class Message;
class Receipt;

class Transfer : public Transaction
{
public:
    Transfer() {};
    ~Transfer() {};
    Message* getSpecificsFromCustomer() {};
    Receipt* completeTransaction() {};

};
#endif
