#include "Receipt.h"

#include "Card.h"
#include "Balances.h"
#include "ATM.h"
#include "Transaction.h"
#include <string>

Receipt::Receipt(ATM* atm, Card* card, Transaction* transaction, Balances* balances)
    : atm_{atm}, card_{card}, transaction_{transaction}, balances_{balances} {

    /*Heading portion of the receipt */
    heading_portion[0] = get_today();
    heading_portion[1] = atm_->name();
    heading_portion[2] = "#ATM #" + atm_->ID();
    //heading_portion[3] = "CARD " + std::to_string(card_->number()) + "TRANS #"\
    + std::to_string(transaction_.serial_number());
    heading_portion[3] = "CARD " + std::to_string(card_->number());
    // Balances portion of the receipt

    balances_portion[0] = "TOTAL BAL: " + balances_->total().toString();
    balances_portion[1] = "AVAILABLE: " + balances_->available().toString();

}


    /* Print to teminal to testing*/
    std::string Receipt::toString() {
        std::string ret = "";
        for (auto p : heading_portion)
            ret += p + "\n";
        for (auto p : balances_portion)
            ret += p + "\n";
        return ret;
    }
