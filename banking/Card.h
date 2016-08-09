//
// Created by kienlb on 02/06/2016.
//

#ifndef ATM_CARD_H
#define ATM_CARD_H

/** Representation for customer's ATM card
 */
#define ERROR_CARD -1

class Card {
public:
    Card(): number_{ERROR_CARD}
    {}

    Card(int number): number_{number}
    {}

    const int number() const { return number_;}

    bool isValid() { return number_ != ERROR_CARD;}

    bool operator==(const Card& otherCard){
        return this->number_ == otherCard.number();
    }

    bool operator!=(const Card& otherCard){
        return !(*this == otherCard);
    }
private:
    /* Card number encoded on the card */
    int number_;
};

#endif //ATM_CARD_H
