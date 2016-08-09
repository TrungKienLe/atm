#ifndef __ATM_H__
#define __ATM_H__

#include "CardReader.h"
#include "CashDispenser.h"
#include "NetworkToBank.h"
#include "OperatorPanel.h"
#include "ReceiptPrinter.h"
#include "EnvelopeAcceptor.h"
#include "Log.h"
#include "CustomerConsole.h"
#include <iostream>

/** Representation for the ATM itself.  An object of this class "owns"
 *  the objects representing the component parts of the ATM, and the
 *  communications network, and is responsible for creating customer
 *  sessions which then use it to gain access to the component parts.
 *  This is an active class - when an instance of the class is created,
 *  a thread is executed that actually runs the system.
 */
class ATM
{
public:
    ATM(string name, string ID);

    ~ATM(){
        performShutdown();
    };

    void setName(string name);

    void setID(string ID);

    // /* Operator */

    void switchOn();

    void switchOff();

    /** Perform the System Startup use case when switch is turned on
     */
    void performStartup();

    /** Perform the System Shutdown use case when switch is turned off
     */
    void performShutdown();

     // Methods corresponding to major responsibilities of the ATM
    void run();

    // The following methods allow objects of other classes to access component
    // parts of the ATM
    CardReader*         cardReader() { return cardReader_;}
    CustomerConsole*    customerConsole() { return customerConsole_;}
    CashDispenser*      cashDispenser() { return cashDispenser_;}
    EnvelopeAcceptor*   envelopeAcceptor() {return envelopeAcceptor_;}
    NetworkToBank*      networkToBank() { return networkToBank_;}
    OperatorPanel*      operatorPanel() { return operatorPanel_;}
    ReceiptPrinter*     receiptPrinter() { return receiptPrinter_;}

    string name()   {return name_;}
    string ID()     { return ID_;}
private:
    string name_;
    string ID_;
    Log* log_;
    CardReader* cardReader_;
    CustomerConsole* customerConsole_;
    CashDispenser* cashDispenser_;
    EnvelopeAcceptor* envelopeAcceptor_;
    NetworkToBank* networkToBank_;
    OperatorPanel* operatorPanel_;
    ReceiptPrinter* receiptPrinter_;

    bool isCardInserted_;
    bool switch_on_;

    enum state{
        OFF_STATE, IDLE_STATE, SERVING_CUSTOMER_STATE
    };

    state state_;

};
#endif //__ATM_H__
