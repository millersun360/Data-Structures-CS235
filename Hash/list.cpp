using namespace custom;

template <class T>
list<T>::node::node()
{
    data = 0;
    pNext = NULL;
    pPrev = NULL;
}

template <class T>
list<T>::node::node(const T * t)
{
    data = t;
    pNext = NULL;
    pPrev = NULL;
}

template <class T>
list<T>::list()
{
    pHead = NULL;
    pTail = NULL;
    numElements = 0;
}

template <class T>
list<T>::list(const list<T> & rhs)
{
    *this = rhs;
}

template <class T>
list<T>::~list()
{
    delete();
}

template <class T>
list<T> & list<T>::operator = (const list & rhs)
{

}

template <class T>
int list<T>::size() const
{
    return numElements;
}

template <class T>
bool list<T>::empty()
{
    return pHead = NULL;
}

template <class T>
void list<T>::clear()
{

}

template <class T>
void list<T>::push_back(const T & t)
{

}

template <class T>
void list<T>::push_front(const T & t)
{

}

template <class T>
void list<T>::pop_back()
{

}

template <class T>
void list<T>::pop_front()
{

}

template <class T>
T & list<T>::front()
{
    if (!empty())
        return pHead.data;
    throw "Error: Calling front on empty list.";
}

template <class T>
T & list<T>::back()
{
    if (!empty())
        return pTail.data;
    throw "Error: Calling back on empty list."
}

template <class T>
list<T>::iterator list<T>::find(const T & t)
{

}

template <class T>
void list<T>::erase (iterator it)
{

}

template <class T>
void list<T>::insert (iterator it, const T & t)
{
    node pNew = new node(t);
    if (it != NULL)
    {
        pNew.pNext = it;
        pNew.pPrev = it.pPrev;
        it.pPrev = pNew;
        if (pNew.pPrev)
            pNew.pPrev.pNext = pNew;
    }
    return pNew;
}

template <class T>
list<T>::iterator list<T>::begin()
{
    return iterator(pBegin);
}

template <class T>
list<T>::iterator list<T>::end()
{

}

template <class T>
list<T>::iterator::iterator()
{
    ptr = NULL;
}

template <class T> 
list<T>::iterator::iterator(T * p)
{
    ptr = p;
}

template <class T>
list<T>::iterator::iterator(const iterator & rhs)
{
    ptr = rhs.ptr;
}

template <class T>
typename list<T>::iterator & list<T>::iterator::operator = (const iterator & rhs)
{
    this->ptr = rhs.ptr; 
    return *this;
}

template <class T>
bool list<T>::iterator::operator != (const iterator & rhs) const
{
    return rhs.ptr != this -> ptr;
}

template <class T>
bool list<T>::iterator::operator == (const iterator & rhs) const
{
    return rhs.ptr == this -> ptr;
}

template<class T>
typename list<T>::iterator & list<T>::iterator::operator ++ ()
{
    if (ptr != NULL)
        ptr++;
    return *this;
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator ++ (int postfix)
{
    iterator tmp(*this);
    if (ptr != NULL)
        ptr++;
    return tmp;
}

template<class T>
typename list<T>::iterator & list<T>::iterator::operator -- ()
{
     if (ptr != NULL)
        ptr--;
    return *this;
}

template <class T>
typename list<T>::iterator list<T>::iterator::operator -- (int postfix)
{
    iterator tmp(*this);
    if (ptr != NULL)
        ptr--;
    return tmp;
}

template <class T>
T & list<T>::iterator::operator * ()
{
    return * ptr;
}


