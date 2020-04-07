#ifndef BST_H
#define BST_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom
{
    template <class T>
    class BST
    {
        public:
        #ifdef UNIT_TESTING
        friend int :: main(int argc, const char* argv[]);
        #endif
        class iterator;
        class BNode;
        BST();
        BST(const BST<T> & rhs);
        ~BST();
        BST <T> & operator = (const BST<T> & rhs);
        int size() const;
        bool empty() const;
        void clear();
        void insert(const T & t);
        void erase(iterator it);
        iterator find(const T & t);
        iterator begin();
        iterator end();

        private:
        BNode * root;
        int numElements;
        BNode * copyFrom(BNode* pSrc);
        void deleteFrom(BNode * & pSrc); //figure out this
        BNode * minNode(BNode * pSrc);
        BNode * maxNode(BNode * pSrc);
        BNode * existsIn(BNode * pSrc, T t);
        BNode * insertAt(BNode * pSrc, T t);
    };

    template <class T>
    class BST<T>::iterator
    {
        private:
        BNode * ptr;

        public:
        #ifdef UNIT_TESTING
        friend int :: main(int argc, const char* argv[]);
        #endif
        friend class BST<T>;
        iterator();
        iterator(BNode * ptr);
        iterator(const iterator & rhs);
        iterator & operator = (const iterator & it);
        bool operator == (const iterator & it) const;
        bool operator != (const iterator & it) const;
        iterator & operator ++ (); //no right hand side
        iterator operator ++ (int postfix); //prefix / postfix
        iterator & operator -- ();
        iterator operator -- (int postfix);
        T & operator * ();
    };

    template <class T>
    class BST<T>::BNode
    {
        public:
        BNode();
        BNode(const T & t);
        T data;
        BNode * pLeft;
        BNode * pRight;
        BNode * pParent;

    };
    #include "bst.cpp"
}
#endif