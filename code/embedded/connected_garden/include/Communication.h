#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "Debug.h"

class Communication{
    public:
    Communication(Debug& debug);

    protected:
    Debug& _debug;
};
#endif /* COMMUNICATION_H */
