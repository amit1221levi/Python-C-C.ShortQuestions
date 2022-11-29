//
// Created by amit levi on 24/09/2022.
//

#ifndef TASKMANAGER_SYSTEM_H
#define TASKMANAGER_SYSTEM_H

#endif //TASKMANAGER_SYSTEM_H
#include <iostream>
#include "Task.h"
#include <vector>
#include <chrono>
template<class Time,class TimeRange>
class System{
private:
    std::vector<std::shared_ptr<Task<Time,TimeRange>>> tasks;
public:
    System();

};