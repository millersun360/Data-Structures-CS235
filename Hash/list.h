#ifndef LIST_H
#define LIST_H

#ifndef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    
    template <class T>
    class list <T> :: node
    {
        public:
        T * data;
        node pNext;
        node pPrev;
        node();
        node(const T * t);
    };

    template <class T>
    class list
    {
        public:
        #ifdef UNIT_TESTING
        friend int::main(int argc, const char* argv[]);
        #endif
        
        list();
        list(const list<T> & rhs);
        ~list();

        list & operator = (const list<T> & rhs);
        int size() const;
        bool empty();
        void clear();
        void push_back(const T & t);
        void push_front(const T & t);
        void pop_back();
        void pop_front();
        T & front();
        T & back();

        class node;
        class iterator;
        iterator find(const T & t);
        void erase (iterator it);
        void insert (iterator it, const T & t); //iterator it need &?
        iterator begin();
        iterator end();

        private:
        node pHead;
        node pTail;
        int numElements;
    };

    template <class T>
    class list <T> :: iterator
    {
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
        iterator & operator ++ ();
        iterator operator ++ (int postfix);
        iterator & operator -- ();
        iterator operator -- (int postfix);
        T & operator * ();

        private:
        node p;
    };
    #include "list.cpp"

}

#endif