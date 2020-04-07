#ifndef MAP_H
#define MAP_H

#include "bst.h"

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template<class K, class V>
    class map<K, V>::pair
    {
        public:
        K first;
        V second;
        pair();
        pair(const K & key, const V & value);
        bool operator = (const pair  & rhs) const;
        bool operator == (const pair & rhs) const;
        bool operator > (const pair & rhs) const;
        bool operator < (const pair & rhs) const;
        bool operator >= (const pair & rhs) const;
        bool operator <= (const pair & rhs) const;
    };
    template<class K, class V>
    class map
    {
        public:
        #ifdef UNIT_TESTING
        friend int :: main(int argc, const char* argv[]);
        #endif
        class iterator;
        class pair;
        map();
        map(const map<K, V> & map);
        ~map();
        map<K,V> & operator = (const map<K,V> & rhs);
        int size();
        bool empty();
        void clear();
        void insert(pair);
        iterator find(const K & key);
        iterator begin();
        iterator end();

        private:
        BST<pair> bst;
    };

    template <class K, class V>
    class map<K, V>::iterator
    {
        private:
        BST<pair>::iterator it;

        public:
        #ifdef UNIT_TESTING
        friend int :: main(int argc, const char* argv[]);
        #endif
        iterator();
        iterator(const BST<pair>::iterator & rhs);
        iterator(const iterator & rhs);
        iterator & operator = (const iterator & it);
        bool operator == (const iterator & it) const;
        bool operator != (const iterator & it) const;
        iterator & operator ++ ();
        iterator & operator -- ();
        T & operator * ();
    };
    #include "map.cpp"
}
#endif