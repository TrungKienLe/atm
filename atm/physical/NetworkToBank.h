#ifndef __NETWORK_TO_BANK_H__
#define __NETWORK_TO_BANK_H__
#include "Log.h"
#include "Message.h"
#include "Balances.h"
#include "Status.h"

// #include "CustomerDatabase.h" // fake data to testing :D.

#include <iostream>

/* Manage connection of network to the bank.
    Send and get status of customer request
*/

class NetworkToBank
{
public:
    NetworkToBank(std::string bankAddress): bank_addr_{bankAddress}
    {}
    /* Open connection at system statup*/
    void openConnection();

    /* Close connection at system shutdown*/
    void closeConnection();

    /* Send Message, fill up balance and rececived status from the bank */
    Status sendMessage(Message* message, Balances* balance);

    ~NetworkToBank() {};
private:
    std::string bank_addr_;
};

#endif //__NETWORK_TO_BANK_H__
