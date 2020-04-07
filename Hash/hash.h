#ifndef HASH_H
#define HASH_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

#include "list.h";

namespace custom
{
    template <class T>
    class Hash
    {
        public:
        #ifdef UNIT_TESTING
        friend int::main(int argc, const char* argv[]);
        #endif
        
        Hash(int newNumBuckets);
        Hash(Hash<T> & rhs);
        ~Hash();

        Hash<T> & operator = (const Hash<T> & rhs);
        int size();
        int capacity();
        bool empty();
        
        bool find(T aValue, long (*h)(const T& aValue, long theBucketCount));
        void insert (T aValue, long (*h)(const T& aValue, long theBucketCount));

        private:
        list<T> **table;
        int numElements;
        int numBuckets;
    };
    #include "hash.cpp";
}
#endif