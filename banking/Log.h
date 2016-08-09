#ifndef __LOG_H__
#define __LOG_H__

#include "Message.h"
#include "Status.h"
#include "Money.h"
#include <iostream>

/* Manager for the ATM's internal log.*/
class Log
{
public:
    Log(){};

    ~Log(){};

    std::string logSend(Message * message);

    std::string logResponse(Status* status);

    std::string logCashDispensed(Money* amount);

    std::string logEnvelopeAccepted();
};

#endif //__LOG_H__
