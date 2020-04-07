using namespace custom;

//NODE CLASS
template<class T>
BST<T>::BNode::BNode()
{
    pLeft = NULL;
    pRight = NULL;
    pParent = NULL;
}

template<class T>
BST<T>::BNode::BNode(const T & t)
{
    data = t;
    pLeft = NULL;
    pRight = NULL;
    pParent = NULL;
}

template <class T>
typename BST<T>::BNode* BST<T>::copyFrom(BNode* pSrc)
{
   if (pSrc == NULL)
      return NULL;
   
   BNode* pDestination = new BNode(pSrc->data);
   numElements++; // V

   pDestination->pLeft = copyFrom(pSrc->pLeft); // L
   if (pDestination->pLeft != NULL)
      pDestination->pLeft->pParent = pDestination;

   pDestination->pRight = copyFrom(pSrc->pRight); // R
   if (pDestination->pRight != NULL)
      pDestination->pRight->pParent = pDestination;

   return pDestination;
}

template <class T>
void BST<T>::deleteFrom(BNode*& pSrc)
{
   if (pSrc == NULL)
      return;

   deleteFrom(pSrc->pLeft); // L
   deleteFrom(pSrc->pRight); // R
   delete pSrc; // V
   pSrc = NULL;
   numElements--;
}

template <class T>
typename BST<T>::BNode* BST<T>::minNode(BNode* pSrc)
{
   if (pSrc == NULL || pSrc->pLeft == NULL) 
      return pSrc; 
   return minNode(pSrc->pLeft); 
}

template <class T>
typename BST<T>::BNode* BST<T>::maxNode(BNode* pSrc)
{
   if (pSrc == NULL || pSrc->pRight == NULL) 
      return pSrc; 
   return maxNode(pSrc->pRight); 
}

template <class T>
typename BST<T>::BNode* BST<T>::existsIn(BNode* pSrc, T t)
{
   if (pSrc == NULL) 
      return NULL; 

   if (pSrc->data == t) 
      return pSrc;

   if (t < pSrc->data) 
      return existsIn(pSrc->pLeft, t);
   else
      return existsIn(pSrc->pRight, t);
}

template <class T>
typename BST<T>::BNode* BST<T>::insertAt(BNode* pSrc, T t)
{
   if (pSrc == NULL) 
   {
      numElements++;
      return new BNode(t);
   }
   if (t < pSrc->data) 
   {
      BNode* pChild = insertAt(pSrc->pLeft, t); 
      pSrc->pLeft = pChild;
      pChild->pParent = pSrc;
   }
   else
   {
      BNode* pChild = insertAt(pSrc->pRight, t); 
      pSrc->pRight = pChild;
      pChild->pParent = pSrc;
   }
   return pSrc;
}      

// BINARY SEARCH TREE CLASS
template<class T>
BST<T>::BST()
{
    root = NULL;
    numElements = 0;
}

template<class T>
int BST<T>::size() const
{
    return numElements;
}

template<class T>
bool BST<T>::empty() const
{
    return (numElements == 0);  
}

template<class T>
BST<T>::BST(const BST<T> & rhs) 
{
    *this = rhs;
}

template<class T>
BST<T>::~BST()
{
    deleteFrom(root);
}

template<class T>
BST<T> & BST<T>::operator = (const BST<T> & rhs)
{
    root = NULL;
    numElements = 0;
    root = copyFrom(rhs.root);
    return *this;
}

template<class T>
void BST<T>::clear()
{
    deleteFrom(root);
}

template<class T>
void BST<T>::insert(const T & t)
{
    root = insertAt(root, t);
}

