//
// Created by kienlb on 02/06/2016.
//

#ifndef ATM_MONEY_H
#define ATM_MONEY_H

#include <cstring>
#include <string>

class Money {
public:
    Money() : centes_(0) {};
    Money(int dollars): centes_(100L* dollars) {}
    Money(int dollars, int centes) : centes_(100L*dollars + centes) {}

          long centes()       { return centes_;}
    const long centes() const { return centes_;}
    /* Overload operator */

    Money& operator+=(const Money& rhs){
        centes_ += rhs.centes_;
        return *this;
    }

    Money& operator-=(const Money& rhs){
        centes_ -= rhs.centes_;
        return *this;
    }

    Money& operator+(const Money& rhs){
        return (*this += rhs);
    }

    Money& operator-(const Money& rhs){
        return (*this -= rhs);
    }


    std::string toString(){
        return "$" + std::to_string(centes_/100) + "." + std::to_string(centes_ % 100);
    }
    bool operator<(const Money& rhs){
        return centes_ < rhs.centes();
    }

    bool operator>=(const Money& rhs){
        return !(*this < rhs);
    }
    bool operator>(const Money& rhs){
        return centes_ > rhs.centes();
    }

    bool operator<= (const Money& rhs){
        return !(*this > rhs);
    }

    bool operator== (const Money& rhs){
        return centes_ == rhs.centes();
    }
private:
    long centes_;
};

#endif //ATM_MONEY_H
