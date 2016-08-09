#ifndef __TRANSACTION_H__
#define __TRANSACTION_H__

class ATM;
class Session;
class Card;
class Balances;
class Receipt;
class Message;

/** Abstract base class for classes representing the various kinds of
 *  transaction the ATM can perform
 */

class Transaction
{
public:
    Transaction()
    {}

    Transaction(ATM* atm, Session* session, Card* card, int pin)
        : atm_(atm), session_(session), card_(card), pin_(pin),\
          balance_(), state_{GETTING_SPECIFICS_STATE}
    {}

    virtual ~Transaction(){};

    /* Virtual function for geting specific argument of transaction from customer*/
    virtual Message* getSpecificsFromCustomer() {};

    /** Create a transaction of an appropriate type by asking the customer
     *  what type of transaction is desired and then returning a newly-created
     *  member of the appropriate subclass
     *
     *  @param atm the ATM used to communicate with customer
     *  @param session the session in which this transaction is being performed
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     *  @return a newly created Transaction object of the appropriate type
     *  @exception CustomerConsole.Cancelled if the customer presses cancel instead
     *         of choosing a transaction type
     */
    static Transaction* makeTransaction(int ID);

    /** Peform a transaction.  This method depends on the three abstract methods
     *  that follow to perform the operations unique to each type of transaction
     *  in the appropriate way.
     *
     *  @return true if customer indicates a desire to do another transaction;
     *          false if customer does not desire to do another transaction
     *  @exception CardRetained if card was retained due to too many invalid PIN's
     */
    bool performTransaction();

    /** Perform the Invalid PIN Extension - reset session pin to new value if successful
     *
     *  @return status code returned by bank from most recent re-submission
     *          of transaction
     *  @exception CustomerConsole.Cancelled if customer presses the CANCEL key
     *             instead of re-entering PIN
     *  @exception CardRetained if card was retained due to too many invalid PIN's
     */
    void performInvalidPinExtension();

    int getSerialNumber();

    virtual Receipt* completeTransaction() {};

protected:
    ATM* atm_;
    Session* session_;
    Card* card_;
    Balances* balance_;
    int pin_;

private:
    enum state{
        GETTING_SPECIFICS_STATE,
        SENDING_TO_BANK_STATE,
        COMPLETING_TRANSACTION_STATE,
        PRINTING_RECEIPT_STATE,
        ASKING_DO_ANOTHER_STATE,
    };

    state state_;
};


#endif //__TRANSACTION_H__
