#include "Log.h"

std::string Log::logSend(Message* message){
    std::string ret = "Message: " + message->toString();
    return ret;
}

std::string Log::logResponse(Status* status){
    std::string ret = "Status: " + status->toString();
    return ret;
}

std::string Log::logCashDispensed(Money* amount){
    std::string ret = "CashDispensed: " + amount->toString();
    return ret;
}
