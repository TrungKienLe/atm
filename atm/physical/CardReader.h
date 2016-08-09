#ifndef __CARD_READER_H__
#define __CARD_READER_H__

#include "Card.h"
#include <iostream>

/*Manager for the ATM's card reader*/
class CardReader
{
public:
    /* Constructor*/
    CardReader() {};
    /* Read card in to Card object*/
    Card readCard();
    /* Retain card in case 3 times input invalid password*/
    void  retainCard();
    /* Reject Card when finish session or abort*/
    void  rejectCard();
};

#endif //__CARD_READER_H__
