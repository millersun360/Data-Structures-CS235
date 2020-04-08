#include "list.h"

using namespace custom;

template <class T>
list<T>::node::node()
{
   data = T();
   pPrev = NULL;
   pNext = NULL;
}

template <class T>
list<T>::node::node(T t)
{
   data = t;
   pPrev = NULL;
   pNext = NULL;
}

template <class T>
list<T>::node::~node()
{
    unit_testing_delete_call_counter++;
}
