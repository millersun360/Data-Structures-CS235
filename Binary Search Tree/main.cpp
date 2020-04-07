/*
 * main.cpp
 *
 *  Created by Lee Barney on 11/1/18.
 *  Copyright (c) 2018 Lee Barney
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

/* !!!!GRADING INSTRUCTIONS!!!!
 *
 * When you report your score for this test set, report
 * the percentage of asserts found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING
//Do not change the next line without instructor approval.
//To do so is cheating and, when found, will result in consequences.
int asserts_existing = 397;

#include <cstring>
#include "unit_testing.h"
#include "bst.h"


using namespace custom;

int main(int argc, const char * argv[]) {
    
    /*
     * Testing default node constructor
     */
    startTestSet("Default Node Constructor");
    BST<int>::BNode defaultNode;
    assertTrue(defaultNode.pLeft == NULL,__LINE__);
    assertTrue(defaultNode.pRight == NULL,__LINE__);
    assertTrue(defaultNode.pParent == NULL,__LINE__);
    
    /*
     * Testing node constructor with data
     */
    startTestSet("Non-Default Node Constructor");
    BST<int>::BNode dataNode(4);
    assertTrue(dataNode.data == 4,__LINE__);
    assertTrue(dataNode.pLeft == NULL,__LINE__);
    assertTrue(dataNode.pRight == NULL,__LINE__);
    assertTrue(dataNode.pParent == NULL,__LINE__);
    
    /*
     * Testing node destructor
     */
    startTestSet("Node Destructor");
    unit_testing_delete_call_counter = 0;
    BST<int>::BNode* nodeToDelete = new BST<int>::BNode();
    delete nodeToDelete;
    assertTrue(unit_testing_delete_call_counter == 1,__LINE__);
    //When done with a pointer set it to NULL so you don't create a zombie pointer.
    nodeToDelete = NULL;
    
    
    /*
     * Testing default BST constructor
     */
    startTestSet("Default BST Constructor");
    BST <int> defaultBST;
    assertTrue(defaultBST.root == NULL,__LINE__);
    assertTrue(defaultBST.numElements == 0,__LINE__);
    
    
    /*
     * Testing size and empty
     */
    startTestSet("Size and Empty");
    BST<int> sizedTree;
    sizedTree.numElements = 0;
    assertTrue(sizedTree.size() == 0,__LINE__);
    assertTrue(sizedTree.empty(),__LINE__);
    sizedTree.numElements = 32;
    assertTrue(sizedTree.size() == 32,__LINE__);
    assertTrue(!sizedTree.empty(),__LINE__);
    
    /*
     * Testing BST copy constructor
     */
    startTestSet("BST Copy Constructor");
    BST<int> bstToCopy;
    bstToCopy.numElements = 0;
    bstToCopy.root = NULL;
    
    //testing copy of empty list
    BST<int>emptyBstCopy(bstToCopy);
    assertTrue(emptyBstCopy.numElements == 0,__LINE__);
    assertTrue(emptyBstCopy.root == NULL,__LINE__);
    
    //Generating small BST with the values                              |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6        ------10------
    //                                                       |             |             |
    //                                                       5             9             11
    
    //reusing bstToCopy
    bstToCopy.numElements = 6;
    bstToCopy.root = new BST<int>::BNode();
    bstToCopy.root->data = 7;
    
    BST<int>::BNode* rootRight = new BST<int>::BNode();
    rootRight->data = 10;
    rootRight->pParent = bstToCopy.root;
    bstToCopy.root->pRight = rootRight;
    
    BST<int>::BNode* rootRightRight = new BST<int>::BNode();
    rootRightRight->data = 11;
    rootRightRight->pParent = rootRight;
    rootRight->pRight = rootRightRight;
    
    BST<int>::BNode* rootRightLeft = new BST<int>::BNode();
    rootRightLeft->data = 9;
    rootRightLeft->pParent = rootRight;
    rootRight->pLeft = rootRightLeft;
    
    BST<int>::BNode* rootLeft = new BST<int>::BNode();
    rootLeft->data = 6;
    rootLeft->pRight = NULL;
    rootLeft->pParent = bstToCopy.root;
    bstToCopy.root->pLeft = rootLeft;
    
    
    BST<int>::BNode* rootLeftLeft = new BST<int>::BNode();
    rootLeftLeft->data = 5;
    rootLeftLeft->pRight = NULL;
    rootLeftLeft->pLeft = NULL;
    rootLeftLeft->pParent = rootLeft;
    rootLeft->pLeft = rootLeftLeft;
    
    //testing copy of non-empty tree. Making sure it is a deep copy.
    //Using BST                                                         |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6---     ------10------
    //                                                       |             |             |
    //                                                       5             9             11
    BST<int> bstCopy(bstToCopy);
    assertTrue(bstCopy.root != NULL,__LINE__);
    assertTrue(bstCopy.root != bstToCopy.root,__LINE__);
    assertTrue(bstCopy.root->data == 7,__LINE__);
    assertTrue(bstCopy.numElements == 6,__LINE__);
    
    assertTrue(bstCopy.root->pLeft != NULL,__LINE__);
    assertTrue(bstCopy.root->pLeft != bstToCopy.root->pLeft,__LINE__);
    assertTrue(bstCopy.root->pLeft->data == 6,__LINE__);
    assertTrue(bstCopy.root->pLeft->pRight == NULL,__LINE__);
    
    assertTrue(bstCopy.root->pLeft->pLeft != NULL,__LINE__);
    assertTrue(bstCopy.root->pLeft->pLeft != bstToCopy.root->pLeft->pLeft,__LINE__);
    assertTrue(bstCopy.root->pLeft->pLeft->data == 5,__LINE__);
    assertTrue(bstCopy.root->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(bstCopy.root->pLeft->pLeft->pLeft == NULL,__LINE__);
    
    assertTrue(bstCopy.root->pRight != NULL,__LINE__);
    assertTrue(bstCopy.root->pRight != bstToCopy.root->pRight,__LINE__);
    assertTrue(bstCopy.root->pRight->data == 10,__LINE__);
    
    assertTrue(bstCopy.root->pRight->pLeft != NULL,__LINE__);
    assertTrue(bstCopy.root->pRight->pLeft != bstToCopy.root->pRight->pLeft,__LINE__);
    assertTrue(bstCopy.root->pRight->pLeft->data == 9,__LINE__);
    assertTrue(bstCopy.root->pRight->pLeft->pLeft == NULL,__LINE__);
    assertTrue(bstCopy.root->pRight->pLeft->pRight == NULL,__LINE__);
    
    assertTrue(bstCopy.root->pRight->pRight != NULL,__LINE__);
    assertTrue(bstCopy.root->pRight->pRight != bstToCopy.root->pRight->pLeft,__LINE__);
    assertTrue(bstCopy.root->pRight->pRight->data == 11,__LINE__);
    assertTrue(bstCopy.root->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(bstCopy.root->pRight->pRight->pRight == NULL,__LINE__);
    
    
    /*
     * Testing BST Clear
     */
    startTestSet("BST Clear");
    BST<int> bstToClear;
    //Generating small BST with the values                              |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6---     ------10------
    //                                                       |             |             |
    //                                                       5             9             11
    
    bstToClear.root = new BST<int>::BNode();
    bstToClear.root->data = 7;
    
    BST<int>::BNode* clearRootRight = new BST<int>::BNode();
    clearRootRight->data = 10;
    clearRootRight->pParent = bstToClear.root;//(7)
    bstToClear.root->pRight = clearRootRight;//(10)
    
    BST<int>::BNode* clearRootRightRight = new BST<int>::BNode();
    clearRootRightRight->data = 11;
    clearRootRightRight->pParent = clearRootRight;//(10)
    clearRootRight->pRight = clearRootRightRight;//(11)
    
    BST<int>::BNode* clearRootRightLeft = new BST<int>::BNode();
    clearRootRightLeft->data = 9;
    clearRootRightLeft->pParent = clearRootRight;//(10)
    clearRootRight->pLeft = clearRootRightLeft;//(9)
    
    BST<int>::BNode* clearRootLeft = new BST<int>::BNode();
    clearRootLeft->data = 6;
    clearRootLeft->pRight = NULL;
    clearRootLeft->pParent = bstToClear.root;//(7)
    bstToClear.root->pLeft = clearRootLeft;//(6)
    
    
    BST<int>::BNode* clearRootLeftLeft = new BST<int>::BNode();
    clearRootLeftLeft->data = 5;
    clearRootLeftLeft->pRight = NULL;
    clearRootLeftLeft->pLeft = NULL;
    clearRootLeftLeft->pParent = clearRootLeft;//(6)
    clearRootLeft->pLeft = clearRootLeftLeft;//(5)
    
    
    unit_testing_delete_call_counter = 0;
    bstToClear.clear();
    assertTrue(unit_testing_delete_call_counter == 6,__LINE__);//delete the list and each of the six nodes
    
    /*
     * Testing BST destructor
     */
    startTestSet("BST Destructor");
    unit_testing_delete_call_counter = 0;
    BST<int>* bstToDelete = new BST<int>();
    delete bstToDelete;
    assertTrue(unit_testing_delete_call_counter == 1,__LINE__);
    
    
    //killing potential zombie
    bstToDelete = NULL;
    
    //reset deletion counter
    unit_testing_delete_call_counter = 0;
    //Generating small BST with the values                              |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6---     ------10------
    //                                                       |             |             |
    //                                                       5             9             11
    
    //reusing bstToDelete
    bstToDelete = new BST<int>();
    bstToDelete->root = new BST<int>::BNode();
    bstToDelete->root->data = 7;
    
    BST<int>::BNode* delRootRight = new BST<int>::BNode();
    delRootRight->data = 10;
    delRootRight->pParent = bstToDelete->root;//(7)
    bstToDelete->root->pRight = delRootRight;//(10)
    
    BST<int>::BNode* delRootRightRight = new BST<int>::BNode();
    delRootRightRight->data = 11;
    delRootRightRight->pParent = delRootRight;//(10)
    delRootRight->pRight = delRootRightRight;//(11)
    
    BST<int>::BNode* delRootRightLeft = new BST<int>::BNode();
    delRootRightLeft->data = 9;
    delRootRightLeft->pParent = delRootRight;//(10)
    delRootRight->pLeft = delRootRightLeft;//(9)
    
    BST<int>::BNode* delRootLeft = new BST<int>::BNode();
    delRootLeft->data = 6;    delRootLeft->pRight = NULL;
    delRootLeft->pParent = bstToDelete->root;//(7)
    bstToDelete->root->pLeft = delRootLeft;//(6)
    
    
    BST<int>::BNode* delRootLeftLeft = new BST<int>::BNode();
    delRootLeftLeft->data = 5;
    delRootLeftLeft->pRight = NULL;
    delRootLeftLeft->pLeft = NULL;
    delRootLeftLeft->pParent = delRootLeft;//(6)
    delRootLeft->pLeft = delRootLeftLeft;//(5)
    
    
    unit_testing_delete_call_counter = 0;
    delete bstToDelete;
    assertTrue(unit_testing_delete_call_counter == 7,__LINE__);//delete the list and each of the six nodes
    
    bstToDelete = NULL;//kill potential zombie
    
    
    /*
     * Testing BST Insert
     */
    
    //Generating small BST with the values                              |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6---     ------10------
    //                                                       |             |             |
    //                                                       5             9             11
    startTestSet("BST Insert");
    BST<int> insertIntoBST;
    insertIntoBST.numElements = 6;
    insertIntoBST.root = new BST<int>::BNode();
    insertIntoBST.root->data = 7;
    
    BST<int>::BNode* insertRootRight = new BST<int>::BNode();
    insertRootRight->data = 10;
    insertRootRight->pParent = insertIntoBST.root;//(7)
    insertIntoBST.root->pRight = insertRootRight;//(10)
    
    BST<int>::BNode* insertRootRightRight = new BST<int>::BNode();
    insertRootRightRight->data = 11;
    insertRootRightRight->pParent = insertRootRight;//(10)
    insertRootRight->pRight = insertRootRightRight;//(11)
    
    BST<int>::BNode* insertRootRightLeft = new BST<int>::BNode();
    insertRootRightLeft->data = 9;
    insertRootRightLeft->pParent = insertRootRight;//(10)
    insertRootRight->pLeft = insertRootRightLeft;//(9)
    
    BST<int>::BNode* insertRootLeft = new BST<int>::BNode();
    insertRootLeft->data = 6;
    insertRootLeft->pRight = NULL;
    insertRootLeft->pParent = insertIntoBST.root;//(7)
    insertIntoBST.root->pLeft = insertRootLeft;//(6)
    
    
    BST<int>::BNode* insertRootLeftLeft = new BST<int>::BNode();
    insertRootLeftLeft->data = 5;
    insertRootLeftLeft->pRight = NULL;
    insertRootLeftLeft->pLeft = NULL;
    insertRootLeftLeft->pParent = insertRootLeft;//(6)
    insertRootLeft->pLeft = insertRootLeftLeft;//(5)
    
    insertIntoBST.insert(8);
    //Should be BST with the values                                      |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6---     ------10------
    //                                                       |             |             |
    //                                                       5         ----9             11
    //                                                                 |
    //                                                                 8
    assertTrue(insertIntoBST.numElements == 7,__LINE__);
    assertTrue(insertIntoBST.root->data == 7,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->data == 6,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pParent == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->data == 5,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pParent == insertIntoBST.root->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->data == 10,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pParent == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->data == 11,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->data == 9,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->data == 8,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pParent == insertIntoBST.root->pRight->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pLeft == NULL,__LINE__);
    
    insertIntoBST.insert(20);
    //Should be BST with the values                                     |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6        ------10------
    //                                                       |             |             |
    //                                                       5         ----9             11-------
    //                                                                 |                          |
    //                                                                 8                          20
    assertTrue(insertIntoBST.numElements == 8,__LINE__);
    assertTrue(insertIntoBST.root->data == 7,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->data == 6,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pParent == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->data == 5,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pParent == insertIntoBST.root->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->data == 10,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pParent == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->data == 11,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->data == 20,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pParent == insertIntoBST.root->pRight->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->data == 9,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->data == 8,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pParent == insertIntoBST.root->pRight->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pLeft == NULL,__LINE__);
    
    insertIntoBST.insert(3);
    //Should be BST with the values                                     |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6        ------10------
    //                                                       |             |             |
    //                                                   ----5         ----9---          11-------
    //                                                  |             |                           |
    //                                                  3             8                           20
    assertTrue(insertIntoBST.numElements == 9,__LINE__);
    assertTrue(insertIntoBST.root->data == 7,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->data == 6,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->data == 5,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->data == 3,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pParent == insertIntoBST.root->pLeft->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->data == 10,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pParent == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->data == 11,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->data == 20,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pParent == insertIntoBST.root->pRight->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->data == 9,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->data == 8,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pParent == insertIntoBST.root->pRight->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pLeft == NULL,__LINE__);
    
    insertIntoBST.insert(4);
    //Should be BST with the values                                     |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6        ------10------
    //                                                       |             |             |
    //                                                   ----5         ----9---          11-------
    //                                                  |             |                           |
    //                                                  3---          8                           20
    //                                                      |
    //                                                      4
    assertTrue(insertIntoBST.numElements == 10,__LINE__);
    assertTrue(insertIntoBST.root->data == 7,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->data == 6,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->data == 5,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->data == 3,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pParent == insertIntoBST.root->pLeft->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight->data == 4,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->data == 10,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pParent == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->data == 11,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->data == 20,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pParent == insertIntoBST.root->pRight->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->data == 9,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->data == 8,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pParent == insertIntoBST.root->pRight->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pLeft == NULL,__LINE__);
    
    insertIntoBST.insert(2);
    //Should be BST with the values                                     |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6        ------10------
    //                                                       |             |             |
    //                                                   ----5         ----9---          11-------
    //                                                  |             |                           |
    //                                              ----3---          8                           20
    //                                             |        |
    //                                             2        4
    assertTrue(insertIntoBST.numElements == 11,__LINE__);
    assertTrue(insertIntoBST.root->data == 7,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->data == 6,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->data == 5,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->data == 3,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pParent == insertIntoBST.root->pLeft->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight->data == 4,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pRight->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pLeft->data == 2,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pLeft->pLeft->pLeft->pLeft->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->data == 10,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pParent == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->data == 11,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->data == 20,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pParent == insertIntoBST.root->pRight->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pRight->pRight->pLeft == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->data == 9,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pParent == insertIntoBST.root->pRight,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft != NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->data == 8,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pParent == insertIntoBST.root->pRight->pLeft,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(insertIntoBST.root->pRight->pLeft->pLeft->pLeft == NULL,__LINE__);
    
    BST<int> buildBST;
    buildBST.insert(10);
    //should be                                                     |
    //                                                              10
    assertTrue(buildBST.numElements == 1,__LINE__);
    assertTrue(buildBST.root->data == 10,__LINE__);
    assertTrue(buildBST.root->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pParent == NULL,__LINE__);
    
    buildBST.insert(5);
    //should be                                                     |
    //                                                       -------10
    //                                                      |
    //                                                      5
    assertTrue(buildBST.numElements == 2,__LINE__);
    assertTrue(buildBST.root->data == 10,__LINE__);
    assertTrue(buildBST.root->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->data == 5,__LINE__);
    assertTrue(buildBST.root->pLeft->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pLeft == NULL,__LINE__);
    
    buildBST.insert(11);
    //should be                                                     |
    //                                                       -------10-------
    //                                                      |                |
    //                                                      5                11
    assertTrue(buildBST.numElements == 3,__LINE__);
    assertTrue(buildBST.root->data == 10,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pRight->data == 11,__LINE__);
    assertTrue(buildBST.root->pRight->pParent = buildBST.root,__LINE__);
    assertTrue(buildBST.root->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pRight->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->data == 5,__LINE__);
    assertTrue(buildBST.root->pLeft->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pLeft == NULL,__LINE__);
    
    buildBST.insert(9);
    //should be                                                     |
    //                                                       -------10-------
    //                                                      |                |
    //                                                      5----            11
    //                                                           |
    //                                                           9
    assertTrue(buildBST.numElements == 4,__LINE__);
    assertTrue(buildBST.root->data == 10,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pRight->data == 11,__LINE__);
    assertTrue(buildBST.root->pRight->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pRight->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->data == 5,__LINE__);
    assertTrue(buildBST.root->pLeft->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->data == 9,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pParent == buildBST.root->pLeft,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft == NULL,__LINE__);
    
    
    buildBST.insert(7);
    //should be                                                     |
    //                                                --------------10-------
    //                                               |                       |
    //                                               5-----------            11
    //                                                           |
    //                                                       ----9
    //                                                      |
    //                                                      7
    assertTrue(buildBST.numElements == 5,__LINE__);
    assertTrue(buildBST.root->data == 10,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pRight->data == 11,__LINE__);
    assertTrue(buildBST.root->pRight->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pRight->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->data == 5,__LINE__);
    assertTrue(buildBST.root->pLeft->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->data == 9,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pParent == buildBST.root->pLeft,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->data == 7,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pParent == buildBST.root->pLeft->pRight,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pRight == NULL,__LINE__);
    
    
    buildBST.insert(6);
    //should be                                                     |
    //                                                --------------10-------
    //                                               |                       |
    //                                               5-----------            11
    //                                                           |
    //                                                       ----9
    //                                                      |
    //                                                   ---7
    //                                                  |
    //                                                  6
    assertTrue(buildBST.numElements == 6,__LINE__);
    assertTrue(buildBST.root->data == 10,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pRight->data == 11,__LINE__);
    assertTrue(buildBST.root->pRight->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pRight->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->data == 5,__LINE__);
    assertTrue(buildBST.root->pLeft->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->data == 9,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pParent == buildBST.root->pLeft,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->data == 7,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pParent == buildBST.root->pLeft->pRight,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->data == 6,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->pParent == buildBST.root->pLeft->pRight->pLeft,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->pLeft == NULL,__LINE__);
    
    
    buildBST.insert(8);
    //should be                                                     |
    //                                                --------------10-------
    //                                               |                       |
    //                                               5-----------            11
    //                                                           |
    //                                                       ----9
    //                                                      |
    //                                                   ---7---
    //                                                  |       |
    //                                                  6       8
    assertTrue(buildBST.numElements == 7,__LINE__);
    assertTrue(buildBST.root->data == 10,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pRight->data == 11,__LINE__);
    assertTrue(buildBST.root->pRight->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pRight->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->data == 5,__LINE__);
    assertTrue(buildBST.root->pLeft->pParent == buildBST.root,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->data == 9,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pParent == buildBST.root->pLeft,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->data == 7,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pParent == buildBST.root->pLeft->pRight,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pRight != NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->data == 6,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->pParent == buildBST.root->pLeft->pRight->pLeft,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pLeft->pLeft == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pRight->data == 8,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pRight->pParent == buildBST.root->pLeft->pRight->pLeft,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pRight->pRight == NULL,__LINE__);
    assertTrue(buildBST.root->pLeft->pRight->pLeft->pRight->pLeft == NULL,__LINE__);
    
    
    /*
     * Testing Iterator Constructors
     */
    startTestSet("Iterator Constructors");
    BST<int>::iterator emptyIterator;
    assertTrue(emptyIterator.ptr == NULL,__LINE__);
    
    BST<int>::BNode* noDataNodePtr = new BST<int>::BNode();
    BST<int>::iterator nonEmptyIterator(noDataNodePtr);
    assertTrue(nonEmptyIterator.ptr != NULL,__LINE__);
    assertTrue(nonEmptyIterator.ptr == noDataNodePtr,__LINE__);
    //clean up memory
    delete noDataNodePtr;
    //get rid of zombies
    noDataNodePtr = NULL;
    nonEmptyIterator.ptr = NULL;
    
    /*
     * Testing Iterator Destructor
     */
    startTestSet("Iterator Destructor");
    BST<int>::iterator* iteratorToDelete = new BST<int>::iterator();
    unit_testing_delete_call_counter = 0;
    delete iteratorToDelete;
    assertTrue(unit_testing_delete_call_counter == 1,__LINE__);//don't delete the node. It's part of a list.
    
    //resetting
    noDataNodePtr = new BST<int>::BNode();
    iteratorToDelete = new BST<int>::iterator();
    iteratorToDelete->ptr = noDataNodePtr;
    unit_testing_delete_call_counter = 0;
    delete iteratorToDelete;
    assertTrue(unit_testing_delete_call_counter == 1,__LINE__);
    //clean up memory
    delete noDataNodePtr;
    //get rid of zombies
    iteratorToDelete = NULL;
    noDataNodePtr = NULL;
    
    /*
     * Testing iterator equality operator
     */
    startTestSet("Iterator == Operator");
    BST<int>::iterator validNodeIterator;
    validNodeIterator.ptr = new BST<int>::BNode();
    
    BST<int>::iterator nullNodeIterator;
    BST<int>::iterator otherNullNodeIterator;
    assertTrue(nullNodeIterator == nullNodeIterator,__LINE__);//compare the memory locations of nodes
    assertTrue(otherNullNodeIterator == otherNullNodeIterator,__LINE__);
    assertTrue(!(nullNodeIterator == validNodeIterator),__LINE__);
    
    
    //resetting
    noDataNodePtr = new BST<int>::BNode();
    BST<int>::iterator nonNullNodeIterator;
    nonNullNodeIterator.ptr = noDataNodePtr;
    assertTrue(nonNullNodeIterator == nonNullNodeIterator,__LINE__);//compare memory locations of nodes
    assertTrue(!(nonNullNodeIterator == nullNodeIterator),__LINE__);
    
    //setting up a node with the data
    BST<int>::BNode* dataNodePtr = new BST<int>::BNode();
    dataNodePtr->data = 7;
    BST<int>::iterator nodeHasDataIterator;
    nodeHasDataIterator.ptr = dataNodePtr;
    assertTrue(nodeHasDataIterator == nodeHasDataIterator,__LINE__);
    
    //setting up an iterator to the same data node
    BST<int>::iterator otherNodeHasDataIterator;
    otherNodeHasDataIterator.ptr = dataNodePtr;
    assertTrue(otherNodeHasDataIterator == nodeHasDataIterator,__LINE__);//compare memory locations of nodes
    
    /*
     * Testing iterator non-equality operator
     */
    startTestSet("Iterator != Operator");
    //comparing with self
    assertTrue((otherNullNodeIterator != otherNullNodeIterator) == false,__LINE__);
    assertTrue((nodeHasDataIterator != nodeHasDataIterator) == false,__LINE__);
    
    //having different nodes makes the iterators different
    assertTrue(nullNodeIterator != nodeHasDataIterator,__LINE__);
    
    //having nodes with data duplicates doesn't make the iterators the same iterator
    BST<int>::BNode* otherNodeWithSameData= new BST<int>::BNode();
    otherNodeWithSameData->data = 7;
    BST<int>::iterator otherNodeWithSameDataIterator;
    otherNodeWithSameDataIterator.ptr = otherNodeWithSameData;
    assertTrue(nodeHasDataIterator != otherNodeWithSameDataIterator,__LINE__);
    
    
    //clean up memory
    delete otherNodeWithSameData;
    delete noDataNodePtr;
    delete dataNodePtr;
    //get rid of zombies
    otherNodeWithSameData = NULL;
    noDataNodePtr = NULL;
    dataNodePtr = NULL;
    
    
    /*
     * Testing iterator assignment operator
     */
    startTestSet("Iterator = Operator");
    BST<int>::iterator assignTo;
    assignTo.ptr = NULL;
    BST<int>::iterator assignFrom;
    assignFrom.ptr = NULL;
    assignTo = assignFrom;
    assertTrue(assignTo.ptr == assignFrom.ptr,__LINE__);
    
    //reset
    nodeToDelete = new BST<int>::BNode();
    assignTo.ptr = nodeToDelete;
    assignTo.ptr->data = 5;
    
    assignFrom.ptr = new BST<int>::BNode();
    assignFrom.ptr->data = 17;
    
    assignTo = assignFrom;
    assertTrue(assignTo.ptr == assignFrom.ptr,__LINE__);
    assertTrue(assignTo.ptr->data == 17,__LINE__);
    
    //clean up memory
    delete assignFrom.ptr;
    delete nodeToDelete;
    //kill zombies
    assignFrom.ptr = NULL;
    nodeToDelete = NULL;
    
    /*
     * Testing dereference operator
     */
    startTestSet("Iterator * Operator");
    //testing when pointer is NULL
    BST<int>::iterator dereferenceIterator;
    dereferenceIterator.ptr = NULL;
    try{
        *dereferenceIterator;
        assertTrue(false,__LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message,"Error: dereferencing null node.") == 0,__LINE__);
    }
    dereferenceIterator.ptr = new BST<int>::BNode();
    dereferenceIterator.ptr->data = 32;
    
    assertTrue((*dereferenceIterator) == 32,__LINE__);
    
    
    /*
     * Testing BST begin and end
     */
    startTestSet("BST Begin and End");
    BST<int> emptyBeginEndTree;
    emptyBeginEndTree.root = NULL;
    assertTrue(emptyBeginEndTree.begin().ptr == NULL,__LINE__);
    assertTrue(emptyBeginEndTree.end().ptr == NULL,__LINE__);
    
    //Reusing insertIntoBST
    //Should be BST with the values                                     |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6        ------10------
    //                                                       |             |             |
    //                                                   ----5         ----9---          11-------
    //                                                  |             |                           |
    //                                              ----3---          8                           20
    //                                             |        |
    //                                             2        4
    assertTrue(insertIntoBST.begin().ptr == insertIntoBST.root->pLeft->pLeft->pLeft->pLeft,__LINE__);
    assertTrue(insertIntoBST.begin().ptr->data == 2,__LINE__);
    assertTrue(insertIntoBST.end().ptr == insertIntoBST.root->pRight->pRight->pRight,__LINE__);
    assertTrue(insertIntoBST.end().ptr->data == 20,__LINE__);
    
    //reusing buildBST
    //currently                                                     |
    //                                                --------------10-------
    //                                               |                       |
    //                                               5-----------            11
    //                                                           |
    //                                                       ----9
    //                                                      |
    //                                                   ---7---
    //                                                  |       |
    //                                                  6       8
    assertTrue(buildBST.begin().ptr == buildBST.root->pLeft,__LINE__);
    assertTrue(buildBST.end().ptr == buildBST.root->pRight,__LINE__);
    
    /*
     * Testing BST find
     */
    startTestSet("BST Find");
    //Reusing emptyBeginEndTree
    assertTrue(emptyBeginEndTree.find(23).ptr == NULL,__LINE__);
    
    //Reusing insertIntoBST
    //Should be BST with the values                                     |
    //                                                            ------7---------
    //                                                            |              |
    //                                                       -----6        ------10------
    //                                                       |             |             |
    //                                                   ----5         ----9---          11-------
    //                                                  |             |                           |
    //                                              ----3---          8                           20
    //                                             |        |
    //                                             2        4
    
    //searching in a balanced tree
    assertTrue(insertIntoBST.find(7).ptr == insertIntoBST.root,__LINE__);
    assertTrue(insertIntoBST.find(2).ptr == insertIntoBST.root->pLeft->pLeft->pLeft->pLeft,__LINE__);
    assertTrue(insertIntoBST.find(20).ptr == insertIntoBST.root->pRight->pRight->pRight,__LINE__);
    assertTrue(insertIntoBST.find(8).ptr == insertIntoBST.root->pRight->pLeft->pLeft,__LINE__);
    assertTrue(insertIntoBST.find(8).ptr->data == 8,__LINE__);
    assertTrue(insertIntoBST.find(456).ptr == NULL,__LINE__);
    //* ToDo: expand each of these tests to check all values of the tree to make sure nothing got messed up.
    
    assertTrue(insertIntoBST.find(4).ptr == insertIntoBST.root->pLeft->pLeft->pLeft->pRight,__LINE__);
    assertTrue(insertIntoBST.find(4).ptr->data == 4,__LINE__);
    
    //reusing buildBST
    //currently                                                     |
    //                                                --------------10-------
    //                                               |                       |
    //                                               5-----------            11
    //                                                           |
    //                                                       ----9
    //                                                      |
    //                                                   ---7---
    //                                                  |       |
    //                                                  6       8
    
    //searching in unbalanced tree
    assertTrue(buildBST.find(8).ptr == buildBST.root->pLeft->pRight->pLeft->pRight,__LINE__);
    assertTrue(buildBST.find(8).ptr->data == 8,__LINE__);
    
    /*
     * Testing BST copy constructor
     */
    
    //reusing buildBST
    //currently                                                     |
    //                                                --------------10-------
    //                                               |                       |
    //                                               5-----------            11
    //                                                           |
    //                                                       ----9
    //                                                      |
    //                                                   ---7---
    //                                                  |       |
    //                                                  6       8
    startTestSet("BST Copy");
    BST<int> buildCopy(buildBST);
    assertTrue(buildCopy.root != buildBST.root,__LINE__);
    assertTrue(buildCopy.root->data == buildBST.root->data,__LINE__);
    assertTrue(buildCopy.root->pRight != buildBST.root->pRight,__LINE__);
    assertTrue(buildCopy.root->pRight->data == buildBST.root->pRight->data,__LINE__);//(11)
    assertTrue(buildCopy.root->pLeft != buildBST.root->pLeft,__LINE__);
    assertTrue(buildCopy.root->pLeft->data == buildBST.root->pLeft->data,__LINE__);//(5)
    assertTrue(buildCopy.root->pLeft->pRight != buildBST.root->pLeft->pRight,__LINE__);
    assertTrue(buildCopy.root->pLeft->pRight->data == buildBST.root->pLeft->pRight->data,__LINE__);//(9)
    assertTrue(buildCopy.root->pLeft->pRight->pLeft != buildBST.root->pLeft->pRight->pLeft,__LINE__);
    assertTrue(buildCopy.root->pLeft->pRight->pLeft->data == buildBST.root->pLeft->pRight->pLeft->data,__LINE__);//(7)
    assertTrue(buildCopy.root->pLeft->pRight->pLeft->pRight != buildBST.root->pLeft->pRight->pLeft->pRight,__LINE__);
    assertTrue(buildCopy.root->pLeft->pRight->pLeft->pRight->data == buildBST.root->pLeft->pRight->pLeft->pRight->data,__LINE__);//(8)
    assertTrue(buildCopy.root->pLeft->pRight->pLeft->pLeft != buildBST.root->pLeft->pRight->pLeft->pLeft,__LINE__);
    assertTrue(buildCopy.root->pLeft->pRight->pLeft->pLeft->data == buildCopy.root->pLeft->pRight->pLeft->pLeft->data,__LINE__);//(6)
    
    /*
     * Testing BST erase
     */
    startTestSet("BST Erase");
    //building erase tree
    //                                                                  |
    //                                                          --------13--------
    //                                                          |                 |
    //                                                      ----5----         ----22----
    //                                                     |         |       |          |
    //                                                     4         11      21         23
    
    BST<int>eraseTree;
    eraseTree.numElements = 7;
    eraseTree.root = new BST<int>::BNode();
    eraseTree.root->data = 13;
    eraseTree.root->pLeft = new BST<int>::BNode();
    eraseTree.root->pLeft->data = 5;
    eraseTree.root->pLeft->pParent = eraseTree.root;
    eraseTree.root->pLeft->pLeft = new BST<int>::BNode();
    eraseTree.root->pLeft->pLeft->data = 4;
    eraseTree.root->pLeft->pLeft->pParent = eraseTree.root->pLeft;
    eraseTree.root->pLeft->pLeft->pRight = NULL;
    eraseTree.root->pLeft->pLeft->pLeft = NULL;
    eraseTree.root->pLeft->pRight = new BST<int>::BNode();
    eraseTree.root->pLeft->pRight->data = 11;
    eraseTree.root->pLeft->pRight->pParent = eraseTree.root->pLeft;
    eraseTree.root->pLeft->pRight->pRight = NULL;
    eraseTree.root->pLeft->pRight->pLeft = NULL;
    
    eraseTree.root->pRight = new BST<int>::BNode();
    eraseTree.root->pRight->data = 22;
    eraseTree.root->pRight->pParent = eraseTree.root;
    eraseTree.root->pRight->pLeft = new BST<int>::BNode();
    eraseTree.root->pRight->pLeft->data = 21;
    eraseTree.root->pRight->pLeft->pParent = eraseTree.root->pRight;
    eraseTree.root->pRight->pRight = new BST<int>::BNode();
    eraseTree.root->pRight->pRight->data = 23;
    eraseTree.root->pRight->pRight->pParent = eraseTree.root->pRight;
    
    BST<int>::iterator eraseIterator;
    eraseIterator.ptr = eraseTree.root->pLeft->pLeft;//(4)
    unit_testing_delete_call_counter = 0;
    eraseTree.erase(eraseIterator);
    
    //should now be
    //                                                                  |
    //                                                          --------13--------
    //                                                          |                 |
    //                                                      ----5----         ----22----
    //                                                               |       |          |
    //                                                               11      21         23
    
    assertTrue(unit_testing_delete_call_counter == 1,__LINE__);
    assertTrue(eraseTree.root->pLeft->pLeft == NULL,__LINE__);
    assertTrue(eraseTree.numElements == 6,__LINE__);
    
    //setting up
    BST<int>::BNode* elevenNode = eraseTree.root->pLeft->pRight;
    unit_testing_delete_call_counter = 0;
    //reusing eraseIterator
    eraseIterator.ptr = eraseTree.root->pLeft;
    eraseTree.erase(eraseIterator);
    
    //should now be
    //                                                                  |
    //                                                          --------13--------
    //                                                          |                 |
    //                                                          11            ----22----
    //                                                                       |          |
    //                                                                       21         23
    assertTrue(unit_testing_delete_call_counter == 1,__LINE__);
    assertTrue(eraseTree.root->pLeft == elevenNode,__LINE__);
    assertTrue(eraseTree.numElements == 5,__LINE__);
    
    //rebuild tree for next test
    //                                                                  |
    //                                                          --------13--------
    //                                                          |                 |
    //                                                      ----11---         ----22----
    //                                                     |         |       |          |
    //                                                     10        12      21         23
    
    
    elevenNode->pLeft = new BST<int>::BNode();
    elevenNode->pLeft->data = 10;
    elevenNode->pLeft->pParent = elevenNode;
    elevenNode->pRight = new BST<int>::BNode();
    elevenNode->pRight->data = 12;
    elevenNode->pRight->pParent = elevenNode;
    
    eraseTree.numElements = 7;
    
    //setting up
    BST<int>::BNode* twentyOneNode = eraseTree.root->pRight->pLeft;
    BST<int>::BNode* twentyTwoNode = eraseTree.root->pRight;
    unit_testing_delete_call_counter = 0;
    //reusing eraseIterator
    eraseIterator.ptr = eraseTree.root;
    eraseTree.erase(eraseIterator);
    //should now be
    //                                                                  |
    //                                                          --------21--------
    //                                                          |                 |
    //                                                      ----11---             22----
    //                                                     |         |                  |
    //                                                     10        12                 23
    assertTrue(unit_testing_delete_call_counter == 1,__LINE__);
    assertTrue(eraseTree.root == twentyOneNode,__LINE__);
    assertTrue(eraseTree.root->data == 21,__LINE__);
    assertTrue(eraseTree.root->pRight == twentyTwoNode,__LINE__);
    assertTrue(eraseTree.root->pRight->pLeft == NULL,__LINE__);
    assertTrue(eraseTree.root->pLeft == elevenNode,__LINE__);
    assertTrue(eraseTree.numElements == 6,__LINE__);
    
    /*
     * Testing iterator pre-increment operator
     */
    startTestSet("Iterator Pre-Increment Operator");
    BST<int>::iterator incrementIterator;
    incrementIterator.ptr = NULL;
    try{
        ++incrementIterator;
        assertTrue(false,__LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: incrementing null node.") == 0,__LINE__);
    }
    //beginning of tree test
    incrementIterator.ptr = eraseTree.root->pLeft->pLeft;//(10)
    assertTrue((++incrementIterator).ptr == eraseTree.root->pLeft,__LINE__);//(11)
    //end of tree test
    incrementIterator.ptr = eraseTree.root->pRight->pRight;
    assertTrue((++incrementIterator).ptr == NULL,__LINE__);
    //middle of tree test
    incrementIterator.ptr = eraseTree.root->pLeft->pRight;//(12)
    assertTrue((++incrementIterator).ptr == eraseTree.root,__LINE__);
    
    /*
     * Testing iterator post increment operator
     */
    startTestSet("Iterator Post-Increment");
    
    //should now be
    //                                                                  |
    //                                                          --------21--------
    //                                                          |                 |
    //                                                      ----11---             22----
    //                                                     |         |                  |
    //                                                     10        12                 23
    incrementIterator.ptr = NULL;
    try{
        incrementIterator++;
        assertTrue(false,__LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: incrementing null node.") == 0,__LINE__);
    }
    //reusing eraseTree
    //beginning of tree test
    incrementIterator.ptr = eraseTree.root->pLeft->pLeft;//(10)
    assertTrue((incrementIterator++).ptr == eraseTree.root->pLeft->pLeft,__LINE__);//(10)
    assertTrue(incrementIterator.ptr == eraseTree.root->pLeft,__LINE__);//(11)
    //end of tree test
    incrementIterator.ptr = eraseTree.root->pRight->pRight;//(23)
    assertTrue((incrementIterator++).ptr == eraseTree.root->pRight->pRight,__LINE__);
    assertTrue(incrementIterator.ptr == NULL,__LINE__);
    //middle of tree test
    incrementIterator.ptr = eraseTree.root->pLeft->pRight;//(12)
    assertTrue((incrementIterator++).ptr == eraseTree.root->pLeft->pRight,__LINE__);
    assertTrue(incrementIterator.ptr == eraseTree.root,__LINE__);//(21)
    
    /*
     * Testing iterator pre-decrement operator
     */
    startTestSet("Iterator Post-Decrement Operator");
    //should now be
    //                                                                  |
    //                                                          --------21--------
    //                                                          |                 |
    //                                                      ----11---             22----
    //                                                     |         |                  |
    //                                                     10        12                 23
    BST<int>::iterator decrementIterator;
    decrementIterator.ptr = NULL;
    try{
        --decrementIterator;
        assertTrue(false,__LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: decrementing null node.") == 0,__LINE__);
    }
    //beginning of tree test
    decrementIterator.ptr = eraseTree.root->pLeft->pLeft;//(10)
    assertTrue((--decrementIterator).ptr == NULL,__LINE__);
    //end of tree test
    decrementIterator.ptr = eraseTree.root->pRight->pRight;//(23)
    assertTrue((--decrementIterator).ptr == eraseTree.root->pRight,__LINE__);
    //middle of tree test
    decrementIterator.ptr = eraseTree.root->pLeft->pRight;//(12)
    assertTrue((--decrementIterator).ptr == eraseTree.root->pLeft,__LINE__);
    
    /*
     * Testing iterator post decrement operator
     */
    startTestSet("Iterator Post-Decrement");
    //should now be
    //                                                                  |
    //                                                          --------21--------
    //                                                          |                 |
    //                                                      ----11---             22----
    //                                                     |         |                  |
    //                                                     10        12                 23
    decrementIterator.ptr = NULL;
    try{
        decrementIterator--;
        assertTrue(false,__LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: decrementing null node.") == 0,__LINE__);
    }
    //beginning of tree test
    decrementIterator.ptr = eraseTree.root->pLeft->pLeft;//(10)
    assertTrue((decrementIterator--).ptr == eraseTree.root->pLeft->pLeft,__LINE__);
    assertTrue(decrementIterator.ptr == NULL,__LINE__);
    //end of tree test
    decrementIterator.ptr = eraseTree.root->pRight->pRight;//(23)
    assertTrue((decrementIterator--).ptr == eraseTree.root->pRight->pRight,__LINE__);
    //middle of tree test
    decrementIterator.ptr = eraseTree.root->pLeft->pRight;//(12)
    assertTrue((decrementIterator--).ptr == eraseTree.root->pLeft->pRight,__LINE__);
    assertTrue(decrementIterator.ptr == eraseTree.root->pLeft,__LINE__);
   
    //*ToDo: Write string test.
    
    
    
    generateTestingReport();
    
    
    
    
    return 0;
}
