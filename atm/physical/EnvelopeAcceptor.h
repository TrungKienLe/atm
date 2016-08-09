#ifndef __ENVELOP_ACCEPTOR_H__
#define __ENVELOP_ACCEPTOR_H__

#include "Log.h"

/* Accept envelope from customer; report if timed out or cancelled */
class EnvelopeAcceptor
{
public:
    EnvelopeAcceptor(Log* pLog): log_{pLog}
    {};

    ~EnvelopeAcceptor(){};

    void acceptEnvelope(){
        ;
    }
private:
    Log* log_;
};
#endif //__ENVELOP_ACCEPTOR_H__
