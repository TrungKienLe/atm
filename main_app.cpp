/* Build script
    g++ -std=c++11 -I./ -I./atm/physical/ -I./atm/transaction/ -I./banking/ main_app.cpp
*/

#include "ATM.h"

int main(int argc, char const *argv[])
{
    ATM atm("BIDV", "18D1");
    atm.run();
    return 0;
}
