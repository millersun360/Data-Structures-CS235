#include "bst.h"
using namespace custom;

/***************
 1. BST METHODS
****************/
template <class T>
void BST<T>::init() 
{
    root = NULL;
    numElements = 0;
}

template <class T>
BST<T>::BST() {                         // Default Constructor
    init();
}

template <class T>
BST<T>::BST(const BST<T>& rhs) {        // Non-Default Constructor
    *this = rhs;
}

template <class T>
BST<T>::~BST() {                        // Deconstructor
    deleteFrom(root);
}

template <class T>
BST<T>& BST<T>::operator = (const BST<T>& rhs) {    // OPERATOR =
    init();
    root = copyFrom(rhs.root);
    return *this;
}

template <class T>
int BST<T>::size() const {              // GENERAL METHODS
    return numElements;
}

template <class T>
bool BST<T>::empty() const {            
    return (numElements == 0);
}

template <class T>
void BST<T>::clear() {
    deleteFrom(root);
}

template <class T>
void BST<T>::insert(const T& t) {
    root = insertAt(root, t);
}

template <class T>
void BST<T>::erase(iterator it) {
    BNode* pSrc = it.ptr;
    if (pSrc->pLeft == NULL && pSrc->pRight == NULL) {  // If it has no children
        if (pSrc->pParent != NULL) {                    // If is has a parent
            if (pSrc->pParent->pRight == pSrc) {        // If Src = Right of Src's Parent
                pSrc->pParent->pRight = NULL;
            }
            else if (pSrc->pParent->pLeft == pSrc) {
                pSrc->pParent->pLeft = NULL;
            }
        }
    delete pSrc;
    pSrc = NULL;
    numElements--;
    }
    
    else if (pSrc->pRight == NULL) {                    // If it has left child only
        pSrc->pLeft->pParent = pSrc->pParent;           //      Set Src->Left->Parent (Src) = Src->Parent
        if (pSrc->pParent != NULL) {                    //      If Src->Parent not NULL
            if (pSrc->pParent->pRight == pSrc)          //          If Src->Parent->Right = Src
                pSrc->pParent->pRight = pSrc->pLeft;    //              Src->Parent->Right = Src->Left
            else                                        //          if Src->Parent->Right != Src
                pSrc->pParent->pLeft = pSrc->pLeft;     //              Src->Parent->Left = Src->Left
        }
        delete pSrc;
        pSrc = NULL;
        numElements--;
    }

    else if (pSrc->pLeft == NULL) {                     // If it has right child only
        pSrc->pRight->pParent = pSrc->pParent;
        if (pSrc->pParent != NULL) {
            if (pSrc->pParent->pRight == pSrc)
                pSrc->pParent->pRight = pSrc->pRight;
            else
                pSrc->pParent->pLeft = pSrc->pRight;
        }
        delete pSrc;
        pSrc = NULL;
        numElements--;
    }

    else {                                              // If it has both left and right children
        BNode* pSuccessor = minNode(pSrc->pRight);
        // successor out of sub-tree
        if (pSuccessor->pRight)
            pSuccessor->pRight->pParent = pSuccessor->pParent;
            pSuccessor->pParent->pLeft = pSuccessor->pRight;
        
        // unable to target's parent to successor
        pSuccessor->pParent = pSrc->pParent;
        if (pSrc->pParent != NULL) {
            if (pSrc->pParent->pRight == pSrc)
                pSrc->pParent->pRight = pSuccessor;
            else 
                pSrc->pParent->pLeft = pSuccessor;
        }

        // unable to target's children to successor
        pSuccessor->pLeft = pSrc->pLeft;
        pSuccessor->pRight = pSrc->pRight;
        pSrc->pLeft->pParent = pSuccessor;
        pSrc->pRight->pParent = pSuccessor;
        
        // in case that the Successor is root update BST
        if (!pSuccessor->pParent)
            root = pSuccessor;
        delete pSrc;
        numElements--;
    }

}

template <class T>
typename BST<T>::iterator BST<T>::find(const T& t) {
    BNode* found = existsIn(root, t);
    return iterator(found);
    
}

template <class T>
typename BST<T>::iterator BST<T>::begin() {
    BNode* min = minNode(root);
    return iterator(min);
}

template <class T>
typename BST<T>::iterator BST<T>::end() {
    BNode* max = maxNode(root);
    return iterator(max);
}

/***************
All of the helper Methods are here!!!
***********/

// Using pre-order traversal for this function
template <class T>
typename BST<T>::BNode* BST<T>::copyFrom(BNode* pSrc) {
    if (pSrc == NULL)
        return NULL;
    BNode* pDestination = new BNode(pSrc->data);
    numElements++;

    pDestination->pLeft = copyFrom(pSrc->pLeft);
    if (pDestination->pLeft != NULL)
        pDestination->pLeft->pParent = pDestination;
    
    pDestination->pRight = copyFrom(pSrc->pRight);
    if (pDestination->pRight != NULL)
        pDestination->pRight->pParent = pDestination;

    return pDestination;
}

