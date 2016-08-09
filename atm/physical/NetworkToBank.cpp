#include "NetworkToBank.h"
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





void NetworkToBank::openConnection(){
    /*print log to simulation*/
    std::cout<< "NetworkToBank: openConnection" << std::endl;
}


void NetworkToBank::closeConnection(){
    /*print log to simulation*/
    std::cout<< "NetworkToBank: closeConnection" << std::endl;
}

Status NetworkToBank::sendMessage(Message* message, Balances* balance){
    bool result;
    for(auto& elem : customerData){
        if(message->card() == elem.card_ ){
            if(message->pin() == elem.pin_){
                *balance = elem.balance_;
                return Status{true, "OK"};
            }
        }
    }

    return Status{false, "Account or PIN invalid"};
}
