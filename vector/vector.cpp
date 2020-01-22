#include "vector.h"

/*

VECTOR CLASS

*/

template <class T>
vector <T> :: vector() //default constructor
{
    numElements = 0;
    numCapacity = 0;
}

template <class T>
vector <T> :: vector(int numElements)
{
    this -> numCapacity = numElements; // see resize
}

template <class T>
vector <T> :: vector(int numElements, const T & t)
{
    this -> numCapacity = numElements;
    for(int i = 0; i <= numElements; i++) //fill it!
        buffer[i] = t;
}

template <class T>
vector <T> :: ~vector()
{
    delete[] buffer;
}

template <class T>
vector <T> :: vector(const vector <T> & rhs)
{
    for(int i = 0; i <= numElements; i++) 
        buffer[i] = rhs.buffer[i];
}

template <class T>
void vector <T> :: resize (int numCapacity)
{
    if(numElements == 1 && numCapacity == 0)
    {
        numCapacity = 1;
    }
    else
    {    
        numCapacity *= 2;
    }
    //create a copied vector but with double the capacity
    const vector <T> rhs = vector(numCapacity); 
    //fill it in with the values of the previous vector
    vector(const vector <T> & rhs); //check to see if this is right
}

template <class T>
custom :: vector <T> & vector <T> :: operator = (const vector & rhs)
{    
    this -> numElements = rhs.numElements;  //
    this -> numCapacity = rhs.numCapacity;  // Verify
    this -> buffer = rhs.buffer;            //
}

template <class T>
int custom :: vector <T> :: size()
{
    return numElements;
}

template <class T>
int custom :: vector <T> :: capacity()
{
    return numCapacity;
}

template <class T>
bool custom :: vector <T> :: empty()
{
    if (numElements == 0)
        return true;
    else
        return false;
}

template <class T>
void custom :: vector <T> :: clear()
{
    //remove elements?
    numElements = 0;
}

template <class T>
void custom :: vector <T> :: push_back(const T & t)
{
//add one element, if capacity is full, resize. 
    numElements++;
    if(numElements >= numCapacity) 
    resize(numCapacity); 
    buffer[numElements] = t; //put in the new element
}

template <class T>
T & vector <T> :: operator [] (int index)
{
    return buffer[index];
}

template <class T>
typename custom :: vector <T> :: iterator vector<T>::begin()
{
    return buffer.begin() const;
}

template <class T>
typename custom :: vector <T> :: iterator vector <T> :: end()
{
    return buffer.end() const;
}

/*

ITERATOR CLASS

*/

template <class T>
custom :: vector <T> :: iterator :: iterator()
{
    ptr = null;
}

template <class T> 
custom :: vector <T> :: iterator :: iterator(T * p)
{
    ptr = p;
}

template <class T>
custom :: vector <T> :: iterator :: iterator(const iterator & rhs)
{
    this -> p = rhs;
}

template <class T>
typename custom :: vector <T> :: iterator & vector <T> :: iterator :: operator = (const iterator & rhs)
{
    return rhs;
}

template <class T>
bool vector <T> :: iterator :: operator != (const iterator & rhs) const
{
    return rhs.ptr != this -> ptr;
}

template <class T>
bool vector <T> :: iterator :: operator == (const iterator & rhs) const
{
    return rhs.ptr == this -> ptr;
}

template<class T>
typename custom :: vector <T> :: iterator & vector<T> :: iterator :: operator ++ ()
{
    return ptr++;
}

template <class T>
typename custom :: vector <T> :: iterator vector <T> :: iterator :: operator ++ (int postfix)
{
    return ++postfix;
}

template<class T>
typename custom :: vector <T> :: iterator & vector<T> :: iterator :: operator -- ()
{
    return ptr--;
}

template <class T>
typename custom :: vector <T> :: iterator vector <T> :: iterator :: operator -- (int postfix)
{
    return --postifx;
}

template <class T>
T & vector <T> :: iterator :: operator * ()
{
    return * ptr;
}






