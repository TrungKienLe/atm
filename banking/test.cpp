#include "Money.h"
#include "Message.h"
#include "Status.h"
#include "Log.h"
#include "CustomerDatabase.h"


#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{

    // Money b(100);
    // Money c(100,2);

    // Log* log = new Log();

    // Status* a = new Status(true);
    // cout << a->toString() << endl;

    // cout << log->logResponse(a) << endl;
    // cout << log->logCashDispensed(&(b+c)) << endl;
    for(auto &elem : customerData){
        cout << elem.pin_ << endl;
        cout << elem.card_.number() << endl;
        cout << "Total: "<< elem.balance_.total().toString() << endl;
        cout << "Available: " << elem.balance_.availiable().toString() << endl;
    }

    return 0;
}
