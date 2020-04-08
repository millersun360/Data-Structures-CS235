#ifndef MAP_H
#define MAP_H

#ifdef UNIT_TESTING
int main(int argc, const char *argv[]);
#endif
#include "bst.h"
namespace custom
{

template <class K, class V>
class map
{
public:
#ifdef UNIT_TESTING
   friend int ::main(int argc, const char *argv[]);
#endif
   class iterator;
   class pair;
   map();
   map(const map<K, V> &rhs);
   ~map();
   map<K, V> &operator=(const map<K, V> &rhs);
   V &operator[](const K &key);

   int size() const;
   bool empty() const;
   void clear();

   void insert(const K &key, const V &value);
   iterator find(const K &k);

   iterator begin();
   iterator end();

private:
   BST<pair> bst;
};

template <class K, class V>
class map<K, V>::iterator
{
public:
#ifdef UNIT_TESTING
   friend int ::main(int argc, const char *argv[]);
#endif

   friend class map<K, V>;
   iterator();
   iterator(const typename BST<pair>::iterator &rhs);
   iterator(const iterator &rhs);
   iterator &operator=(const iterator &rhs);
   bool operator!=(const iterator &rhs) const;
   bool operator==(const iterator &rhs) const;
   pair &operator*();
   iterator &operator++();
   iterator operator++(int postfix);
   iterator &operator--();
   iterator operator--(int postfix);

private:
   typename BST<pair>::iterator it;
};

/**********************************************
 * PAIR
 ***********************************************/
template <class k, class v>
class map<k, v>::pair
{
public:
   // constructors
   pair() : first(), second() {}
   pair(const k &first, const v &second) : first(first), second(second) {}
   pair(const map<k, v>::pair &rhs) : first(rhs.first), second(rhs.second) {}

   // copy the seconds
   map<k, v>::pair &operator=(const map<k, v>::pair &rhs)
   {
      first = rhs.first;
      second = rhs.second;
      return *this;
   }

   // constant fetchers
   const k &getKey() const { return first; }
   const v &getValue() const { return second; }

   // compare pairs.  Only first will be compared!
   bool operator>(const pair &rhs) const { return first > rhs.first; }
   bool operator>=(const pair &rhs) const { return first >= rhs.first; }
   bool operator<(const pair &rhs) const { return first < rhs.first; }
   bool operator<=(const pair &rhs) const { return first <= rhs.first; }
   bool operator==(const pair &rhs) const { return first == rhs.first; }
   bool operator!=(const pair &rhs) const { return first != rhs.first; }
   // inline std::ostream &operator<<(std::ostream &out, const pair<k, v> &rhs)
   // {
   //    out << '(' << rhs.first << ", " << rhs.second << ')';
   //    return out;
   // }
   // inline std::istream &operator>>(std::istream &in, pair<k, v> &rhs)
   // {
   //    in >> rhs.first >> rhs.second;
   //    return in;
   // }
   // these are public.  We cannot validate!
   k first;
   v second;
};

} // namespace custom

#include "map.cpp"

#endif