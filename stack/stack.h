#ifndef STACK_H //this is the header guard
#define STACK_H

#ifdef UNIT_TESTING // this is the unit testing macro
int main(int argc, const char* argv[]);
#endif

namespace custom
{

    template <class T>
    class stack
    {
        private:
            
        T * buffer;
        int numElements;
        int numCapacity;
        void resize(int numCapacity);

        public:

        #ifdef UNIT_TESTING // this is the unit testing macro
        friend int :: main(int argc, const char* argv[]);
        #endif

        stack();
        stack(int numElements);
        stack(int numElements, const T & t); //fix
        stack(const stack<T> & rhs);
        ~stack();

        stack & operator = (const stack<T> & rhs);
        int size() const;
        int capacity();
        bool empty();
        void clear();
        void push(const T & t);
        void pop();
        T & top();
    };

    #include "stack.cpp"
};

#endif