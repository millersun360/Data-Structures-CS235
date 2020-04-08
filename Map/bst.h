#ifndef BST_H
#define BST_H

#ifdef UNIT_TESTING
int main(int argc, const char* argv[]);
#endif

namespace custom
{
   /**
    * A custom binary search tree implementation to satisfy CS235 unit tests for
    * week 09. While this version of the BST class satisfies the BST constraint
    * it is not self-balancing. As a result, some operations could take as long
    * as O(n) depending on the organization of the underlying nodes.
    */
   template <class T>
   class BST
   {
      public:

         #ifdef UNIT_TESTING
         friend int ::main(int argc, const char* argv[]);
         #endif

         class BNode;
         class iterator;

         BST();
         BST(const BST<T>& rhs);
         ~BST();
         BST<T>& operator = (const BST<T>& rhs);

         int size() const;
         bool empty() const;
         void clear();
         void insert(const T& t);
         void erase(iterator it);
         iterator find(const T& t);
         
         iterator begin();
         iterator end();

      private:
         void init();

         // recursive helper methods
         BNode* copyFrom(BNode* pSrc);
         int sizeOf(BNode* pTree);
         void deleteFrom(BNode*& pSrc);
         BNode* minNode(BNode* pSrc);
         BNode* maxNode(BNode* pSrc);
         BNode* existsIn(BNode* pSrc, T t);
         BNode* insertAt(BNode* pSrc, T t);
         
         BNode* root;
         int numElements;
      
   };

   template <class T>
   class BST<T>::BNode
   {
      public:
         BNode();
         BNode(const T& data);
            
         T data;
         BNode* pLeft;
         BNode* pRight;
         BNode* pParent;
   };

   template <class T>
   class BST<T>::iterator
   {
      public:
         
         #ifdef UNIT_TESTING
         friend int ::main(int argc, const char* argv[]);
         #endif

         friend class BST<T>;
         
         iterator();
         iterator(BNode* p);
         iterator(const iterator& rhs);
         iterator & operator = (const iterator& rhs);
         bool operator != (const iterator& rhs) const;
         bool operator == (const iterator& rhs) const;
         T& operator * ();
         iterator& operator ++ ();
         iterator operator ++ (int postfix);
         iterator& operator -- ();
         iterator operator -- (int postfix);
         
      private:
         
         BNode* ptr;
   
   };

}

#include "bst.cpp"

#endif 