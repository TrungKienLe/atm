//
// Created by kienlb on 02/06/2016.
//

#ifndef ATM_MESSAGE_H
#define ATM_MESSAGE_H


/** Representations of a message from the ATM to the bank.
 *  Messages to the bank use a fixed format with fixed slots, not all of which
 *  pertain to any given type of transaction.  Each type of transaction creates
 *  one or more subclasses using the slots that it needs, and supplying appropriate
 *  "not needed" values for the rest.
 */

#include "Card.h"
#include "Money.h"

#include <string>
using std::string;

enum Mesg_code {
    WITHDRAWAL,         // messageCode value for a cash withdrawal message
    INITIATE_DEPOSIT,   // message initiating a deposit
    COMPLETE_DEPOSIT,   // messageCode value for a message completing a deposit (envelope received).
    TRANSFER,           // transfer between accounts message
    INQUIRY             // inquiry message
};

class Message {
  public:
    /** Constructor
     *
     *  @param messageCode identifying the type of message
     *  @param card the customer's card
     *  @param pin the PIN entered by the customer
     *  @param serialNumber serial number of the transaction
     *  @param fromAccount the type of the "from" account of the transaction - can
     *         be -1 if the particular type of transaction does not have a "from"
     *         account (e.g. a deposit)
     *  @param toAccount the type of the "to" account of the transaction - can
     *         be -1 if the particular type of transaction does not have a "to"
     *         account (e.g. a withdrawal)
     *  @param amount the amount of the transaction - can be null if the particular
     *         type of transaction does not have an amount (e.g. an inquiry)
     */
    Message(Mesg_code messageCode, Card card, int pin, int serialNumber, int fromAccount,
            int toAccount, Money amount)
        : messageCode_{messageCode},
          card_{card}, pin_{pin},
          serialNumber_{serialNumber},
          fromAccount_{fromAccount},
          toAccount_{toAccount},
          amount_{amount}
    {}

    // Message()
    //     : messageCode_{INQUIRY},
    //       card_{}, pin_{},
    //       serialNumber_{},
    //       fromAccount_{},
    //       toAccount_{},
    //       amount_{0}
    // {}

    /* Create a printable string representing this message*/
    string toString() {
        string result = "";
        switch (messageCode_) {
        case WITHDRAWAL:
            result += "WITHDRAWAL";
            break;
        case INITIATE_DEPOSIT:
            result += "INITIATE_DEPOSIT";
            break;
        case COMPLETE_DEPOSIT:
            result += "COMPLETE_DEPOSIT";
            break;
        case TRANSFER:
            result += "TRANSFER";
            break;
        case INQUIRY:
            result += "INQUIRY";
            break;
        }

        result += " CARD# " + std::to_string(card_.number());
        result += " TRANS# " + std::to_string(serialNumber_);
        if (fromAccount_ >= 0)
            result += " FROM  " + std::to_string(fromAccount_);
        else
            result += " NO FROM";
        if (toAccount_ >= 0)
            result += " TO  " + std::to_string(fromAccount_);
        else
            result += " NO TO";
        if (amount_ > 0)
            result += " " + amount_.toString();
        else
            result += " NO AMOUNT";

        return result;

    }

    /* Return code identifying the type of message*/
    int messageCode() { return messageCode_;}

    /**/
    int pin() { return pin_;}

    /* Set new PIN*/
    void setPIN(int pin) { pin_ = pin;}

    /**/
    Card& card() { return card_;}

    /**/
    int serialNumber() { return serialNumber_;}

    /**/
    int fromAccount() { return fromAccount_;}

    /**/
    int toAccount() { return toAccount_;}

    /**/
    Money amount() { return amount_;}

    /*messageCode value for a cash withdrawal message*/

  private:
    Mesg_code messageCode_;
    Card card_;
    int pin_;
    int serialNumber_;
    int fromAccount_;
    int toAccount_;
    Money amount_;

};

#endif //ATM_MESSAGE_H
