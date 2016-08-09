//
// Created by kienlb on 02/08/2016.
//

#ifndef ATM_STATUS_H
#define ATM_STATUS_H

#include <string>

/** Abstract base class for representation of various status codes returned
 *  by bank for a transaction.  The bank will create appropriate subclasses.
 */
class Status {
public:

    Status () : result_{false}, message_{}
    {}

    Status(bool result) : result_{result}, message_{}
    {}

    Status(bool result, string message) : result_{result}, message_{message}
    {}

    /** Create a printable string representing this status
     *
     *  @return string representation
     */
    std::string toString()
    {
        if (isSuccess())
            return "SUCCESS";
        else if (isInvalidPIN())
            return "INVALID PIN";
        else
            return "FAILURE " + getMessage();
    }

    /** See if this status represents success
     *
     *  @return true if this status represents success
     */
    bool isSuccess() {return result_ == true;}

    /** See if this status represents an invalid PIN
     *
     *  @return true if this status represents an invalid PIN
     */
    bool isInvalidPIN()  {return result_ != false;}

    /** Accessor for message describing this status (used if status is
     *  not success)
     *
     *  @return description of the problem
     */
    std::string getMessage(){return message_;}
private:
    bool result_;
    std::string message_;
};


#endif //ATM_STATUS_H