// Using in-order traversal for this function
template <class T>
int BST<T>::sizeOf(BNode* pTree) {
    int count = 0;
    if (pTree == NULL)
        return count;
    count += sizeOf(pTree->pLeft);
    count += 1;
    count += sizeOf(pTree->pRight);
    return count;
}

// Using post-order traversal for this function to delete
template <class T>
void BST<T>::deleteFrom(BNode*& pSrc) {
    if (pSrc == NULL)
        return;
    deleteFrom(pSrc->pLeft);
    deleteFrom(pSrc->pRight);
    delete pSrc;
    pSrc = NULL;
    numElements--;
}

// The least value node is at the left side of the tree. 
template <class T>
typename BST<T>::BNode* BST<T>::minNode(BNode* pSrc) {
    if (pSrc == NULL || pSrc->pLeft == NULL)
        return pSrc;
    return minNode(pSrc->pLeft);
}


// The most value node is at the right side of the tree. 
template <class T>
typename BST<T>::BNode* BST<T>::maxNode(BNode* pSrc) {
    if (pSrc == NULL || pSrc->pRight == NULL)
        return pSrc;
    return maxNode(pSrc->pRight);
}

// Checking for a match in the left and right subtrees from the root 
template <class T>
typename BST<T>::BNode* BST<T>::existsIn(BNode* pSrc, T t) {
    if (pSrc == NULL)
        return NULL;
    if (pSrc->data == t)
        return pSrc;
    if (t < pSrc->data)
        return existsIn(pSrc->pLeft, t);
    else 
        return existsIn(pSrc->pRight, t);
}

// inserting when we find the first NULL position in the left and right subtrees from the root.
template <class T>
typename BST<T>::BNode* BST<T>::insertAt(BNode* pSrc, T t) {
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

/* 2. Implementation */
template <class T>
BST<T>::BNode::BNode() {
    pLeft = NULL;
    pRight = NULL;
    pParent = NULL;
    data = T();
}

template <class T>
BST<T>::BNode::BNode(const T& data) {
    pLeft = NULL;
    pRight = NULL;
    pParent = NULL;
    this->data = data;
}

/* 3. iterator implementation */
template <class T>
BST<T>::iterator::iterator() {
    ptr = NULL;
}

template <class T>
BST<T>::iterator::iterator(BNode * p) {
    this->ptr = p;
}

template <class T>
BST<T>::iterator::iterator(const iterator &rhs) {
    this->ptr = rhs.ptr;
}

template <class T>
typename BST<T>::iterator& BST<T>::iterator::operator=(const iterator & it) {
    this->ptr = it.ptr;
    return *this;
}

template <class T>
bool BST<T>::iterator::operator == (const iterator & rhs) const {
    return rhs.ptr == this->ptr;
}

template <class T>
bool BST<T>::iterator::operator != (const iterator & rhs) const {
    return rhs.ptr != this->ptr;
}

template <class T>
typename BST<T>::iterator& BST<T>::iterator::operator++() {
    if (ptr == NULL)
        throw "Error: incrementing null node.";
    if (ptr->pRight) {
        ptr = ptr->pRight;
            while(ptr->pLeft)
                ptr = ptr->pLeft;
        return *this;
    }
    if (ptr->pParent) {
        if (ptr->pParent->pRight == ptr)
            while(ptr->pParent && ptr->pParent->pRight == ptr)
                ptr = ptr->pParent;
        ptr = ptr->pParent;
    }
    return *this;
}

template<class T>
typename BST<T>::iterator BST<T>::iterator::operator++(int postfix) {
    if (ptr == NULL)
        throw "Error: incrementing null node.";

    iterator tmp(*this);
    if (ptr != NULL)
        ++*this;
    return tmp;
}

template <class T>
typename BST<T>::iterator& BST<T>::iterator::operator--() {
    if (ptr == NULL)
        throw "Error: decrementing null node.";

    if (ptr->pLeft) {
        ptr = ptr->pLeft;
            while(ptr->pRight)
                ptr = ptr->pRight;
        return *this;
    }
    if (!ptr->pLeft) {
        if (ptr->pParent->pLeft == ptr)
            while(ptr->pParent && ptr->pParent->pLeft == ptr)
                ptr = ptr->pParent;
        ptr = ptr->pParent;
    }
    return *this;
}

template <class T>
typename BST<T>::iterator BST<T>::iterator::operator--(int postfix) {
    if (ptr == NULL)
        throw "Error: decrementing null node.";

    iterator tmp(*this);
    if (ptr != NULL)
        --*this;
    return tmp;
}

template <class T>
T& BST<T>::iterator::operator*() {
    if (ptr == NULL)
        throw "Error: dereferencing null node.";
    return ptr->data;
}






