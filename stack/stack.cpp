#include <cstddef>
using namespace custom;

template <class T>
stack <T>::stack()
{
    numCapacity = 0;
    numElements = 0;
    buffer = NULL;
}

template <class T>
stack<T>::stack(int numElements)
{
    if (numElements <= 0)
        throw "Error: stack sizes must be greater than 0.";

    this->numCapacity = numElements;
    this->numElements = numElements;
    this->buffer = new T[numElements];
    for (int i = 0; i < numElements; i++)
        this->buffer[i] = T(); 
}

template <class T>
stack<T>::stack(int numElements, const T & t)
{
    if (numElements <= 0)
        throw "Error: stack sizes must be greater than 0.";

    this->numCapacity = numElements;
    this->numElements = numElements;
    this->buffer = new T[numElements];
    for(int i = 0; i < numElements; i++)
        this->buffer[i] = t;
}


template <class T>
stack<T>::stack(const stack<T> & rhs)
{
    *this = rhs;
}

template <class T>
stack<T>::~stack()
{
    delete [] buffer;
} 

template <class T>
stack<T> & stack<T>::operator=(const stack<T> & rhs)
{
    numCapacity = rhs.numElements;
    numElements = rhs.numElements;
    buffer = new T[rhs.numElements];
    for(int i = 0; i < rhs.numElements; i++)
        buffer[i] = rhs.buffer[i];
    return *this;
} 

template <class T>
int stack<T>::size() const
{
    return numElements;
}

template <class T>
int stack<T>::capacity()
{
    return numCapacity;
}

template <class T>
bool stack<T>::empty()
{
    if(numElements == 0)
        return true;
    else
        return false;
    
}

template <class T>
void stack<T>::clear()
{
    numElements = 0;
}

template <class T>
void stack<T>::push(const T & t)
{
    if(numElements == numCapacity) 
        resize((numCapacity == 0) ? 1 : numCapacity * 2); // find another way to do this 
    buffer[numElements++] = t; 
}

template <class T>
void stack<T>::pop()
{
    if(!empty())
        --numElements;
}

template <class T>
T & stack<T>::top()
{
    if(empty())
        throw "Error: asking for top of empty stack.";
    return buffer[numElements - 1];
    
}

template <class T>
void stack<T>::resize(int newCapacity) //RENAME NEWCAPACITY
{
    if (newCapacity == 0)
    {
        numCapacity = 0;
        numElements = 0;
        buffer = NULL;
    }

    if (newCapacity > 0)
    {
        T * newBuffer = new T[newCapacity];
        if (newCapacity < numElements)
            numElements = newCapacity;
        for (int i = 0; i < numElements; i++)
            newBuffer[i] = buffer[i];
        delete [] buffer;
        buffer = newBuffer;
        numCapacity = newCapacity;
    }
}