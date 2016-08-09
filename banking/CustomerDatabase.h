#ifndef __CUSTOMER_DATABASE_H__
#define __CUSTOMER_DATABASE_H__

#include "Card.h"
#include "Balances.h"
#include <vector>

/*Some customer database to tesing. In real ATM, this will provided by the Bank*/

struct CustomerDatabase {
    Card card_;
    int pin_;
    Balances balance_;
};

CustomerDatabase account1{ Card{1234}, 1234, Balances{15000, 15000}};
CustomerDatabase account2{ Card{5678}, 5678, Balances{20000, 20000}};

std::vector<CustomerDatabase> customerData{ account1, account2};


#endif //__CUSTOMER_DATABASE_H__
