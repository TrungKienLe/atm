#ifndef __OPERATOR_PANEL_H__
#define __OPERATOR_PANEL_H__

#include "Money.h"
#include <iostream>

/*
Inform ATM of changes to state of switch
Allow operator to specify amount of initial cash*/

class OperatorPanel
{
public:
    OperatorPanel(){};

    ~OperatorPanel(){};

    Money getInitCash(){
        std::cout << "Set init cash" << std::endl;
        int init_money;
        std::cin >> init_money;
        return Money{init_money};
    }
};
#endif // __OPERATOR_PANEL_H__
