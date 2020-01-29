#ifndef VECTOR_H //this is the header guard
#define VECTOR_H
#include <iostream>
#ifdef UNIT_TESTING // this is the unit testing macro
int main(int argc, const char* argv[]);
#endif

// no inline implementations! (all in vector.cpp)
namespace custom // (main line 41)
{
    template <class T> //template so that we can use any data type
    class vector
    {
        private:

        T * buffer; 
        int numElements; // # of elements (size)
        int numCapacity; //doubles when buffer filled

        void resize (int numCapacity); //utilized by push back function, creates an array double the size of previous
    
        public:

        #ifdef UNIT_TESTING
        friend int :: main(int argc, const char* argv[]);
        #endif

        vector(); //default vector (main line 48)
        vector(int numElements); //sized vector (main line 57)
        vector(int numElements, const T & t); //initialize each slot of the vector with the value of "t"
        vector(const vector <T> & rhs); //copy vector (main line 300)
        ~vector(); //deconstructer

        vector <T> & operator = (const vector & rhs);
        int size() const;
        int capacity();
        bool empty();
        void clear();
        void push_back(const T & t); //adds the element to the end, if numElements = numCapacity, call resize
        T & operator [] (int index); //check to see that this is what its called in main
        const T & operator [] (int index) const;
        class iterator;

        iterator begin();
        iterator end();
    };

    template <class T>
    class vector <T>  :: iterator
    {
        private:

        T * ptr; //vector from template

        public:

        #ifdef UNIT_TESTING
        friend int :: main(int argc, const char* argv[]);
        #endif

        iterator();
        iterator(T * p);
        iterator(const iterator & rhs);

        iterator & operator = (const iterator & it);
        bool operator != (const iterator & it) const;
        bool operator == (const iterator & it) const;
        iterator & operator ++ (); //no right hand side
        iterator operator ++ (int postfix); //prefix / postfix
        iterator & operator -- ();
        iterator operator -- (int postfix);
        T & operator * ();
    };

    #include "vector.cpp"

};

#endif