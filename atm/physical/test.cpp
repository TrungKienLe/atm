/*  Program for testing
    Build script:
    g++ -std=c++11 -I./../../banking/ test.cpp
*/


#include "NetworkToBank.h"
#include "Message.h"
#include "CardReader.h"
#include "CashDispenser.h"
#include "EnvelopeAcceptor.h"
//#include "ReceiptPrinter.h"
#include <iostream>


using namespace std;
int main(int argc, char const *argv[])
{
    NetworkToBank* network = new NetworkToBank{"01-LuongYen"};

    network->openConnection();
    network->closeConnection();

    CardReader* cardReader = new CardReader();
    Card card =  cardReader->readCard();

    Log log;

    CashDispenser* cashDispenser = new CashDispenser(&log);
    cashDispenser->setInitialCash(10000);


    Message* mesg = new Message{ INQUIRY, card, 5678, 1 , 1, 0, 100};
    Balances* bal = new Balances();
    Status status = network->sendMessage(mesg, bal);

    cout << status.toString() << endl;
    cout <<"Total     : "<< bal->total().toString() << endl;
    cout <<"Availiable: "<< bal->availiable().toString() << endl;

    cashDispenser->dispenseCash(200);

    return 0;
}
