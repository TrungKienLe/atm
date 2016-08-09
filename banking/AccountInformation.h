//
// Created by kienlb on 02/08/2016.
//

#ifndef ATM_ACCOUNTINFO_H
#define ATM_ACCOUNTINFO_H

#include <string>
#include <vector>

/** The static members of this class inco,rporate information about accounts
 *  offered by the bank.  Actual communication with the bank uses account type
 *  numbers - e.g. 0 represents the first type of account listed.
 */

class AccountInfo {
public:
    /** Names for accounts to be offered in menu to customer
 */
 std::vector<std::string> ACCOUNT_NAMES =
            { "Checking", "Savings", "Money Market" };

    /** Abbreviations for account names to be printed on receipts.
     */
  std::vector<std::string> ACCOUNT_ABBREVIATIONS =
            { "CHKG", "SVGS", "MMKT" };
};

#endif //ATM_ACCOUNTINFO_H
