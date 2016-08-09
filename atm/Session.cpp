#include "Session.h"
#include "ATM.h"
#include "Transaction.h"
#include <vector>

#include "Card.h"

/* Menu choise of chansaction */
std::vector<std::string> session_choise{
    "1. Withdrawal",
    "2. Deposite",
    "3. Tranfer",
    "4. Inquiry"
};

void Session::performSession() {
    /* Store ID to make transaction type*/
    int ID;
    /* Object manage current transaction */
    Transaction* current_transaction = nullptr;
    /* Flag to know customer do another transaction or not*/
    bool do_again;

    while (state_ != FINAL_STATE) {
        switch (state_) {

        case READING_CARD_STATE:

            std::cout << "READING_CARD_STATE" << std::endl;
            card_ = atm_->cardReader()->readCard();
            if (card_ != ERROR_CARD)
                state_ = READDING_PIN_STATE;
            else {
                std::cout << "Invalid Card " << std::endl;
                state_ = EJECTING_CARD_STATE;
            }
            break;

        case READDING_PIN_STATE:
            std::cout << "READDING_PIN_STATE" << std::endl;
            std::cout << "Please input PIN code: " << std::endl;
            std::cin >> pin_;
            state_ = CHOOSING_TRANSACTION_STATE;
            break;

        case CHOOSING_TRANSACTION_STATE:
            ID = atm_->customerConsole()->getMenuChoise(session_choise);
            current_transaction = Transaction::makeTransaction(ID);
            if (current_transaction != nullptr)
                state_ = PERFORMING_TRANSACTION_STATE;
            else // Invalid transaction
                state_ = EJECTING_CARD_STATE;
            break;

        case PERFORMING_TRANSACTION_STATE:
            do_again = current_transaction->performTransaction();
            if (do_again == true)
                state_ = CHOOSING_TRANSACTION_STATE;
            else
                state_ = EJECTING_CARD_STATE;
            break;

        case EJECTING_CARD_STATE:
            atm_->cardReader()->rejectCard();
            state_ = FINAL_STATE;
            break;

        case FINAL_STATE:
            break;
        }
    }
}
