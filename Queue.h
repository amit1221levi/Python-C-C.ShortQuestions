//
// Created by amit levi on 20/05/2022.
//


#include <iostream>;
using namespace std;

// Class defination for queue

template<class T>
class queue{
public:
    queue();
    ~queue();
    void pushBack(const T& value);
    T& front() const;
    void popFront();
    int size() const;
    queue(const queue&);
    queue& operator=(const queue&);=

    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

    class EmptyQueue{};

};