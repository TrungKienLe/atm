#include "CashDispenser.h"

void CashDispenser::setInitialCash(Money init_cash) {
    cashOnHand_ = init_cash;
}

bool CashDispenser::checkCashOnHand(Money amount) {
    return cashOnHand_ >= amount;
}


void CashDispenser::dispenseCash(Money amount) {
    if (checkCashOnHand(amount)) {
        std::cout << "Dispense: " << amount.toString() << std::endl;
        log_->logCashDispensed(&amount);
        cashOnHand_ -= amount;
    }
}
