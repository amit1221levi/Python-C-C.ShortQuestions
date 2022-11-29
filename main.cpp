

#include "Queue.h"
#include "iostream"

#define AGREGATE_TEST_RESULT(res, cond) (res) = ((res) && (cond))


template <class X>
X* Queue<X>::end()
{
    X* a=&arr[backIndex];
    return a;//!!!!!!!! maybe backIndex+1
}

template <class X>
X* Queue<X>::begin()
{
    X* a=&arr[frontIndex];
    return a;
}

// Function to checking if  queue is full or not
template <class X>
bool Queue<X>::full()
{
    if (sizeVar == capacityOFvar)
    {
        return true;
    }else{
        return false;
    }
}

// Find the capacity of queue
template <class X>
int Queue<X>::capacity()
{
    return capacityOFvar;
}

// Find the number of elements present in Queue
template <class X>
int Queue<X>::size()
{
    return sizeVar;
}

// Function to check if Queue is empty or not
template <class X>
bool Queue<X>::empty()
{
    if (frontIndex == -1 && backIndex == -1)
    {
        return true;
    }else{
        return false;
    }
}



// Function to find the front element
// of the queue
template <class X>
X Queue<X>::front()
{
    if (empty())// If queue is empty
    {
        throw string("EmptyQueue");
    }
    return arr[frontIndex];
}

// Function to find the last element
// of the Queue
template <class X>
X Queue<X>::back()
{
    if (empty())
    {
        {
            throw string("Invalidoperation");
        }
        abort();
    }
    return arr[backIndex];
}

// Function to inserting the element to the back end of the queue
template <class X>
void Queue<X>::pushBack(X x)
{
    if (full())
    {
        capacityOFvar = capacityOFvar * 2;  // If the queue is fulling, then double the capacity
        X* temp = new X[capacityOFvar];// Initialize a new array of double size
        if(!temp)
        {
            throw string("bad_alloc");
        }
        for (int k = 0; k < sizeVar; k++)// Copy the elements of the previous array
        {
            temp[k] = arr[k];
        }
        delete[] arr;// Deallocate the memory of previous array
        arr = temp;
    }
    if (empty()) // If size is zero
    {
        frontIndex = backIndex = 0;
        arr[backIndex] = x;
        sizeVar++;
        return;
    }
    backIndex = (backIndex + 1) % capacityOFvar;    // Increment the backIndex
    arr[backIndex] = x;
    sizeVar++;
    return;
}

template <class X>
void Queue<X>::popFront()
{
    if (empty()) // If size is zero
    {
        throw string("Invalidoperation");
    }
    for (int i = 0; i <backIndex; ++i) //  pop the front element//!!!!! maybe < -1  !!!!!!!!!!
    {
        arr[i]=arr[i+1];
    }
    backIndex = (backIndex - 1) % capacityOFvar;
    sizeVar--;
    return;
}

// Function to pop an element from
// front end of the queue
template <class X>
void Queue<X>::pop()
{
    if (empty())    // If queue is empty
    {
        throw string("Invalidoperation");
    }
    if (frontIndex == backIndex)// If there is only one character
    {
        frontIndex = backIndex = -1; // Mark Queue as empty and decrement sizeVar
        sizeVar--;
        return;
    }
    frontIndex = (frontIndex + 1) % capacityOFvar; // Increment frontIndex cyclically using modulo arithmetic
    sizeVar--;
    return;
}





template<typename D , typename B >
Queue<D>  transform (Queue<D> & x , B pred) {

    for(int i=0;i<x.size();i++)
    {
        pred(x.arr[i]);
    }
    return x;
}
template<typename D , typename B >
Queue<D>  filter (Queue<D> & x , B pred) {
    int index = 0;
    D *ar;

    int end=sizeof x;
    for (int  i= 0; i <= end; i++) {

        if (pred(x.arr[i])) {
            ar[index]=x.arr[i];
            index++;
        }
    }
    x.arr=ar;
    return x;
}

//________________________________________________________________________________________________________________________________________
static bool isEven(int n)
{
    return (n % 2) == 0;
}

static void setFortyTwo(int& n)
{
    n = 42;
}

namespace QueueTests {


    bool testQueueMethods() {
        bool testResult = true;

        Queue<int> queue1;
        queue1.pushBack(1);
        queue1.pushBack(2);
        int front1 = queue1.front();
        AGREGATE_TEST_RESULT(testResult, front1 == 1);

        queue1.front() = 3;
        front1 = queue1.front();
        AGREGATE_TEST_RESULT(testResult, front1 == 3);

        queue1.popFront();
        front1 = queue1.front();
        AGREGATE_TEST_RESULT(testResult, front1 == 2);

        int size1 = queue1.size();
        AGREGATE_TEST_RESULT(testResult, size1 == 1);

        return testResult;
    }

    bool testModuleFunctions() {
        bool testResult = true;

        Queue<int> queue3;
        for (int i = 1; i <= 10; i++) {
            queue3.pushBack(i);
        }
        Queue<int> queue4 = filter(queue3, isEven);
        for (int i = 2; i <= 10; i += 2) {
            int front4 = queue4.front();
            AGREGATE_TEST_RESULT(testResult, front4 == i);
            queue4.popFront();
        }

        Queue<int> queue5;
        for (int i = 1; i <= 5; i++) {
            queue5.pushBack(i);
            transform(queue5, setFortyTwo);
            for (Queue<int>::Iterator i = queue5.begin(); i != queue5.end(); ++i) {
                AGREGATE_TEST_RESULT(testResult, (*i == 42));
            }
            return testResult;
        }

        bool testExceptions() {
            bool testResult = true;

            bool exceptionThrown = false;
            Queue<int> queue6;
            try {
                queue6.front() = 5;
            }
            catch (Queue<int>::EmptyQueue &e) {
                exceptionThrown = true;
            }
            AGREGATE_TEST_RESULT(testResult, exceptionThrown);

            exceptionThrown = false;
            Queue<int>::Iterator endIterator = queue6.end();
            try {
                ++endIterator;
            }
            catch (Queue<int>::Iterator::InvalidOperation &e) {
                exceptionThrown = true;
            }
            AGREGATE_TEST_RESULT(testResult, exceptionThrown);

            return testResult;
        }

        bool testConstQueue() {
            bool testResult = true;

            Queue<int> queue5;
            for (int i = 1; i <= 5; i++) {
                queue5.pushBack(42);
            }
            const Queue<int> constQueue = queue5;
            for (Queue<int>::ConstIterator i = constQueue.begin(); i != constQueue.end(); ++i) {
                AGREGATE_TEST_RESULT(testResult, (*i == 42));
            }

            bool exceptionThrown = false;
            Queue<int>::ConstIterator endConstIterator = constQueue.end();
            try {
                ++endConstIterator;
            }
            catch (Queue<int>::ConstIterator::InvalidOperation &e) {
                exceptionThrown = true;
            }
            AGREGATE_TEST_RESULT(testResult, exceptionThrown);

            return testResult;
        }

    }
}