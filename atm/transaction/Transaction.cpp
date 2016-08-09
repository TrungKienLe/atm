#include "Transaction.h"
#include "Message.h"
#include <vector>

#include "Status.h"

#include "Deposit.h"
#include "Inquiry.h"
#include "Transfer.h"
#include "Withdrawal.h"
#include "ATM.h"

#define WITHDRAWAL 1
#define DEPOSITE   2
#define TRANFER    3
#define INQUIRY    4

Transaction* Transaction::makeTransaction(int ID) {
    switch (ID) {
    case WITHDRAWAL:
        return new Withdrawal();
    case DEPOSITE:
        return new Deposit();
    case TRANFER:
        return new Transfer();
    case INQUIRY:
        return new Inquiry();
    default:
        return nullptr;
    }
}

bool Transaction::performTransaction() {
    Message* message = nullptr;
    Receipt* receipt = nullptr;
    Status status;
    bool do_again;

    while (state_ != ASKING_DO_ANOTHER_STATE) {
        switch (state_) {

        case GETTING_SPECIFICS_STATE:
            message = this->getSpecificsFromCustomer();
            state_ = SENDING_TO_BANK_STATE;
            break;

        case SENDING_TO_BANK_STATE:
            if(message != nullptr)
                status = atm_->networkToBank()->sendMessage(message, balance_);

            if(status.isSuccess())
                state_ = COMPLETING_TRANSACTION_STATE;
            else{
                std::cout << status.toString() << std::endl;
                state_ = ASKING_DO_ANOTHER_STATE;
            }
            break;
        case COMPLETING_TRANSACTION_STATE:
            receipt = this->completeTransaction();
            state_ = PRINTING_RECEIPT_STATE;
        case PRINTING_RECEIPT_STATE:
            atm_->receiptPrinter()->print(receipt);
            state_ = ASKING_DO_ANOTHER_STATE;
            break;
        case ASKING_DO_ANOTHER_STATE:
            std::cout << "Do you want to make another transaction ";
            std::cin >> do_again;
            return do_again;
        }
    }
}

int Transaction::getSerialNumber() {
    ;
}

