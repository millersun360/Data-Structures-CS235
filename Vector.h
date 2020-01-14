#ifndef VECTOR_H //this is the header guard
#define VECTOR_H

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
        int numElements;
        int numCapacity; 

        void resize (int numCapacity);

        public:

        #ifdef UNIT_TESTING // only for Unit Testing
        friend int :: main(int argc, const char* argv[]); // gives main access to the private members of vector so that it can validate its functionality
        #endif

        vector(); //default vector (main line 48)
        vector(int numElements); //sized vector (main line 57)
        vector(int numElements, T t); //
        vector(vector rhs); //copy vector (main line 300)
        ~vector(); //deconstructer

        vector assign(vector rhs);
        int size();
        int capacity();
        bool empty();
        void clear();
        void push_back(T t);
        T access(int index); //check to see that this is what its called in main
        iterator begin();
        iterator end();
    };

    template <class it>
    class iterator
    {
        private:

        T p; //vector from template

        public:

        #ifdef UNIT_TESTING
        friend int :: main(int argc, const char* argv[]);
        #endif

        iterator();
        iterator(T p);
        iterator(iterator rhs);

        iterator assignment(iterater it);
        bool isEquals(iterator it);
        bool isNEqual(iterator it);
        iterator increment();
        iterator decrement();
        T dereference();
    }

}

#include "vector.cpp"

#endif