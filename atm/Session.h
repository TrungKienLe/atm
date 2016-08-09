#ifndef __SESSION_H__
#define __SESSION_H__

#include "Transaction.h"
#include "Card.h"

class ATM;

/** Representation for one ATM session serving a single customer. */
class Session
{
public:
    Session(ATM* atm): atm_{atm}, pin_{}, card_{},  state_{READING_CARD_STATE}
    {}

    ~Session() {};

    void setPIN(int pin) { pin_ = pin;}

    /** Perform the Session Use Case
     */
    void performSession();

private:
    ATM* atm_;
    int pin_;
    Card card_;

    /* State of session */
    enum state{
        READING_CARD_STATE,
        READDING_PIN_STATE,
        CHOOSING_TRANSACTION_STATE,
        PERFORMING_TRANSACTION_STATE,
        EJECTING_CARD_STATE,
        FINAL_STATE
    };

    state state_;
};



#endif //__SESSION_H__
