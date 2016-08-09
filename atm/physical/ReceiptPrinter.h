#ifndef __RECEIPT_PRINTER_H__
#define __RECEIPT_PRINTER_H__

#include "Receipt.h"
#include <iostream>

/* Class handle print receipt */
class ReceiptPrinter
{
public:
    void print(Receipt* receipt){
        std::cout << receipt->toString();
    }
};
#endif //__RECEIPT_PRINTER_H__
