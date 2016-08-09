#ifndef __INQUIRY__H__
#define __INQUIRY__H__

#include "Transaction.h"
#include <iostream>

class Message;
class Receipt;

class Inquiry : public Transaction
{
public:
    Inquiry() {};
    ~Inquiry() {};
    Message* getSpecificsFromCustomer() {};
    Receipt* completeTransaction() {};
};

#endif
