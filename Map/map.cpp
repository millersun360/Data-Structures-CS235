#include "map.h"
#include "bst.h"
template <class K, class V>
map<K, V>::map()
{
}

template <class K, class V>
map<K, V>::map(const map<K, V> &rhs)
{
    bst = rhs.bst;
}

template <class K, class V>
map<K, V>::~map()
{
}

template <class K, class V>
map<K, V> &map<K, V>::operator=(const map<K, V> &rhs)
{
    bst = rhs.bst;
    return *this;
}

template <class K, class V>
V &map<K, V>::operator[](const K &key)
{
    pair target(key, V());
    typename BST<map<K, V>::pair>::iterator it = bst.find(target);
    if (it == NULL)
    {
        bst.insert(target);
        it = bst.find(target);
    }
    return (*it).second;
}

template <class K, class V>
int map<K, V>::size() const
{
    return bst.size();
}

template <class K, class V>
bool map<K, V>::empty() const
{
    return bst.empty();
}

template <class K, class V>
void map<K, V>::clear()
{
    bst.clear();
}

template <class K, class V>
void map<K, V>::insert(const K &key, const V &value)
{
    pair target(key, value);
    typename BST<map<K, V>::pair>::iterator it = bst.find(target);
    if (it == NULL)
    {
        bst.insert(target);
    }
}

template <class K, class V>
typename map<K, V>::iterator map<K, V>::find(const K &key)
{
    pair target(key, V());
    typename BST<map<K, V>::pair>::iterator it = bst.find(target);
    return iterator(it);
}

template <class K, class V>
typename map<K, V>::iterator map<K, V>::begin()
{
    typename BST<map<K, V>::pair>::iterator it = bst.begin();
    return iterator(it);
}

template <class K, class V>
typename map<K, V>::iterator map<K, V>::end()
{
    typename BST<map<K, V>::pair>::iterator it = bst.end();
    return iterator(it);
}

//iterator

template <class K, class V>
map<K, V>::iterator::iterator()
{
}
template <class K, class V>
map<K, V>::iterator::iterator(const typename BST<pair>::iterator &rhs)
{
    it = rhs;
}
template <class K, class V>
map<K, V>::iterator::iterator(const iterator &rhs)
{
    it = rhs.it;
}
template <class K, class V>
typename map<K, V>::iterator &map<K, V>::iterator::operator=(const iterator &rhs)
{
    it = rhs.it;
    return *this;
}
template <class K, class V>
bool map<K, V>::iterator::operator!=(const iterator &rhs) const
{
        return it != rhs.it;

}
template <class K, class V>
bool map<K, V>::iterator::operator==(const iterator &rhs) const
{
    return it == rhs.it;
}

template <class K, class V>
typename map<K, V>::pair &map<K, V>::iterator::operator*()
{
    if(it == NULL)
    {
        throw "Error: Dereferencing null node.";
    }
    return *it;
}

template <class K, class V>
typename map<K, V>::iterator &map<K, V>::iterator::operator++()
{
    if(it == NULL)
    {
        throw "Error: Incrementing null node.";
    }
    ++it;
    return *this;
}

template <class K, class V>
typename map<K, V>::iterator map<K, V>::iterator::operator++(int postfix)
{
    if(it == NULL)
    {
        throw "Error: Incrementing null node.";
    }
    return iterator(it++);
}

template <class K, class V>
typename map<K, V>::iterator &map<K, V>::iterator::operator--()
{
  if(it == NULL)
    {
        throw "Error: Decrementing null node.";
    }
    --it;
    return *this;
}

template <class K, class V>
typename map<K, V>::iterator map<K, V>::iterator::operator--(int postfix)
{
        if(it == NULL)
    {
        throw "Error: Decrementing null node.";
    }
    return iterator(it--);
}
