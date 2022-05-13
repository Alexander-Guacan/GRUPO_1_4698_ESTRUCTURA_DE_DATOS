#ifndef CAST_H
#define CAST_H

template <typename T> class Cast {
    
    public:
        virtual T transform(char *input) = 0;
};

#endif