#include "CardReader.h"

Card CardReader::readCard(){
    // TODO: reimplement by using GUI->display()
    std::cout << "Card number: " << std::endl;
    int cardNumber;
    std::cin >> cardNumber;

    return Card{cardNumber};
}

void CardReader::retainCard(){
    std::cout << "Retain card!" << std::endl;
}


void CardReader::rejectCard(){
    std::cout << "Reject card!" << std::endl;
}
