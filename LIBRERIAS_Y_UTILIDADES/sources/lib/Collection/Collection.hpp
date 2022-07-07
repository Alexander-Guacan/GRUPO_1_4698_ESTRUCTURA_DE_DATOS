#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <cstddef>

template <typename E>
class Collection {
    
    public:
        // Returns true if this collection contains no elements
        virtual bool isEmpty() const = 0;
        // Returns the number of elements in this collection
        virtual size_t size() const = 0;
        // Removes all elements from this collection
        virtual void clear() = 0;
};

#endif