using namespace custom;
/********************************************************************************************************************************
* MAP CLASS
*********************************************************************************************************************************/
template<class K, class V>
map<K, V>::map() //uses default constructor of BST
{
   bst();
}

template<class K, class V>
map<K, V>::map(const map<K, V> & map)
{
    bst = map.bst;
}

template<class K, class V>
map<K, V>::~map()
{
    clear();
}

template<class K, class V>
map<K,V> & map<K, V>::operator = (const map<K,V> & rhs)
{
    bst = rhs.bst;
    return this;
}

template<class K, class V>
int map<K, V>::size()
{
    return bst.size();
}

template<class K, class V>
bool map<K, V>::empty()
{
    return bst.empty();
}

template<class K, class V>
void map<K, V>::clear()
{
   return bst.clear();
}

template<class K, class V>
void map<K, V>::insert(pair) //not sure if pair is right
{
    it = bst.find(pair);
    if(it != NULL)
      *it = pair;
   else
      bst.insert(pair);
}

template<class K, class V>
map<K, V>::iterator map<K, V>::find(const K & key)
{
    bst.find(key);
}

template<class K, class V>
map<K, V>::iterator map<K, V>::begin()
{
    return bst.begin();
}

template<class K, class V>
map<K, V>::iterator map<K, V>::end()
{
    return bst.end();
}

/********************************************************************************************************************************
* MAP ITERATOR CLASS : All the Map Iterator methods simply call the comparable bst iterator methods
*********************************************************************************************************************************/

// BST::iterator will be created when a map::iterator is created and
// the BST::iterator will be destroyed when the map::iterator is destroyed

template <class K, class V>
map<K, V>::iterator::iterator()
{

}

template <class K, class V>
map<K, V>::iterator::iterator(const BST<pair>::iterator & rhs)
{
    it = rhs.it;
}

template <class K, class V>
map<K, V>::iterator::iterator(const iterator & rhs)
{
    it = rhs.it;
}

template <class K, class V>
typename map<K, V>::iterator & map<K, V>::iterator::operator = (const iterator & rhs)
{
    this->it = rhs.it; 
    return *this;
}

template <class K, class V>
bool map<K, V>::iterator::operator == (const iterator & rhs) const
{
    return rhs.it == this -> it;
}

template <class K, class V>
bool map<K, V>::iterator::operator != (const iterator & rhs) const
{
    return rhs.it != this -> it;
}

template<class K, class V>
typename map<K, V>::iterator & map<K, V>::iterator::operator ++ ()
{
    return ++it;
}

template<class K, class V>
typename map<K, V>::iterator & map<K, V>::iterator::operator -- ()
{
    return --it;
}

template<class K, class V>
T & map<K, V>::iterator::operator * ()
{
   if(ptr == NULL)
      throw "Error: dereferencing null node.";
	return ptr->data;
}

/********************************************************************************************************************************
* PAIR CLASS
*********************************************************************************************************************************/
template <class K, class V>
map<K, V>::pair::pair()
{

}

template <class K, class V>
map<K, V>::pair::pair(const K & key, const V & value)
{
   first = key;
   second = value;
}

template <class K, class V>
bool map<K, V>::pair::operator = (const pair  & rhs) const
{
   first = rhs.first;
   second = rhs.second;
}

template <class K, class V>
bool map<K, V>::pair::operator == (const pair & rhs) const
{
   if (first == rhs.first && second == rhs.second)
      return true;
   else
      return false;
}

template <class K, class V>
bool map<K, V>::pair::operator > (const pair & rhs) const
{
   if (first > rhs.first && second > rhs.second)
      return true;
   else
      return false;
}

template <class K, class V>
bool map<K, V>::pair::operator < (const pair & rhs) const
{
   if (first < rhs.first && second < rhs.second)
      return true;
   else
      return false;
}

template <class K, class V>
bool map<K, V>::pair::operator >= (const pair & rhs) const
{
   if (first >= rhs.first && second >= rhs.second)
      return true;
   else
      return false;
}

template <class K, class V>
bool map<K, V>::pair::operator <= (const pair & rhs) const
{
   if (first <= rhs.first && second <= rhs.second)
      return true;
   else
      return false;
}

