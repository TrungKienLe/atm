#ifndef __CUSTOMER_CONSOLE_H__
#define __CUSTOMER_CONSOLE_H__

#include <vector>
#include <iostream>

class CustomerConsole
{
public:
    // CustomerConsole();
    // ~CustomerConsole();
    int getMenuChoise(std::vector<std::string> choise){
        for(auto& elem : choise){
            std::cout<< elem << std::endl;
        }
        std::cout << "Select: ";
        int ret;
        std::cin >> ret;

        return ret;
    }

};

#endif //__CUSTOMER_CONSOLE_H__
