/*
 * Custom list implementation with iterator and const iterator.
 * 
 * @author Matt Manley
 * @since 19 Sep 2019
 */

#ifndef LIST_H
#define LIST_H

#ifdef UNIT_TESTING
int main(int argc, const char *argv[]);
#endif

namespace custom
{

/*
    * Custom implementation of list.
    */
template <class T>
class list
{
public:
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif

    list();
    list(const list<T> &rhs);
    ~list();

    class node;
    class iterator;

    list<T> &operator=(const list<T> &rhs);

    int size() const;
    bool empty() const;
    void clear();

    void push_front(const T &t);
    void push_back(const T &t);
    void pop_front();
    void pop_back();
    T &front();
    T &back();

    void insert(iterator it, T element);
    void insertAt(node* pCurrent, T element, bool after);
    iterator find(const T &t);
    iterator erase(iterator it);
    iterator begin();
    iterator end();

private:
    node* pHead;
    node* pTail;
    int numElements;
};
///////////////////////////////////////////


template <class T>
class list<T>::node
{
public:
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif
    friend list<T>;
    node();
    node(T t);
    ~node();
    T data;
    node *pPrev;
    node *pNext;
};
//////////////////////////////////////////////////
template <class T>
class list<T>::iterator
{
public:
#ifdef UNIT_TESTING
    friend int ::main(int argc, const char *argv[]);
#endif

    friend list<T>;

    iterator();
    iterator(node* ptr);
    iterator(const iterator &rhs);

    iterator &operator = (const iterator &rhs);
    bool operator != (const iterator &rhs) const;
    bool operator == (const iterator &rhs) const;
    T &operator * ();
    iterator &operator ++ ();
    iterator operator ++ (int postfix);
    iterator &operator -- ();
    iterator operator -- (int postfix);
    node * ptr;

};
} // namespace custom

#include "list.cpp"
#include "iterator.cpp"
#include "node.cpp"

#endif
