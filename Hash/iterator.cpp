#include "list.h"

using namespace custom;

template <class T>
list<T>::iterator::iterator()
{
    ptr = NULL;
}

template <class T>
list<T>::iterator::iterator(node *aNode)
{
    ptr = aNode;
}

template <class T>
list<T>::iterator::iterator(const iterator &rhs)
{
    *this = rhs;
}

template <class T>
typename list<T>::iterator &list<T>::iterator::operator=(const iterator &rhs)
{
    ptr = rhs.ptr;
    return *this;
}

template <class T>
bool list<T>::iterator::operator!=(const iterator &rhs) const
{
    return ptr != rhs.ptr;
}

template <class T>
bool list<T>::iterator::operator==(const iterator &rhs) const
{
    return ptr == rhs.ptr;
}

template <class T>
T &list<T>::iterator::operator*()
{
    if (ptr == NULL)
        throw "Error: Dereferencing null node.";
    return ptr->data;
}

template <class T>
typename list<T>::iterator &list<T>::iterator::operator++()
{
    if (ptr == NULL)
        throw "Error: Incrementing null node.";
    if (ptr->pNext)
        ptr = ptr->pNext;
    return *this;
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator++(int postfix)
{
    iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <class T>
typename list<T>::iterator &list<T>::iterator::operator -- ()
{
    if (ptr == NULL)
        throw "Error: Decrementing null node.";
    if (ptr->pPrev)
        ptr = ptr->pPrev;
    return *this;
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator -- (int postfix)
{
    iterator tmp = *this;
    if (ptr == NULL)
        throw "Error: Decrementing null node.";
    if (ptr->pPrev)
        ptr = ptr->pPrev;
    return tmp;
}
