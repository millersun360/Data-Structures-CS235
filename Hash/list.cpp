#include "list.h"

using namespace custom;

/* custom list implementation 
 ******************************************************************************/

template <class T>
list<T>::list()
{
   pHead = NULL;
   pTail = NULL;
   numElements = 0;
}

template <class T>
list<T>::list(const list<T> &rhs)
{
   pHead = NULL;
   pTail = NULL;
   numElements = 0;
   *this = rhs;
}

template <class T>
list<T>::~list()
{
   clear();
}

template <class T>
list<T> &list<T>::operator=(const list<T> &rhs)
{
   clear();
   for (node *p = rhs.pHead; p; p = p->pNext)
      push_back(p->data);
   return *this;
}

template <class T>
int list<T>::size() const
{
   return numElements;
}

template <class T>
bool list<T>::empty() const
{
   return pHead == NULL;
}

template <class T>
void list<T>::clear()
{

   for (node *p = pHead; p;)
   {
      node* pTarget = p;
      p = p->pNext;
      delete pTarget;
      numElements--;
   }
   pHead = NULL;
   pTail = NULL;
}

template <class T>
void list<T>::push_front(const T &t)
{
   insertAt(pHead, t, false);
}

template <class T>
void list<T>::push_back(const T &t)
{
   insertAt(pTail, t, true);
}

template <class T>
void list<T>::pop_front()
{
   if (!empty())
   {
      pHead = pHead->pNext;
      pHead->pPrev = NULL;
      numElements--;
   }
}

template <class T>
void list<T>::pop_back()
{
   if (!empty())
   {
      pTail = pTail->pPrev;
      pTail->pNext = NULL;
      numElements--;
   }
}

template <class T>
T &list<T>::front()
{
   if (!empty())
      return pHead->data;

   else
      throw "Error: Calling front on empty list.";
}

template <class T>
T &list<T>::back()
{
   if (!empty())
      return pTail->data;

   else
      throw "Error: Calling back on empty list.";
}

//Iterator coding********************************************************************

template <class T>
void list<T>::insert(iterator it, T e)
{
   insertAt(it.ptr, e, false);
}

template <class T>
void list<T>::insertAt(node *pCurrent, T element, bool after)
{
   node *pNew = new node(element);

   if (empty())
   {
      pHead = pNew;
      pTail = pNew;
      numElements++;
      return;
   }

   if (after == false) // before
   {
      if (pHead == pCurrent) // the head
         pHead = pNew;       // we have a new head

      pNew->pNext = pCurrent;
      pNew->pPrev = pCurrent->pPrev;
      pCurrent->pPrev = pNew;
      if (pNew->pPrev)
         pNew->pPrev->pNext = pNew;
   }
   if (after == true)
   {
      if (pTail == pCurrent)
         pTail = pNew;
      
      pNew->pPrev = pCurrent;
      pNew->pNext = pCurrent->pNext;
      pCurrent->pNext = pNew;
      if (pNew->pNext)
         pNew->pNext->pPrev = pNew;
   }
   numElements++;
}

template <class T>
typename list<T>::iterator list<T>::find(const T &t)
{
   for (node *p = pHead; p; p = p->pNext)
   {
      if (p->data == t)
         return iterator(p);
   }
   return iterator(NULL);
}

template <class T>
typename list<T>::iterator list<T>::erase(list<T>::iterator it)
{
   node *pMiddle = it.ptr;

   if (pMiddle == NULL)
      return iterator(NULL);

   node *pResult = (pMiddle->pPrev) ? pMiddle->pPrev : pMiddle->pNext;

   if (pMiddle->pPrev)
      pMiddle->pPrev->pNext = pMiddle->pNext;
   if (pMiddle->pNext)
      pMiddle->pNext->pPrev = pMiddle->pPrev;
   if (pMiddle == pHead)
      pHead = pMiddle->pNext;

   delete pMiddle;
   pMiddle = NULL;
   return iterator(pResult);
}

template <class T>
typename list<T>::iterator list<T>::begin()
{
   return iterator(pHead);
}

template <class T>
typename list<T>::iterator list<T>::end()
{
   return iterator(pTail);
}
