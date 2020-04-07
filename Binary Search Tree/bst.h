#ifndef BST_H //Always include header guard
#define BST_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif


/* 1. BST */
namespace custom
{
template <class T>
class BST
{
    public:
    #ifdef UNIT_TESTING
    friend int ::main(int argc, const char* argv[]);
    #endif

    class BNode;
    class iterator;

    BST();
    BST(const BST<T>& rhs);
    ~BST();
    BST& operator=(const BST<T> &rhs);
    
    int size() const;
    bool empty() const;
    void clear();
    void insert(const T& t);
    void erase(iterator it);
    iterator find(const T& t);

    iterator begin();
    iterator end();

    private:
    // helper function to restart everything
    void init();
    BNode* root;
    int numElements;

    // helper methods
    BNode* copyFrom(BNode* pSrc);
    int sizeOf(BNode * pTree);
    void deleteFrom(BNode*& pSrc);
    BNode* minNode(BNode* pSrc);
    BNode* maxNode(BNode* pSrc);
    BNode* existsIn(BNode* pSrc, T t);
    BNode* insertAt(BNode* pSrc, T t);
};

/* 2. Implementation */
template <class T>
class BST<T>::BNode
{
    public: 
        BNode();
        BNode(const T& data);

        T data;
        BNode* pLeft;
        BNode* pRight;
        BNode* pParent;
};

/* 3. iterator implementation */
template <class T>
class BST<T>::iterator {

    private: 
    BNode* ptr;

    public:
    #ifdef UNIT_TESTING
    friend int ::main(int argc, const char* argv[]);
    #endif
    friend class BST<T>;
    
    iterator();
    iterator(BNode* p);
    iterator(const iterator &rhs);
    iterator & operator = (const iterator & rhs);
    bool operator==(const iterator& rhs) const;
    bool operator!=(const iterator& rhs) const;

    iterator& operator++(); //num++
    iterator operator++(int postfix); //++num
    iterator& operator--();
    iterator operator--(int postfix);
    T& operator*();
};

}

#include "bst.cpp"
#endif
