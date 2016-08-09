//
// Created by kienlb on 02/06/2016.
//

#ifndef ATM_RECEIPT_H
#define ATM_RECEIPT_H



// #include "Card.h"
// #include "Balances.h"
// #include "ATM.h"
// #include "Transaction.h"

#include <iostream>
#include <ctime>
#include <string>

class Card;
class Balances;
class ATM;
class Transaction;

/** Abstract base class for representation of a receipt to be printed.  Each
 *  specific type of transaction creates an instance of a concrete subclass
 *  of this class.
 */


class Receipt {
  public:
    /** Constructor.  This base class constructor will create the portions of the
     *  receipt that are common to all types of transaction, and the subclass
     *  constructor will create the details portion unique to each type.
     *
     *  @param atm the ATM where the transaction was done
     *  @param card the card that was used
     *  @param transaction the Transaction object for the transaction
     *  @param balances Balances object giving final balances for account used
     */
    Receipt()
    {}

    Receipt(ATM* atm, Card* card, Transaction* transaction, Balances* balances);

    /** Get the individual lines to be printed.  Each call to the nextElement()
     *  of the enumeration gets one line (as a String)
     */

    // void getLines();

    /* Print to teminal to testing*/
    std::string toString();

  private:
    /* Heading portion of the receipt - common to all forms of receipt*/
    std::string heading_portion[4];

    /** Transaction details portion of the receipt - specific to each type of
     *  transaction, and therefore filled in by subclasses
     */
    std::string detail_portion[2];

    /** Ending balances portion of the receipt - common to all forms of receipt
     */
    std::string balances_portion[2];

    ATM* atm_;
    Card* card_;
    Transaction* transaction_;
    Balances* balances_;

    /*Helper function*/
    std::string get_today() {
        time_t now = time(0);
        char* date = ctime(&now);
        return (date);
    }

};

#endif //ATM_RECEIPT_H
