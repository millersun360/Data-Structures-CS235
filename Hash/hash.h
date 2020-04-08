

#ifndef HASH_H
#define HASH_H

#include "list.h"

#ifdef UNIT_TESTING
int main(int argc, const char *argv[]);
#endif

namespace custom
{

/*
    * Custom implementation of list.
    */
template <class T>
class Hash
{

public:
#ifdef UNIT_TESTING
   friend int ::main(int argc, const char *argv[]);
#endif

  //Constructor
  Hash();
  Hash(int numBuckets);
  ~Hash();
  Hash<T>& operator =(const Hash<T>& rhs);
  int size();
  int capacity();
  bool empty();
  bool find(T t, long (*h)(const T& aValue, long theBucketCount));
  void insert(T t, long (*h)(const T& aValue, long theBucketCount));



private:
list<T> ** table;
int numElements;
int numBuckets;



};




}; // namespace custom

#include "Hash.cpp"

#endif