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
        stack(int numCapacity);
        stack(stack rhs);
        ~stack();

        stack assign(stack rhs);
        int size();
        int capacity();
        bool empty();
        void clear();
        void push(T t);
        void pop();
        T & top();

    };
}

#endif