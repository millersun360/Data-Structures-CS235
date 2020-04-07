/*
 * main.cpp
 *
 *  Created by Lee Barney on 11/14/18.
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
int asserts_existing = 161;

#include <cstring>
#include "unit_testing.h"
#include "map.h"

using namespace custom;

int main(int argc, const char * argv[]) {
    
    /*------------------------------------------------------------------
     * WARNING: THIS TEST HAS A DEPENDENCY ON THE BST TEST.
     * THE BST TEST MUST PASS WITHOUT FAILURE BEFORE THIS TEST IS RUN.
     *------------------------------------------------------------------
     */
    
    
    
    /*
     * Testing pair constructors
     */
    
    startTestSet("Pair Constructor");
    map<char,int>::pair defaultPair;
    //not really anything that can be tested here. Unset default values could be anything.
    
    map<char,int>::pair pairToCopy;
    pairToCopy.first = 'a';
    pairToCopy.second = 97;
    
    map<char,int>::pair copiedPair(pairToCopy);
    assertTrue(copiedPair.first == 'a', __LINE__);
    assertTrue(copiedPair.second == 97, __LINE__);
    
    /*
     * Testing pair operators
     */
    startTestSet("Pair Assignment");
    map<char, int>::pair assignedToPair = pairToCopy;
    assertTrue(assignedToPair.first == 'a', __LINE__);
    assertTrue(assignedToPair.second == 97, __LINE__);
    
    
    assignedToPair = defaultPair;
    assertTrue(assignedToPair.first == defaultPair.first, __LINE__);
    assertTrue(assignedToPair.second == defaultPair.second, __LINE__);
    
    //for all comparison operators, only the key is used for the comparison.
    
    
    /*
     * Testing == operator
     */
    startTestSet("Pair == Operator");
    //testing comparing to self
    assertTrue(defaultPair == defaultPair, __LINE__);
    assertTrue(assignedToPair == assignedToPair, __LINE__);
    //testing comparing to others
    assertTrue(assignedToPair == defaultPair, __LINE__);
    assertTrue(copiedPair == pairToCopy, __LINE__);
    assertTrue(!(assignedToPair == pairToCopy), __LINE__);
    //testing key matches value doesn't
    copiedPair.second = 5;
    assertTrue(copiedPair == pairToCopy, __LINE__);
    //testing key doesn't match, value does
    copiedPair.second = 97;
    copiedPair.first = 'b';
    assertTrue(!(copiedPair == pairToCopy), __LINE__);
    
    /*
     * Testing > operator
     */
    startTestSet("Pair > Operator");
    map<char, int>::pair lesserPair;
    lesserPair.first = ' ';//ascii value is 32
    lesserPair.second = 18;
    map<char, int>::pair greaterPair;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 18;
    
    //testing key doesn't match, value does
    assertTrue(greaterPair > lesserPair, __LINE__);
    //testing key matches, values don't
    lesserPair.first = '~';
    greaterPair.second = 100;
    assertTrue(!(greaterPair > lesserPair), __LINE__);
    //testing comparing to self
    assertTrue(!(greaterPair > greaterPair), __LINE__);
    assertTrue(!(defaultPair > defaultPair), __LINE__);
    
    /*
     * Testing < operator
     */
    startTestSet("Pair < Operator");
    //resetting lesser and greater pairs
    lesserPair.first = ' ';
    lesserPair.second = 18;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 100;
    
    assertTrue(lesserPair < greaterPair, __LINE__);
    //testing against self
    assertTrue(!(lesserPair < lesserPair), __LINE__);
    assertTrue(!(greaterPair < greaterPair), __LINE__);
    assertTrue(!(defaultPair < defaultPair), __LINE__);
    assertTrue(!(greaterPair < lesserPair), __LINE__);
    //testing keys don't match, values do
    greaterPair.second = lesserPair.second;
    assertTrue(lesserPair < greaterPair, __LINE__);
    //testing keys match values don't
    greaterPair.second = 200;
    lesserPair.first = greaterPair.first;
    assertTrue(!(lesserPair < greaterPair), __LINE__);
    
    /*
     * Testing >= operator
     */
    startTestSet("Pair >= Operator");
    //resetting lesser and greater pairs
    lesserPair.first = ' ';
    lesserPair.second = 18;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 100;
    
    assertTrue(greaterPair >= lesserPair, __LINE__);
    //testing against self
    assertTrue(lesserPair >= lesserPair, __LINE__);
    assertTrue(greaterPair >= greaterPair, __LINE__);
    assertTrue(defaultPair >= defaultPair, __LINE__);
    assertTrue(!(lesserPair >= greaterPair), __LINE__);
    //testing keys don't match, values do;
    greaterPair.second = lesserPair.second;
    assertTrue(greaterPair >= lesserPair, __LINE__);
    assertTrue(!(lesserPair >= greaterPair), __LINE__);
    //testing keys match values don't
    greaterPair.second = 200;
    lesserPair.first = greaterPair.first;
    assertTrue(greaterPair >= lesserPair, __LINE__);
    assertTrue(lesserPair >= greaterPair, __LINE__);
    
    /*
     * Testing <= operator
     */
    startTestSet("Pair <= Operator");
    //resetting lesser and greater pairs
    lesserPair.first = ' ';
    lesserPair.second = 18;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 100;
    
    assertTrue(lesserPair <= greaterPair, __LINE__);
    //testing against self
    assertTrue(lesserPair <= lesserPair, __LINE__);
    assertTrue(greaterPair <= greaterPair, __LINE__);
    assertTrue(defaultPair <= defaultPair, __LINE__);
    //testing keys don't match values do
    greaterPair.second = lesserPair.second;
    assertTrue(lesserPair <= greaterPair, __LINE__);
    assertTrue(!(greaterPair <= lesserPair), __LINE__);
    //testing keys match values don't
    greaterPair.second = 200;
    lesserPair.first = greaterPair.first;
    assertTrue(lesserPair <= greaterPair, __LINE__);
    assertTrue(greaterPair <= lesserPair, __LINE__);
    
    /*
     * Testing map constructors
     */
    startTestSet("Map Constructors");
    map<char,int> defaultMap;
    assertTrue(defaultMap.bst.numElements == 0, __LINE__);
    assertTrue(defaultMap.bst.root == NULL, __LINE__);
    
    map<char, int> copiedMap(defaultMap);
    assertTrue(copiedMap.bst.numElements == 0, __LINE__);
    assertTrue(copiedMap.bst.root == NULL, __LINE__);
    
    //Generating small BST with the values                              |
    //                                                            ----<f,7>------
    //                                                            |              |
    //                                                       ---<c,21>--     --<s,10>------
    //                                                       |               |             |
    //                                                     <b,3>           <g,-5>        <z,0>
    
    map<char, int> builtMap;
    //BST<map<char,int>::pair<char,int>> builtMap.bst;
    builtMap.bst.numElements = 6;
    builtMap.bst.root = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair fPair;
    fPair.first = 'f';
    fPair.second = 7;
    builtMap.bst.root->data = fPair;
    
    
    BST<map<char,int>::pair>::BNode* insertRootRight = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair gPair;
    gPair.first = 's';
    gPair.second = 10;
    insertRootRight->data = gPair;
    insertRootRight->pParent = builtMap.bst.root;// <f,7>
    builtMap.bst.root->pRight = insertRootRight;// <s,10>
    
    BST<map<char,int>::pair>::BNode* insertRootRightRight = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair zPair;
    zPair.first = 'z';
    zPair.second = 0;
    insertRootRightRight->data = zPair;
    insertRootRightRight->pParent = insertRootRight;// <s,10>
    insertRootRight->pRight = insertRootRightRight;// <z,0>
    
    BST<map<char,int>::pair>::BNode* insertRootRightLeft = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair sPair;
    sPair.first = 'g';
    sPair.second = -5;
    insertRootRightLeft->data = sPair;
    insertRootRightLeft->pParent = insertRootRight;// <s,10>
    insertRootRight->pLeft = insertRootRightLeft;// <g,-5>
    
    BST<map<char,int>::pair>::BNode* insertRootLeft = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair cPair;
    cPair.first = 'c';
    cPair.second = 21;
    insertRootLeft->data = cPair;
    insertRootLeft->pRight = NULL;
    insertRootLeft->pParent = builtMap.bst.root;// <f,7>
    builtMap.bst.root->pLeft = insertRootLeft;// <c,21>
    insertRootLeft->pRight = NULL;
    
    
    BST<map<char,int>::pair>::BNode* insertRootLeftLeft = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair bPair;
    bPair.first = 'b';
    bPair.second = 3;
    insertRootLeftLeft->data = bPair;
    insertRootLeftLeft->pRight = NULL;
    insertRootLeftLeft->pLeft = NULL;
    insertRootLeftLeft->pParent = insertRootLeft;// <c,21>
    insertRootLeft->pLeft = insertRootLeftLeft;// <b,3>
    
    
    map<char,int> copiedBuiltMap(builtMap);
    
    //copy should be                                                    |
    //                                                            ----<f,7>------
    //                                                            |              |
    //                                                       ---<c,21>--     --<s,10>------
    //                                                       |               |             |
    //                                                     <b,3>           <g,-5>        <z,0>
    
    assertTrue(copiedBuiltMap.bst.root != NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root != builtMap.bst.root, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->data.first == 'f', __LINE__);
    assertTrue(copiedBuiltMap.bst.root->data.second == 7, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pParent == NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight != NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft != NULL, __LINE__);
    
    //testing right sub-tree
    assertTrue(copiedBuiltMap.bst.root->pRight != builtMap.bst.root->pRight, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->data.first == 's', __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->data.second == 10, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pParent == copiedBuiltMap.bst.root, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight != NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft != NULL, __LINE__);
    
    assertTrue(copiedBuiltMap.bst.root->pRight->pRight != builtMap.bst.root->pRight->pRight, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pRight->data.first == 'z', __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pRight->data.second == 0, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pRight->pParent == copiedBuiltMap.bst.root->pRight, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pRight->pRight == NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pRight->pLeft == NULL, __LINE__);
    
    assertTrue(copiedBuiltMap.bst.root->pRight->pLeft != builtMap.bst.root->pRight->pLeft, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pLeft->data.first == 'g', __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pLeft->data.second == -5, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pLeft->pParent == copiedBuiltMap.bst.root->pRight, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pLeft->pRight == NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pRight->pLeft->pLeft == NULL, __LINE__);
    
    
    //testing left sub-tree
    assertTrue(copiedBuiltMap.bst.root->pLeft != builtMap.bst.root->pLeft, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->data.first == 'c', __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->data.second == 21, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pParent == copiedBuiltMap.bst.root, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pLeft != NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pRight == NULL, __LINE__);
    
    assertTrue(copiedBuiltMap.bst.root->pLeft->pLeft != builtMap.bst.root->pLeft->pLeft, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pLeft->data.first == 'b', __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pLeft->data.second == 3, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pLeft->pParent == copiedBuiltMap.bst.root->pLeft, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pLeft->pLeft == NULL, __LINE__);
    assertTrue(copiedBuiltMap.bst.root->pLeft->pLeft->pRight == NULL, __LINE__);
    
    /*
     * Testing map size
     */
    startTestSet("Map Size");
    assertTrue(defaultMap.size() == 0, __LINE__);
    assertTrue(builtMap.size() == 6, __LINE__);
    builtMap.bst.numElements = 243;
    assertTrue(builtMap.size() == 243, __LINE__);
    //resetting builtMap
    builtMap.bst.numElements = 6;
    
    /*
     * Testing map empty
     */
    startTestSet("Map Empty");
    assertTrue(defaultMap.empty() == true, __LINE__);
    assertTrue(builtMap.empty() == false, __LINE__);
    builtMap.bst.numElements = 0;
    assertTrue(builtMap.empty() == true, __LINE__);
    //resetting builtMap
    builtMap.bst.numElements = 6;
    
    /*
     * Testing map clear
     */
    startTestSet("Map Clear");
    unit_testing_delete_call_counter = 0;
    defaultMap.clear();
    assertTrue(defaultMap.bst.numElements == 0, __LINE__);
    assertTrue(defaultMap.bst.root == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 0, __LINE__);
    
    builtMap.clear();
    assertTrue(builtMap.bst.numElements == 0, __LINE__);
    assertTrue(builtMap.bst.root == NULL, __LINE__);
    assertTrue(unit_testing_delete_call_counter == 6, __LINE__);
    
    /*
     * Testing iterator constructors
     */
    startTestSet("Iterator Constructor");
    map<char,int>::iterator emptyIterator;
    assertTrue(emptyIterator.it.ptr == NULL, __LINE__);
    
    map<char, int>::iterator emptyIteratorCopy(emptyIterator);
    assertTrue(emptyIteratorCopy.it.ptr == NULL, __LINE__);
    //Generating small BST with the values
    //                                                           |
    //                                                  ----<j,32>------
    //                                                  |              |
    //                                            ---<e,8>----     <q,1000>------
    //                                           |            |                  |
    //                                          <a,100>      <i,-1>              <y,-3>

    

    map<char, int> iterMap;
    iterMap.bst.numElements = 5;
    iterMap.bst.root = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair jPair;
    jPair.first = 'j';
    jPair.second = 32;
    iterMap.bst.root->data = jPair;
    
    //right subtree
    //reusing insert pointers
    insertRootRight = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair qPair;
    qPair.first = 'q';
    qPair.second = 1000;
    insertRootRight->data = qPair;
    insertRootRight->pParent = iterMap.bst.root;// <j,32>
    iterMap.bst.root->pRight = insertRootRight;// <q,1000>
    insertRootRight->pLeft = NULL;
    
    insertRootRightRight = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair yPair;
    yPair.first = 'y';
    yPair.second = -3;
    insertRootRightRight->data = yPair;
    insertRootRightRight->pParent = insertRootRight;// <q,1000>
    insertRootRight->pRight = insertRootRightRight;// <y,-3>
    insertRootRight->pLeft = NULL;
    
    
    //left subtree
    insertRootLeft = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair ePair;
    ePair.first = 'e';
    ePair.second = 8;
    insertRootLeft->data = ePair;
    insertRootLeft->pParent = iterMap.bst.root;// <j,32>
    iterMap.bst.root->pLeft = insertRootLeft;// <e,8>
    
    insertRootLeftLeft = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair aPair;
    aPair.first = 'a';
    aPair.second = 100;
    insertRootLeftLeft->data = aPair;
    insertRootLeftLeft->pRight = NULL;
    insertRootLeftLeft->pLeft = NULL;
    insertRootLeftLeft->pParent = insertRootLeft;// <e,8>
    insertRootLeft->pLeft = insertRootLeftLeft;// <a,100>
    
    BST<map<char,int>::pair>::BNode* insertRootLeftRight = new BST<map<char,int>::pair>::BNode();
    map<char,int>::pair iPair;
    iPair.first = 'i';
    iPair.second = -1;
    insertRootLeftRight->data = iPair;
    insertRootLeftRight->pRight = NULL;
    insertRootLeftRight->pLeft = NULL;
    insertRootLeftRight->pParent = insertRootLeft;// <e,8>
    insertRootLeft->pRight = insertRootLeftRight;// <i,-1>
    
    // BST with the values                                              |
    //                                                            ----<j,32>------
    //                                                            |              |
    //                                                       ---<e,8>----     <q,1000>------
    //                                                       |            |                  |
    //                                                     <a,100>      <i,-1>              <y,-3>
    
    /*
     * Testing map begin
     */
    startTestSet("Map Begin");
    assertTrue(defaultMap.begin().it.ptr == NULL, __LINE__);
    assertTrue(iterMap.begin().it.ptr->data.first == 'a', __LINE__);
    assertTrue(iterMap.begin().it.ptr->data.second == 100, __LINE__);
    
    /*
     * Testing map end
     */
    startTestSet("Map End");
    assertTrue(defaultMap.end().it.ptr == NULL, __LINE__);
    assertTrue(iterMap.end().it.ptr->data.first == 'y', __LINE__);
    assertTrue(iterMap.end().it.ptr->data.second == -3, __LINE__);
    
    /*
     * Testing iterator equality operator
     */
    startTestSet("Iterator == Operator");
    map<char,int>::iterator nullNodeIterator;
    map<char,int>::iterator otherNullNodeIterator;
    
    assertTrue(nullNodeIterator == nullNodeIterator, __LINE__);
    assertTrue(otherNullNodeIterator == otherNullNodeIterator, __LINE__);
    assertTrue(nullNodeIterator == otherNullNodeIterator, __LINE__);
    
    
    map<char,int>::iterator nonNullNodeIterator;
    map<char,int>::pair somePair;
    somePair.first = '!';
    somePair.second = 567;
    BST<custom::map<char, int>::pair>::BNode commonNode;
    commonNode.data = somePair;
    nonNullNodeIterator.it.ptr = &commonNode;
    
    
    map<char,int>::iterator otherNonNullNodeIterator;
    otherNonNullNodeIterator.it.ptr = &commonNode;
    assertTrue(nonNullNodeIterator == otherNonNullNodeIterator, __LINE__);
    
    /*
     * Testing iterator not-equal operator
     */
    startTestSet("Iterator != Operator");
    //reusing nullNodeIterator, nonNullNodeIterator, and otherNonNullNodeIterator
    
    map<char,int>::pair someOtherPair;
    someOtherPair.first = '$';
    someOtherPair.second = 567;
    BST<custom::map<char, int>::pair>::BNode someOtherNode;
    someOtherNode.data = someOtherPair;
    otherNonNullNodeIterator.it.ptr = &someOtherNode;
    assertTrue(otherNonNullNodeIterator != nonNullNodeIterator, __LINE__);
    assertTrue(!(nullNodeIterator != nullNodeIterator), __LINE__);
    assertTrue(!(nonNullNodeIterator != nonNullNodeIterator), __LINE__);
    //resetting
    otherNonNullNodeIterator.it.ptr = nonNullNodeIterator.it.ptr;
    assertTrue(!(otherNonNullNodeIterator != nonNullNodeIterator), __LINE__);
    
    /*
     * Testing iterator assignment operator
     */
    startTestSet("Iterator = Operator");
    //reusing nonNullNodeIterator
    map<char,int>::iterator assignedTo = nonNullNodeIterator;
    assertTrue(assignedTo.it.ptr != NULL, __LINE__);
    assertTrue(assignedTo.it.ptr == nonNullNodeIterator.it.ptr, __LINE__);
    
    assignedTo = emptyIterator;
    assertTrue(assignedTo.it.ptr == NULL, __LINE__);
    
    /*
     * Testing iterator dereference operator
     */
    startTestSet("Iterator * Operator");
    try{
        *emptyIterator;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Dereferencing null node.") == 0, __LINE__);
    }
    map<char,int>::pair retrievedPair = *nonNullNodeIterator;
    assertTrue(retrievedPair.first == nonNullNodeIterator.it.ptr->data.first, __LINE__);
    assertTrue(retrievedPair.second == nonNullNodeIterator.it.ptr->data.second, __LINE__);
    
    /*
     * Testing iterator pre-increment operator
     */
    startTestSet("Iterator Pre-Increment Operator");
    // BST with the values                                              |
    //                                                            ----<j,32>------
    //                                                            |              |
    //                                                       ---<i,-1>----     <q,1000>------
    //                                                       |            |                  |
    //                                                     <a,100>      <e,8>              <y,-3>
    
    //reusing iterMap
    map<char, int>::iterator incrementIterator;
    incrementIterator.it.ptr = NULL;
    try{
        ++incrementIterator;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Incrementing null node.") == 0, __LINE__);
    }
    //beginning of tree test
    incrementIterator.it.ptr = insertRootLeftLeft;// <a,100>
    assertTrue((++incrementIterator).it.ptr == insertRootLeft, __LINE__);// <e,8>
    //end of tree test
    incrementIterator.it.ptr = insertRootRightRight;// <y,-3>
    assertTrue((++incrementIterator).it.ptr == NULL, __LINE__);
    //middle of tree test
    incrementIterator.it.ptr = insertRootLeft;// <e,8>
    assertTrue((++incrementIterator).it.ptr == insertRootLeftRight, __LINE__); // <i,-1>;
    
    /*
     * Testing iterator post increment operator
     */
    startTestSet("Iterator Post Increment Operator");
    
    // BST with the values                                              |
    //                                                            ----<j,32>------
    //                                                            |              |
    //                                                       ---<e,8>----     <q,1000>------
    //                                                       |            |                  |
    //                                                     <a,100>      <i,-1>              <y,-3>
    
    //reusing iterMap
    incrementIterator.it.ptr = NULL;
    try{
        incrementIterator++;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Incrementing null node.") == 0, __LINE__);
    }
    //reusing iterMap
    //beginning of tree test
    incrementIterator.it.ptr = insertRootLeftLeft;// <a,100>
    assertTrue((incrementIterator++).it.ptr == insertRootLeftLeft, __LINE__);// <a,100>
    assertTrue(incrementIterator.it.ptr == insertRootLeft, __LINE__);// <e,8>
    //end of tree test
    incrementIterator.it.ptr = insertRootRightRight;// <y,-3>
    assertTrue((incrementIterator++).it.ptr == insertRootRightRight, __LINE__);// <y,-3>
    assertTrue(incrementIterator.it.ptr == NULL, __LINE__);
    //middle of tree test
    incrementIterator.it.ptr = insertRootLeft;// <e,8>
    assertTrue((incrementIterator++).it.ptr == insertRootLeft, __LINE__);// <e,8>
    assertTrue(incrementIterator.it.ptr == insertRootLeftRight, __LINE__);// <i,-1>
    
    /*
     * Testing iterator pre-decrement operator
     */
    startTestSet("Iterator Pre-Decrement Operator");
    // BST with the values                                              |
    //                                                            ----<j,32>------
    //                                                            |              |
    //                                                       ---<e,8>----     <q,1000>------
    //                                                       |            |                  |
    //                                                     <a,100>      <i,-1>              <y,-3>
    
    //reusing iterMap
    map<char, int>::iterator decrementIterator;
    decrementIterator.it.ptr = NULL;
    try{
        --decrementIterator;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Decrementing null node.") == 0, __LINE__);
    }
    //beginning of tree test
    decrementIterator.it.ptr = insertRootLeftLeft;// <a,100>
    assertTrue((--decrementIterator).it.ptr == NULL, __LINE__);
    //end of tree test
    decrementIterator.it.ptr = insertRootRightRight;// <y,-3>
    assertTrue((--decrementIterator).it.ptr == insertRootRight, __LINE__);
    //middle of tree test
    decrementIterator.it.ptr = insertRootLeftRight;//(12)
    assertTrue((--decrementIterator).it.ptr == insertRootLeft, __LINE__);
    
    /*
     * Testing iterator post decrement operator
     */
    startTestSet("Iterator Post Decrement Operator");
    // BST with the values                                              |
    //                                                            ----<j,32>------
    //                                                            |              |
    //                                                       ---<i,-1>----     <q,1000>------
    //                                                       |            |                  |
    //                                                     <a,100>      <e,8>              <y,-3>
    
    //reusing iterMap
    decrementIterator.it.ptr = NULL;
    try{
        decrementIterator--;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: Decrementing null node.") == 0, __LINE__);
    }
    //beginning of tree test
    decrementIterator.it.ptr = insertRootLeftLeft;// <a,100>
    assertTrue((decrementIterator--).it.ptr == insertRootLeftLeft, __LINE__);// <a,100>
    assertTrue(decrementIterator.it.ptr == NULL, __LINE__);
    //end of tree test
    decrementIterator.it.ptr = insertRootRightRight;// <y,-3>
    assertTrue((decrementIterator--).it.ptr == insertRootRightRight, __LINE__);
    //middle of tree test
    decrementIterator.it.ptr = insertRootLeftRight;// <e,8>
    assertTrue((decrementIterator--).it.ptr == insertRootLeftRight, __LINE__);// <e,8>
    assertTrue(decrementIterator.it.ptr == insertRootLeft, __LINE__);// <i,-1>
    
    /*
     * Testing map find
     */
    startTestSet("Map Find");
    assertTrue((*iterMap.find('j')).second == 32, __LINE__);
    assertTrue((*iterMap.find('i')).second == -1, __LINE__);
    assertTrue((*iterMap.find('a')).second == 100, __LINE__);
    assertTrue((*iterMap.find('e')).second == 8, __LINE__);
    assertTrue((*iterMap.find('q')).second == 1000, __LINE__);
    assertTrue((*iterMap.find('y')).second == -3, __LINE__);
    
    // for fun
    assertTrue((*iterMap.find('j')).first == 'j', __LINE__);
    assertTrue(iterMap.find('*').it.ptr == NULL, __LINE__); // * is not in tree
    
    /*
     * Testing square bracket operator
     */
    startTestSet("Map [] Access Operator");
    //reusing iterMap
    
    // BST should be                                          |
    //                                                  ----<j,32>------
    //                                                  |              |
    //                                             ---<e,8>----     <q,1000>------
    //                                            |            |                  |
    //                                           <a,100>      <i,-1>              <y,-3>
    //beginning square bracket operator accessor test
    assertTrue(iterMap['j'] == 32, __LINE__);
    assertTrue(iterMap['i'] == -1, __LINE__);
    assertTrue(iterMap['a'] == 100, __LINE__);
    assertTrue(iterMap['e'] == 8, __LINE__);
    assertTrue(iterMap['q'] == 1000, __LINE__);
    assertTrue(iterMap['y'] == -3, __LINE__);
    
    startTestSet("Map [] Mutate Operator");
    // beginning square bracket operator mutator test
    iterMap['j'] = 15;
    iterMap['i'] = 45;
    iterMap['a'] = 75;
    iterMap['e'] = 25;
    iterMap['q'] = 10000;
    iterMap['y'] = -300;
    assertTrue(iterMap.bst.root->data.second == 15, __LINE__);
    assertTrue(iterMap.bst.root->pLeft->data.second == 25, __LINE__);
    assertTrue(iterMap.bst.root->pLeft->pLeft->data.second == 75, __LINE__);
    assertTrue(iterMap.bst.root->pLeft->pRight->data.second == 45, __LINE__);
    assertTrue(iterMap.bst.root->pRight->data.second == 10000, __LINE__);
    assertTrue(iterMap.bst.root->pRight->pRight->data.second == -300, __LINE__);
    
    startTestSet("Map [] Insert Operator");
    // beginning square bracket operator insert test
    iterMap['z'] = 35;
    iterMap[';'] = 95;
    assertTrue(iterMap.bst.root->pRight->pRight->pRight->data.first == 'z', __LINE__);
    assertTrue(iterMap.bst.root->pRight->pRight->pRight->data.second == 35, __LINE__);
    assertTrue(iterMap.bst.root->pLeft->pLeft->pLeft->data.first == ';', __LINE__);
    assertTrue(iterMap.bst.root->pLeft->pLeft->pLeft->data.second == 95, __LINE__);
    
    // ToDo: Write string test.
    
    
    generateTestingReport();
}
