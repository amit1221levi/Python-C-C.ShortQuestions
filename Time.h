//
// Created by amit levi on 25/09/2022.
//

#ifndef TASKMANAGER_TIME_H
#define TASKMANAGER_TIME_H

#endif //TASKMANAGER_TIME_H
template<class T>
class Time{
    T* t;
public:
    Time();
   ~ Time()=default;
   T different(Time* &other);
   bool operator <(Time* other);
};

template<class T>
T Time<T>::different(Time<T>* &other) {
    if(*other->t>t)
        return *other->t-t;
    return t-other->t;
}

template<class T>
class TimeGange{

    };
\