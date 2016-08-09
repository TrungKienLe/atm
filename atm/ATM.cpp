#include "ATM.h"
#include "Session.h"

ATM::ATM(string name, string ID) : name_{name}, ID_{ID} {
    cardReader_         = new CardReader();
    customerConsole_    = new CustomerConsole();
    log_                = new Log();
    cashDispenser_      = new CashDispenser(log_);
    envelopeAcceptor_   = new EnvelopeAcceptor(log_);
    networkToBank_      = new NetworkToBank(name);
    operatorPanel_      = new OperatorPanel();
    receiptPrinter_     = new ReceiptPrinter();

    switch_on_          = false;
    isCardInserted_     = false;
    state_              = OFF_STATE;
}

void ATM::setName(string name){
    name_ = name;
}

void ATM::setID(string ID){
    ID_ = ID;
}

void ATM::switchOn(){
    state_ = IDLE_STATE;
    std::cout << "switchOn: "<< state_ << std::endl;
}

void ATM::switchOff(){
    std::cout << "switchOff" << std::endl;
    // state = OFF_STATE;
}

void ATM::performStartup(){
    this->switchOn();
    networkToBank_->openConnection();
    Money init_money = operatorPanel_->getInitCash();
    cashDispenser_->setInitialCash(init_money);
}


void ATM::performShutdown(){
    this->switchOff();
    networkToBank_->closeConnection();
}


void ATM::run(){
    while(true){
        switch(state_){
            case OFF_STATE:
                std::cout << "Not current available: input \"on\"" << std::endl;
                 /* Hack: waite until turn on switch*/
                for(string command; std::cin >> command && command != "on";);
                    switch_on_ = true;

                if(switch_on_){
                    performStartup();
                    state_ = IDLE_STATE;
                }
                break;
            case IDLE_STATE:
                std::cout << "Please insert your card: input \"insert\"" << std::endl;
                 /* Hack: waite until insert card */
                /* In real code will use sensor and interrupt to detect*/
                for(string command; std::cin >> command && command != "insert";);

                isCardInserted_ = true;

                if(isCardInserted_){
                    /*Start new session and update state*/
                    state_ = SERVING_CUSTOMER_STATE;
                }

                if(!switch_on_){
                    performShutdown();
                    state_ = OFF_STATE;
                }
                break;
            case SERVING_CUSTOMER_STATE:
                /* Create session and perform session!*/
                Session* current_session = new Session(this);
                current_session->performSession();
                state_ = IDLE_STATE;
                break;
        }
    }
}
