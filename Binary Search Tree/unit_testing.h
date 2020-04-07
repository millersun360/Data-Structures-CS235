//
//  node_delete.h
//  junk
//
//  Created by Lee Barney on 10/20/18.
//  Copyright © 2018 Lee Barney. All rights reserved.
//

#ifndef unit_testing_delete_h
#define unit_testing_delete_h

#include <math.h>
#include <iostream>
#include <new>

//DON'T EDIT THIS CODE!! IF YOU DO, YOU WILL HATE LIFE.

#ifdef UNIT_TESTING
//This global int variable is used to track calls to delete for unit testing purposes only.
int unit_testing_delete_call_counter = 0;

int asserts_passed = 0;
const char* theTestSetName = NULL;
bool passedFlag = true;

extern int asserts_existing;

void startTestSet(const char* aTestSetName){
    if(theTestSetName != NULL){
        if (passedFlag) {
            std::cout<<"Passed"<<std::endl;
        }
    }
    passedFlag = true;
    std::cout<<"Testing "<<aTestSetName<<"...";
    theTestSetName = aTestSetName;
}
void generateTestingReport(){
    if (passedFlag) {
        std::cout<<"Passed"<<std::endl;
    }
    std::cout<<"\n\nPercentage of Tests Passed:  "<<floor(100*(float)asserts_passed/asserts_existing)<<"%"<<std::endl;
}

#undef assert
void assertTrue(bool passed, int aLineNumber)
{
    if (!passed)
    {
        if(passedFlag){
            std::cout<<std::endl;
        }
        passedFlag = false;
        std::cout<<"\tfailed on line "<<aLineNumber<<std::endl;
    }
    else{
        asserts_passed++;
    }
}

//overloading the delete operator globally.
bool deletingArray = false;
#ifdef __APPLE__
void operator delete(void * p) _NOEXCEPT
#else
void operator delete(void * p)
#endif
{
    free(p);
    if (!deletingArray) {
        unit_testing_delete_call_counter++;
    }
}

#ifdef __APPLE__
void operator delete[]( void* ptr)  _NOEXCEPT
#else
void operator delete[]( void* ptr)
#endif
{
    if(ptr != NULL){
        deletingArray = true;
        unit_testing_delete_call_counter++;
        free(ptr);
        deletingArray = false;
    }
}

void * operator new(size_t size) throw(std::bad_alloc)
{
    void * p = malloc(size);
    return p;
}
#endif /* UNIT_TESTING */
#endif /* unit_testing_delete_h */
