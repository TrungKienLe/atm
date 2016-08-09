//
// Created by kienlb on 02/06/2016.
//

#ifndef ATM_BALANCES_H
#define ATM_BALANCES_H

/** Representation for customer's current account balances as returned by the
 *  bank.  An empty object of this class is created and sent along with the
 *  transaction message; the bank fills it in with values.
 */

#include "Money.h"

class Balances {
public:
    /* Constructor. Create an object whose values will be filled in later
     * */
    Balances() :total_{0}, available_{0}
    {}

    Balances(Money total, Money available): total_{total}, available_{available}
    {}

    void set_balances(Money total, Money available){
        this->total_ = total;
        this->available_ = available;
    }

    Money total() { return total_; }
    Money available() { return available_;}

private:
    Money total_;
    Money available_;
};


#endif //ATM_BALANCES_H
