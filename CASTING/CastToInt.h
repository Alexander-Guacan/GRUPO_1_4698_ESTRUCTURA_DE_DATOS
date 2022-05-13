#ifndef CAST_TO_INT_H
#define CAST_TO_INT_H

#include "Cast.h"

class CastToInt : public Cast<int> {
    
    public:
        int transform(char* input);
    
};

#endif