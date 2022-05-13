#ifndef CAST_TO_FLOAT_H
#define CAST_TO_FLOAT_H

#include "Cast.h"

class CastToFloat : public Cast<float> {
    
    public:
        float transform(char* input);
    
};

#endif