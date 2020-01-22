/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/15/18.
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
int asserts_existing = 127;

#include <cstring>
#include "vector.h"
#include "unit_testing.h"

using std::string;
using namespace custom;



int main(int argc, const char* argv[]) {
    
    /*
     * Testing default constructor
     */
    startTestSet("Default Constructor");
    vector <int> defaultVector;
    assertTrue(defaultVector.numCapacity == 0, __LINE__);
    assertTrue(defaultVector.numElements == 0, __LINE__);
    assertTrue(defaultVector.buffer == NULL, __LINE__);
    
    /*
     * Testing sized vector constructor
     */
    startTestSet("Sized Constructor");
    try{
        vector<int> badSizeVector(-3);
        assertTrue(false, __LINE__);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: vector sizes must be greater than 0.") == 0, __LINE__);
    }
    
    vector <int> sizedVector(4);
    assertTrue(sizedVector.numCapacity == 4, __LINE__);
    assertTrue(sizedVector.numElements == 4, __LINE__);
    assertTrue(sizedVector.buffer != NULL, __LINE__);
    assertTrue(sizedVector.buffer[0] == 0, __LINE__);
    assertTrue(sizedVector.buffer[1] == 0, __LINE__);
    assertTrue(sizedVector.buffer[2] == 0, __LINE__);
    assertTrue(sizedVector.buffer[3] == 0, __LINE__);
    
    /*
     * Testing sized and filled vector constructor
     */
    startTestSet("Sized Constructor with Default Value");
    try{
        vector<int>zeroSizedFilledVector(0,15);
        assertTrue(false, __LINE__);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: vector sizes must be greater than 0.") == 0, __LINE__);
    }
    vector<int>filledVector(4,0);
    assertTrue(filledVector.buffer != NULL, __LINE__);
    assertTrue(filledVector.numElements == 4, __LINE__);
    assertTrue(filledVector.numCapacity == 4, __LINE__);
    assertTrue(filledVector.buffer[0] == 0, __LINE__);
    assertTrue(filledVector.buffer[1] == 0, __LINE__);
    assertTrue(filledVector.buffer[2] == 0, __LINE__);
    assertTrue(filledVector.buffer[3] == 0, __LINE__);
    
    /*
     * Testing Size
     */
    startTestSet("Size");
    vector <int> sizeTestVector;
    
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 4;
    assertTrue(sizeTestVector.size() == 4, __LINE__);
    
    /*
     * Testing Capacity
     */
    startTestSet("Capacity");
    assertTrue(sizeTestVector.capacity() == 8, __LINE__);
    sizeTestVector.numCapacity = 0;
    assertTrue(sizeTestVector.capacity() == 0, __LINE__);
    
    /*
     * Resetting for further use
     */
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 0;
    sizeTestVector.buffer = new int[sizeTestVector.numCapacity];
    for (int i = 0; i < sizeTestVector.numCapacity; i++) {
        sizeTestVector.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    startTestSet("Clear");
    sizeTestVector.clear();
    assertTrue(sizeTestVector.numCapacity == 8, __LINE__);
    assertTrue(sizeTestVector.numElements == 0, __LINE__);
    assertTrue(sizeTestVector.buffer != NULL, __LINE__);
    
    /*
     * Testing Empty
     */
    startTestSet("Empty");
    sizeTestVector.numElements = 3;
    assertTrue(!sizeTestVector.empty(), __LINE__);
    
    sizeTestVector.numElements = 0;
    
    assertTrue(sizeTestVector.empty(), __LINE__);
    
    /*
     * Testing resize
     */
    startTestSet("Negative Resize");
    vector<int> emptyResizeVector;
    emptyResizeVector.resize(-1);
    assertTrue(emptyResizeVector.numCapacity == 0, __LINE__);
    assertTrue(emptyResizeVector.numElements == 0, __LINE__);
    assertTrue(emptyResizeVector.buffer == NULL, __LINE__);
    
    startTestSet("Default Vector Resize");
    emptyResizeVector.resize(7);
    assertTrue(emptyResizeVector.numCapacity == 7, __LINE__);
    assertTrue(emptyResizeVector.numElements == 0, __LINE__);
    assertTrue(emptyResizeVector.buffer != NULL, __LINE__);
    
    startTestSet("Resize");
    vector <int> resizeVector;
    resizeVector.buffer = new int[5];
    resizeVector.numCapacity = 5;
    resizeVector.numElements = 5;
    resizeVector.buffer[0] = 7;
    resizeVector.buffer[1] = 12;
    resizeVector.buffer[2] = 10;
    resizeVector.buffer[3] = 9;
    resizeVector.buffer[4] = 8;
    
    int *theBuffer = resizeVector.buffer;
    resizeVector.resize(10);
    assertTrue(theBuffer != resizeVector.buffer, __LINE__);
    assertTrue(resizeVector.numCapacity == 10, __LINE__);
    assertTrue(resizeVector.numElements == 5, __LINE__);
    assertTrue(resizeVector.buffer[0] == 7, __LINE__);
    assertTrue(resizeVector.buffer[1] == 12, __LINE__);
    assertTrue(resizeVector.buffer[2] == 10, __LINE__);
    assertTrue(resizeVector.buffer[3] == 9, __LINE__);
    assertTrue(resizeVector.buffer[4] == 8, __LINE__);
    
    theBuffer = resizeVector.buffer;
    resizeVector.resize(2);
    assertTrue(theBuffer != resizeVector.buffer, __LINE__);
    assertTrue(resizeVector.numCapacity == 2, __LINE__);
    assertTrue(resizeVector.numElements == 2, __LINE__);
    assertTrue(resizeVector.buffer[0] == 7, __LINE__);
    assertTrue(resizeVector.buffer[1] == 12, __LINE__);
    
    theBuffer = resizeVector.buffer;
    resizeVector.resize(0);
    assertTrue(resizeVector.numCapacity == 0, __LINE__);
    assertTrue(resizeVector.numElements == 0, __LINE__);
    assertTrue(resizeVector.buffer == NULL, __LINE__);
    
    
    /*
     * Testing push_back with no resizing
     */
    startTestSet("Push Back First Element");
    vector <int> pushBackVector(5);
    int * tempBuffer = pushBackVector.buffer;
    pushBackVector.push_back(1);
    assertTrue(tempBuffer != pushBackVector.buffer, __LINE__);
    assertTrue(pushBackVector.numCapacity == 10, __LINE__);
    assertTrue(pushBackVector.numElements == 6, __LINE__);
    assertTrue(pushBackVector.buffer[0] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[1] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[2] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[3] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[4] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[5] == 1, __LINE__);
    
    startTestSet("Push Back Second Element");
    pushBackVector.push_back(3);
    assertTrue(pushBackVector.numCapacity == 10, __LINE__);
    assertTrue(pushBackVector.numElements == 7, __LINE__);
    assertTrue(pushBackVector.buffer[0] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[1] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[2] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[3] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[4] == 0, __LINE__);
    assertTrue(pushBackVector.buffer[5] == 1, __LINE__);
    assertTrue(pushBackVector.buffer[6] == 3, __LINE__);
    
    
    
    
    /*
     * Testing Accessor
     */
    startTestSet("[] Accessor Operator");
    vector <int> beginEndVector;
    beginEndVector.buffer = new int[6];
    beginEndVector.buffer[0] = -500;
    beginEndVector.buffer[1] = 0;
    beginEndVector.buffer[2] = 7;
    beginEndVector.buffer[3] = 13;
    beginEndVector.buffer[4] = 23;
    beginEndVector.numCapacity = 6;
    beginEndVector.numElements = 5;
    assertTrue(beginEndVector[0] == -500, __LINE__);
    
    try{
        beginEndVector[-1];
        assertTrue(false, __LINE__);
    } catch (const char * message) {
        assertTrue(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0, __LINE__);
    }
    
    
    try{
        beginEndVector[6];
        assertTrue(false, __LINE__);
    } catch (const char * message) {
        assertTrue(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0, __LINE__);
    }
    
    
    vector <int> emptyVector;
    try{
        emptyVector[0];
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0, __LINE__);
    }
    
    
    /*
     * Testing Mutator
     */
    startTestSet("[] Mutator Operator");
    beginEndVector[0] = 35;
    assertTrue(beginEndVector.buffer[0] == 35, __LINE__);
    
    /*
     * Testing = operator and copy constructor
     */
    startTestSet("(full) = Operator");
    vector <int> vectorToCopy;
    vectorToCopy.numCapacity = 8;
    vectorToCopy.numElements = 8;
    vectorToCopy.buffer = new int[vectorToCopy.numCapacity];
    for (int i = 0; i < vectorToCopy.numCapacity; i++) {
        vectorToCopy.buffer[i]=i*i+1;
    }
    vector <int> vectorAssignedCopy;
    vectorAssignedCopy = vectorToCopy;
    assertTrue(vectorAssignedCopy.numCapacity == 8, __LINE__);
    assertTrue(vectorAssignedCopy.numElements == 8, __LINE__);
    assertTrue(vectorAssignedCopy.buffer != vectorToCopy.buffer, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[0] == 1, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[1] == 2, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[2] == 5, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[3] == 10, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[4] == 17, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[5] == 26, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[6] == 37, __LINE__);
    assertTrue(vectorAssignedCopy.buffer[7] == 50, __LINE__);
    
    startTestSet("(Full) Copy Constructor");
    vector <int> vectorCopy(vectorToCopy);
    assertTrue(vectorCopy.numCapacity == 8, __LINE__);
    assertTrue(vectorCopy.numElements == 8, __LINE__);
    assertTrue(vectorCopy.buffer != vectorToCopy.buffer, __LINE__);
    assertTrue(vectorCopy.numCapacity == 8, __LINE__);
    assertTrue(vectorCopy.buffer[0] == 1, __LINE__);
    assertTrue(vectorCopy.buffer[1] == 2, __LINE__);
    assertTrue(vectorCopy.buffer[2] == 5, __LINE__);
    assertTrue(vectorCopy.buffer[3] == 10, __LINE__);
    assertTrue(vectorCopy.buffer[4] == 17, __LINE__);
    assertTrue(vectorCopy.buffer[5] == 26, __LINE__);
    assertTrue(vectorCopy.buffer[6] == 37, __LINE__);
    assertTrue(vectorCopy.buffer[7] == 50, __LINE__);
    
    /*
     * Resetting to not full vector
     */
    startTestSet("(Not full) = Operator");
    vectorToCopy.numElements = 3;
    
    vector <int> notFullVectorAssignedCopy;
    notFullVectorAssignedCopy = vectorToCopy;
    assertTrue(notFullVectorAssignedCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullVectorAssignedCopy.numElements == 3, __LINE__);
    assertTrue(notFullVectorAssignedCopy.buffer != vectorToCopy.buffer, __LINE__);
    assertTrue(notFullVectorAssignedCopy.buffer[0] == 1, __LINE__);
    assertTrue(notFullVectorAssignedCopy.buffer[1] == 2, __LINE__);
    assertTrue(notFullVectorAssignedCopy.buffer[2] == 5, __LINE__);
    
    startTestSet("(Not Full) Copy Constructor");
    vector <int> notFullVectorCopy(vectorToCopy);
    assertTrue(notFullVectorCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullVectorCopy.numElements == 3, __LINE__);
    assertTrue(notFullVectorCopy.buffer != vectorToCopy.buffer, __LINE__);
    assertTrue(notFullVectorCopy.buffer[0] == 1, __LINE__);
    assertTrue(notFullVectorCopy.buffer[1] == 2, __LINE__);
    assertTrue(notFullVectorCopy.buffer[2] == 5, __LINE__);
    
    /*
     * Testing Raw Iterators
     */
    startTestSet("Raw Iterator");
    vector<int>::iterator nullIt = vector<int>::iterator();
    assertTrue(nullIt.ptr == NULL, __LINE__);
    int someInt = 3;
    int *someIntPtr = &someInt;
    vector<int>::iterator intPtr = vector<int>::iterator(&someInt);
    assertTrue(intPtr.ptr == someIntPtr, __LINE__);
    
    
    /*
     * Testing begin and end
     */
    startTestSet("Iterator Begin and End");
    vector<int>::iterator emptyVectorBeginIt = emptyVector.begin();
    assertTrue(emptyVectorBeginIt.ptr == NULL, __LINE__);
    
    
    vector<int>::iterator emptyVectorEndIt = emptyVector.end();
    assertTrue(emptyVectorEndIt.ptr == NULL, __LINE__);
    
    vector<int>::iterator notFullVectorBeginIt = notFullVectorCopy.begin();
    assertTrue(notFullVectorCopy.buffer == notFullVectorBeginIt.ptr, __LINE__);
    
    
    vector<int>::iterator notFullVectorEndIt = notFullVectorCopy.end();
    assertTrue(notFullVectorCopy.buffer+notFullVectorCopy.numElements == notFullVectorEndIt.ptr, __LINE__);
    
    /*
     * Testing Iterator Assignment Operator
     */
    startTestSet("Iterator = Operator");
    vector<int>::iterator iteratorToAssign;
    iteratorToAssign.ptr = someIntPtr;
    vector<int>::iterator assignedToIterator;
    assignedToIterator = iteratorToAssign;
    assertTrue(assignedToIterator.ptr == someIntPtr, __LINE__);
    
    /*
     * Testing Iterator Comparison Operators
     */
    startTestSet("Iterator Comparison Operator");
    assertTrue(iteratorToAssign == assignedToIterator, __LINE__);
    //reset
    int someOtherInt = 4;
    int* someOtherIntPtr = &someOtherInt;
    assignedToIterator.ptr = someOtherIntPtr;
    assertTrue(iteratorToAssign != assignedToIterator, __LINE__);
    
    /*
     * Testing Dereference Operator
     */
    startTestSet("Iterator * Operator");
    assertTrue(*assignedToIterator == 4, __LINE__);
    
    /*
     * Testing iterator incrementor
     */
    startTestSet("Iterator Pre and Post-Increment");
    assertTrue((nullIt++).ptr == NULL, __LINE__);
    assertTrue((++nullIt).ptr == NULL, __LINE__);
    
    //setting to the beginning of buffer
    vector<int>::iterator fakeBeginIt = vector<int>::iterator();
    fakeBeginIt.ptr = notFullVectorCopy.buffer;
    
    assertTrue((fakeBeginIt++).ptr == notFullVectorCopy.buffer, __LINE__);
    //reset
    fakeBeginIt.ptr = notFullVectorCopy.buffer;
    assertTrue((++fakeBeginIt).ptr == notFullVectorCopy.buffer+1, __LINE__);
    
    
    //setting to the end of buffer
    startTestSet("Iterator Pre and Post-Decrement Operator");
    vector<int>::iterator fakeEndIt = vector<int>::iterator();
    fakeEndIt.ptr = notFullVectorCopy.buffer+notFullVectorCopy.numElements;
    assertTrue((fakeEndIt--).ptr == notFullVectorCopy.buffer+notFullVectorCopy.numElements, __LINE__);
    //reset
    fakeEndIt.ptr = notFullVectorCopy.buffer+notFullVectorCopy.numElements;
    assertTrue((--fakeEndIt).ptr == notFullVectorCopy.buffer+notFullVectorCopy.numElements - 1, __LINE__);
    
    
    
    /*
     * Testing push_back for Non-Integer Vector Behavior (Just to Make Sure vector Works For Other Types)
     */
    startTestSet("Can Hold Strings");
    vector <string> stringVector;
    
    stringVector.push_back("Hello");
    stringVector.push_back("It's me");
    stringVector.push_back("I was wondering");
    assertTrue(stringVector.numCapacity == 4, __LINE__);
    assertTrue(stringVector.buffer[0] == "Hello", __LINE__);
    assertTrue(stringVector.buffer[1] == "It's me", __LINE__);
    assertTrue(stringVector.buffer[2] == "I was wondering", __LINE__);
    
    generateTestingReport();
    
    return 0;
}
