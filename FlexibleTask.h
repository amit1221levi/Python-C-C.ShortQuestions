//
// Created by amit levi on 24/09/2022.
//

#ifndef TASKMANAGER_FLEXIBLETASK_H
#define TASKMANAGER_FLEXIBLETASK_H

#endif //TASKMANAGER_FLEXIBLETASK_H
#include "Task.h"
#include <chrono>

template<class Time,class TimeRange>
class FlexibleTask:public Task<Time,TimeRange>{
private:
    Time* end;
public:
    FlexibleTask(Time* end,int const& id,float power,TimeRange timeRange,Time timeStart=std::chrono::system_clock::now());
    ~FlexibleTask()=default;
    std::string getType() const override;
    Time* End();
};