#ifndef CAST_TO_CHAR_H
#define CAST_TO_CHAR_H

#include "Cast.h"

class CastToChar : public Cast<char> {
    
    public:
        char transform(char *);
};

#endif