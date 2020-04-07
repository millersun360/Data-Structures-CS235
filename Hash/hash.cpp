using namespace custom;

template <class T>
Hash<T>::Hash(int newNumBuckets)
{
    if (numBuckets <= 0)
        throw "Error: Hashes must have at least 1 bucket.";
    numBuckets = newNumBuckets;
    numElements = 0;
    table = new list<T>*[numBuckets];
    for (int i = 0; i < numBuckets; i++)
        table[i] = new list<T>();
}

template <class T>
Hash<T>::Hash(Hash<T> & rhs)
{
    numElements = 0;
    numBuckets = 0;
    table = NULL;
    *this = rhs;
}

template <class T>
Hash<T>::~Hash()
{
    for (int i = 0; i < numBuckets; i++)
    {
        delete table[i];
        table[i] = NULL;
    }
}

template <class T>
Hash<T> & Hash<T>::operator = (const Hash<T> & rhs)
{
    for (int i = 0; i < numBuckets; i++)
    {
        delete table[i];
        table[i] = NULL;
    }
    delete [] table;

    numBuckets = rhs.numBuckets;
    numElements = rhs.numElements;

    table = new list<T>*[rhs.numBuckets];
    for (int i = 0; i < rhs.numBuckets; i++)
    {
        list<T> temp = *(rhs.table[i]);
        table[i] = new list<T>(temp);
    }

    return *this;
}

template<class T>
int Hash<T>::size()
{
    return numElements;
}

template <class T>
int Hash<T>::capacity()
{
    return numBuckets;
}

template <class T>
bool Hash<T>::empty()
{
    return (numElements == 0);
}

template <class T>
bool Hash<T>::find(T aValue, long (*h)(const T& aValue, long theBucketCount))
{
    long bucket = h(aValue, numBuckets);
    typename list<T>::iterator found = table[bucket]->find(aValue);
    return (found != NULL);
}

template <class T>
void Hash<T>::insert(T aValue, long (*h)(const T& aValue, long theBucketCount))
{
    long bucket = h(aValue, numBuckets);
    table[bucket]->push_back(aValue);
    numElements++
}