template<class T>
void BST<T>::erase(iterator it)
{
BNode* pSrc = it.ptr;

   // case 1: has no children (a leaf node)
   if (pSrc->pLeft == NULL && pSrc->pRight == NULL)
   {
      if (pSrc->pParent != NULL)
      {
         // update parent node pointers
         if (pSrc->pParent->pRight == pSrc)
			   pSrc->pParent->pRight = NULL;
		   else if (pSrc->pParent->pLeft == pSrc)
			   pSrc->pParent->pLeft = NULL;
      }

      delete pSrc;
      pSrc = NULL;
      numElements--;
   }
   // case 2: has left child only
   else if (pSrc->pRight == NULL)
   {
      // update left node's parent to my parent (null or not is ok)
      pSrc->pLeft->pParent = pSrc->pParent;

      // update parent node pointers
      if (pSrc->pParent != NULL)
      {
         if (pSrc->pParent->pRight == pSrc)
			   pSrc->pParent->pRight = pSrc->pLeft;
		   else
			   pSrc->pParent->pLeft = pSrc->pLeft;
      }

      delete pSrc;
      pSrc = NULL;
      numElements--;
   }
   // case 3: has right child only
   else if (pSrc->pLeft == NULL)
   {
      // update right node's parent to my parent (null or not is ok)
      pSrc->pRight->pParent = pSrc->pParent;

      // update parent node pointers
		if (pSrc->pParent != NULL)
      {
         if (pSrc->pParent->pRight == pSrc)
			   pSrc->pParent->pRight = pSrc->pRight;
		   else
			   pSrc->pParent->pLeft = pSrc->pRight;
      }

      delete pSrc;
      pSrc = NULL;
      numElements--;
   }
   // case 4: has left and right children
   else
   {
      BNode* pSuccessor = minNode(pSrc->pRight); 

      // strip successor out of sub-tree and reassign parent node pointers
      if (pSuccessor->pRight)
		   pSuccessor->pRight->pParent = pSuccessor->pParent;
		pSuccessor->pParent->pLeft = pSuccessor->pRight;

      // connect successor to target's parent
      pSuccessor->pParent = pSrc->pParent;

      // update target's parent's node pointers
      if (pSrc->pParent != NULL)
      {
         if (pSrc->pParent->pRight == pSrc)
			   pSrc->pParent->pRight = pSuccessor;
		   else
			   pSrc->pParent->pLeft = pSuccessor;
      }
      
      // connect target's children to successor
      pSuccessor->pLeft = pSrc->pLeft;
		pSuccessor->pRight = pSrc->pRight;
      pSrc->pLeft->pParent = pSuccessor;
		pSrc->pRight->pParent = pSuccessor;
      
      // if successor is root update BST
      if (!pSuccessor->pParent)
         root = pSuccessor;

      delete pSrc;
      pSrc = NULL;
      numElements--;
   } 
}

template<class T>
typename BST<T>::iterator BST<T>::find(const T & t)
{
   BNode* found = existsIn(root, t);
   return iterator(found);
}

template<class T>
typename BST<T>::iterator BST<T>::begin()
{
   BNode* min = minNode(root);
   return iterator(min);
}

template<class T>
typename BST<T>::iterator BST<T>::end()
{
   BNode* max = maxNode(root);
   return iterator(max);
}

//ITERATOR CLASS

template <class T>
BST<T>::iterator::iterator()
{
    ptr = NULL;
}

template <class T> 
BST<T>::iterator::iterator(BNode * p)
{
    ptr = p;
}

template <class T>
BST<T>::iterator::iterator(const iterator & rhs)
{
    ptr = rhs.ptr;
}

template <class T>
typename BST<T>::iterator & BST<T>::iterator::operator = (const iterator & rhs)
{
    this->ptr = rhs.ptr; 
    return *this;
}

template <class T>
bool BST<T>::iterator::operator != (const iterator & rhs) const
{
    return rhs.ptr != this -> ptr;
}

template <class T>
bool BST<T>::iterator::operator == (const iterator & rhs) const
{
    return rhs.ptr == this -> ptr;
}

template<class T>
typename BST<T>::iterator & BST<T>::iterator::operator ++ ()
{
   if (ptr == NULL)
      throw "Error: incrementing null node.";
   
   if (ptr->pRight)
   {
      ptr = ptr->pRight;
		while(ptr->pLeft)
			ptr = ptr->pLeft;
      return *this;
   }

   if (ptr->pParent)
   {
      if (ptr->pParent->pLeft == ptr)
         ptr = ptr->pParent;
      else
      {
         while(ptr->pParent && ptr->pParent->pRight == ptr)
            ptr = ptr->pParent;
         ptr = ptr->pParent;
      }
   }
   return *this;
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::operator ++ (int postfix)
{
   if (ptr == NULL)
      throw "Error: incrementing null node.";
  
   iterator tmp(*this);
   if (ptr != NULL) 
      ++*this;
   return tmp;
}

template<class T>
typename BST<T>::iterator & BST<T>::iterator::operator -- ()
{
 if (ptr == NULL)
      throw "Error: decrementing null node.";

   if (ptr->pLeft) { 
      ptr = ptr->pLeft; 
      while (ptr->pRight) 
         ptr = ptr->pRight; 
      return *this;
   }
   
   if (!ptr->pLeft)
   {
      if (ptr->pParent->pLeft == ptr)
         while(ptr->pParent && ptr->pParent->pLeft == ptr)
            ptr = ptr->pParent;
      ptr = ptr->pParent;
   }
   return *this;

}

template <class T>
typename BST<T>::iterator BST<T>::iterator::operator -- (int postfix)
{
   if (ptr == NULL)
      throw "Error: decrementing null node.";

   iterator tmp(*this);
   if (ptr != NULL)
      --*this;
   return tmp;
}

template <class T>
T & BST<T>::iterator::operator * ()
{
   if(ptr == NULL)
      throw "Error: dereferencing null node.";
	return ptr->data;
}


