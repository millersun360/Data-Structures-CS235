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
 * the percentage of assertTrues found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING
//Do not change the next line without instructor approval.
//To do so is cheating and, when found, will result in consequences.
int asserts_existing = 112;

#include <cstring>
#include "stack.h"
#include "unit_testing.h"

using namespace custom;



int main(int argc, const char* argv[]) {
    
    /*
     * Testing default constructor
     */
    startTestSet("Default Constructor");
    stack <int> defaultStack;
    assertTrue(defaultStack.numCapacity == 0, __LINE__);
    assertTrue(defaultStack.numElements == 0, __LINE__);
    assertTrue(defaultStack.buffer == NULL, __LINE__);
    
    
    /*
     * Testing Size
     */
    startTestSet("Size");
    stack <int> sizeTestStack;
    
    sizeTestStack.numCapacity = 8;
    sizeTestStack.numElements = 4;
    assertTrue(sizeTestStack.size() == 4, __LINE__);
    
    /*
     * Testing Capacity
     */
    startTestSet("Capacity");
    assertTrue(sizeTestStack.capacity() == 8, __LINE__);
    sizeTestStack.numCapacity = 0;
    assertTrue(sizeTestStack.capacity() == 0, __LINE__);
    
    /*
     * Resetting for further use
     */
    sizeTestStack.numCapacity = 8;
    sizeTestStack.numElements = 0;
    sizeTestStack.buffer = new int[sizeTestStack.numCapacity];
    for (int i = 0; i < sizeTestStack.numCapacity; i++) {
        sizeTestStack.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    startTestSet("Clear");
    sizeTestStack.clear();
    assertTrue(sizeTestStack.numCapacity == 8, __LINE__);
    assertTrue(sizeTestStack.numElements == 0, __LINE__);
    assertTrue(sizeTestStack.buffer != NULL, __LINE__);
    
    /*
     * Testing Empty
     */
    startTestSet("Empty");
    sizeTestStack.numElements = 3;
    assertTrue(!sizeTestStack.empty(), __LINE__);
    
    sizeTestStack.numElements = 0;
    
    assertTrue(sizeTestStack.empty(), __LINE__);
    
    /*
     * Testing resize
     */
    startTestSet("Negative Resize");
    stack<int> emptyResizeStack;
    emptyResizeStack.resize(-1);
    assertTrue(emptyResizeStack.numCapacity == 0, __LINE__);
    assertTrue(emptyResizeStack.numElements == 0, __LINE__);
    assertTrue(emptyResizeStack.buffer == NULL, __LINE__);
    
    startTestSet("Default Stack Resize");
    emptyResizeStack.resize(7);
    assertTrue(emptyResizeStack.numCapacity == 7, __LINE__);
    assertTrue(emptyResizeStack.numElements == 0, __LINE__);
    assertTrue(emptyResizeStack.buffer != NULL, __LINE__);
    
    startTestSet("Resize");
    stack <int> resizeStack;
    resizeStack.buffer = new int[5];
    resizeStack.numCapacity = 5;
    resizeStack.numElements = 5;
    resizeStack.buffer[0] = 7;
    resizeStack.buffer[1] = 12;
    resizeStack.buffer[2] = 10;
    resizeStack.buffer[3] = 9;
    resizeStack.buffer[4] = 8;
    
    int *theBuffer = resizeStack.buffer;
    resizeStack.resize(10);
    assertTrue(theBuffer != resizeStack.buffer, __LINE__);
    assertTrue(resizeStack.numCapacity == 10, __LINE__);
    assertTrue(resizeStack.numElements == 5, __LINE__);
    assertTrue(resizeStack.buffer[0] == 7, __LINE__);
    assertTrue(resizeStack.buffer[1] == 12, __LINE__);
    assertTrue(resizeStack.buffer[2] == 10, __LINE__);
    assertTrue(resizeStack.buffer[3] == 9, __LINE__);
    assertTrue(resizeStack.buffer[4] == 8, __LINE__);
    
    theBuffer = resizeStack.buffer;
    resizeStack.resize(2);
    assertTrue(theBuffer != resizeStack.buffer, __LINE__);
    assertTrue(resizeStack.numCapacity == 2, __LINE__);
    assertTrue(resizeStack.numElements == 2, __LINE__);
    assertTrue(resizeStack.buffer[0] == 7, __LINE__);
    assertTrue(resizeStack.buffer[1] == 12, __LINE__);
    
    theBuffer = resizeStack.buffer;
    resizeStack.resize(0);
    assertTrue(resizeStack.numCapacity == 0, __LINE__);
    assertTrue(resizeStack.numElements == 0, __LINE__);
    assertTrue(resizeStack.buffer == NULL, __LINE__);
    
    
    /*
     * Testing push with resizing
     */
    startTestSet("Push First Element");
    stack <int> pushStack;
    theBuffer = pushStack.buffer;
    pushStack.push(1);
    assertTrue(pushStack.numCapacity == 1, __LINE__);
    assertTrue(pushStack.numElements == 1, __LINE__);
    assertTrue(theBuffer != pushStack.buffer, __LINE__);
    assertTrue(pushStack.buffer[0] == 1, __LINE__);
    
    startTestSet("Push Second Element");
    theBuffer = pushStack.buffer;
    pushStack.push(3);
    assertTrue(pushStack.numCapacity == 2, __LINE__);
    assertTrue(pushStack.numElements == 2, __LINE__);
    assertTrue(theBuffer != pushStack.buffer, __LINE__);
    assertTrue(pushStack.buffer[0] == 1, __LINE__);
    assertTrue(pushStack.buffer[1] == 3, __LINE__);
    
    startTestSet("Push Third Element");
    theBuffer = pushStack.buffer;
    pushStack.push(5);
    assertTrue(pushStack.numCapacity == 4, __LINE__);
    assertTrue(pushStack.numElements == 3, __LINE__);
    assertTrue(theBuffer != pushStack.buffer, __LINE__);
    assertTrue(pushStack.buffer[0] == 1, __LINE__);
    assertTrue(pushStack.buffer[1] == 3, __LINE__);
    assertTrue(pushStack.buffer[2] == 5, __LINE__);
    
    startTestSet("Push Fourth Element");
    theBuffer = pushStack.buffer;
    pushStack.push(7);
    assertTrue(pushStack.numCapacity == 4, __LINE__);
    assertTrue(pushStack.numElements == 4, __LINE__);
    assertTrue(theBuffer == pushStack.buffer, __LINE__);
    assertTrue(pushStack.buffer[0] == 1, __LINE__);
    assertTrue(pushStack.buffer[1] == 3, __LINE__);
    assertTrue(pushStack.buffer[2] == 5, __LINE__);
    assertTrue(pushStack.buffer[3] == 7, __LINE__);
    
    
    
    /*
     * Testing pop
     */
    startTestSet("Pop");
    stack<int> popStack;
    popStack.pop();
    assertTrue(popStack.numElements == 0, __LINE__);
    assertTrue(popStack.numCapacity == 0, __LINE__);
    assertTrue(popStack.buffer == NULL, __LINE__);
    
    /*
     * Simulate situation where one push has been done.
     */
    popStack.numElements = 1;
    popStack.numCapacity = 1;
    popStack.buffer = new int[1];
    popStack.buffer[0] = 3;
    
    popStack.pop();
    assertTrue(popStack.numElements == 0, __LINE__);
    assertTrue(popStack.numCapacity == 1, __LINE__);
    assertTrue(popStack.buffer != NULL, __LINE__);
    assertTrue(popStack.buffer[0] == 3, __LINE__);//this value is abandoned, but not replaced by pop.
    
    /*
     * Simulate situation where elements != capacity.
     */
    delete [] popStack.buffer;
    popStack.buffer = new int[5];
    popStack.numElements = 3;
    popStack.numCapacity = 5;
    popStack.buffer[0] = 1;
    popStack.buffer[1] = -7;
    popStack.buffer[2] = 3861;
    
    popStack.pop();
    assertTrue(popStack.numElements == 2, __LINE__);
    assertTrue(popStack.numCapacity == 5, __LINE__);
    assertTrue(popStack.buffer != NULL, __LINE__);
    assertTrue(popStack.buffer[0] == 1, __LINE__);
    assertTrue(popStack.buffer[1] == -7, __LINE__);
    assertTrue(popStack.buffer[2] == 3861, __LINE__);
    
    
    /*
     * Testing top getter
     */
    startTestSet("Top Accessor");
    stack<int> topStack;
    try{
        int topValue = topStack.top();
        topValue = 18;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: asking for top of empty stack.") == 0, __LINE__);
    }
    //simulating full buffer
    topStack.numElements = 5;
    topStack.numCapacity = 5;
    topStack.buffer = new int[5];
    topStack.buffer[0] = 1;
    topStack.buffer[1] = -7;
    topStack.buffer[2] = 3861;
    topStack.buffer[3] = 0;
    topStack.buffer[4] = 18;
    assertTrue(topStack.top() == 18, __LINE__);
    //simulating non-full buffer
    topStack.numElements = 3;
    assertTrue(topStack.top() == 3861, __LINE__);
    
    int topValue = topStack.top();
    topValue = 34;
    assertTrue(topStack.top() == 3861, __LINE__);
    
    /*
     * Testing top setter
     */
    //reseting
    delete [] topStack.buffer;
    topStack.buffer = NULL;
    topStack.numElements = 0;
    topStack.numCapacity = 0;
    try{
        topStack.top() = 3;
        assertTrue(false, __LINE__);
    } catch (const char* message) {
        strcmp(message, "Error: asking for top of empty stack.");
    }
    //simulating full buffer
    topStack.numElements = 5;
    topStack.numCapacity = 5;
    topStack.buffer = new int[5];
    topStack.buffer[0] = 1;
    topStack.buffer[1] = -7;
    topStack.buffer[2] = 3861;
    topStack.buffer[3] = 0;
    topStack.buffer[4] = 18;
    topStack.top() = -13;
    assertTrue(topStack.top() == -13, __LINE__);
    //simulating non-full buffer
    topStack.numElements = 3;
    topStack.top() = 421;
    assertTrue(topStack.top() == 421, __LINE__);
    
    /*
     * Testing = operator and copy constructor
     */
    startTestSet("(full) = Operator");
    stack <int> stackToCopy;
    stackToCopy.numCapacity = 8;
    stackToCopy.numElements = 8;
    stackToCopy.buffer = new int[stackToCopy.numCapacity];
    for (int i = 0; i < stackToCopy.numCapacity; i++) {
        stackToCopy.buffer[i]=i*i+1;
    }
    stack <int> stackAssignedCopy;
    stackAssignedCopy = stackToCopy;
    assertTrue(stackAssignedCopy.numCapacity == 8, __LINE__);
    assertTrue(stackAssignedCopy.numElements == 8, __LINE__);
    assertTrue(stackAssignedCopy.buffer != stackToCopy.buffer, __LINE__);
    assertTrue(stackAssignedCopy.buffer[0] == 1, __LINE__);
    assertTrue(stackAssignedCopy.buffer[1] == 2, __LINE__);
    assertTrue(stackAssignedCopy.buffer[2] == 5, __LINE__);
    assertTrue(stackAssignedCopy.buffer[3] == 10, __LINE__);
    assertTrue(stackAssignedCopy.buffer[4] == 17, __LINE__);
    assertTrue(stackAssignedCopy.buffer[5] == 26, __LINE__);
    assertTrue(stackAssignedCopy.buffer[6] == 37, __LINE__);
    assertTrue(stackAssignedCopy.buffer[7] == 50, __LINE__);
    
    
    startTestSet("(Full) Copy Constructor");
    stack <int> stackCopy(stackToCopy);
    assertTrue(stackCopy.numCapacity == 8, __LINE__);
    assertTrue(stackCopy.numElements == 8, __LINE__);
    assertTrue(stackCopy.buffer != stackToCopy.buffer, __LINE__);
    assertTrue(stackCopy.numCapacity == 8, __LINE__);
    assertTrue(stackCopy.buffer[0] == 1, __LINE__);
    assertTrue(stackCopy.buffer[1] == 2, __LINE__);
    assertTrue(stackCopy.buffer[2] == 5, __LINE__);
    assertTrue(stackCopy.buffer[3] == 10, __LINE__);
    assertTrue(stackCopy.buffer[4] == 17, __LINE__);
    assertTrue(stackCopy.buffer[5] == 26, __LINE__);
    assertTrue(stackCopy.buffer[6] == 37, __LINE__);
    assertTrue(stackCopy.buffer[7] == 50, __LINE__);
    
    /*
     * Resetting to not full stack
     */
    startTestSet("(Not Full) = Operator");
    stackToCopy.numElements = 3;
    
    stack <int> notFullStackAssignedCopy;
    notFullStackAssignedCopy = stackToCopy;
    assertTrue(notFullStackAssignedCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullStackAssignedCopy.numElements == 3, __LINE__);
    assertTrue(notFullStackAssignedCopy.buffer != stackToCopy.buffer, __LINE__);
    assertTrue(notFullStackAssignedCopy.buffer[0] == 1, __LINE__);
    assertTrue(notFullStackAssignedCopy.buffer[1] == 2, __LINE__);
    assertTrue(notFullStackAssignedCopy.buffer[2] == 5, __LINE__);
    
    startTestSet("(Not Full) Copy Constructor");
    stack <int> notFullStackCopy(stackToCopy);
    assertTrue(notFullStackCopy.numCapacity == 3, __LINE__);
    assertTrue(notFullStackCopy.numElements == 3, __LINE__);
    assertTrue(notFullStackCopy.buffer != stackToCopy.buffer, __LINE__);
    assertTrue(notFullStackCopy.buffer[0] == 1, __LINE__);
    assertTrue(notFullStackCopy.buffer[1] == 2, __LINE__);
    assertTrue(notFullStackCopy.buffer[2] == 5, __LINE__);
    
    
    
    /*
     * Testing push for Non-Integer Stack Behavior (Just to Make Sure stack Works For Other Types)
     */
    startTestSet("Can Hold Strings");
    stack <std::string> stringStack;
    
    stringStack.push("Hello");
    stringStack.push("It's me");
    stringStack.push("I was wondering");
    assertTrue(stringStack.numCapacity == 4, __LINE__);
    assertTrue(stringStack.buffer[0] == "Hello", __LINE__);
    assertTrue(stringStack.buffer[1] == "It's me", __LINE__);
    assertTrue(stringStack.buffer[2] == "I was wondering", __LINE__);
    
    
    generateTestingReport();
    
    return 0;
}
