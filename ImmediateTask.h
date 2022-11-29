//
// Created by amit levi on 24/09/2022.
//

#ifndef TASKMANAGER_IMMEDIATETASK_H
#define TASKMANAGER_IMMEDIATETASK_H

#endif //TASKMANAGER_IMMEDIATETASK_H
#include "Task.h"
#include <ctime>
// Task with immediate power need
template<class Time,class TimeRange>
class ImmediateTask:public Task<Time,TimeRange>{
private:

public:
    ImmediateTask(int const& id,float power,TimeRange timeRange,Time timeStart=std::chrono::system_clock::now());
    ~ImmediateTask()=default;
    std::string getType() const override;
};
