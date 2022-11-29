//
// Created by amit levi on 24/09/2022.
//
#include "ImmediateTask.h"

template<class Time,class TimeRange>
std::string ImmediateTask<Time,TimeRange>::getType() const {
    return "Immediate";
}

template<class Time,class TimeRange>
ImmediateTask<Time, TimeRange>::ImmediateTask
    (const int &id, float power, TimeRange timeRange,Time timeStart):
    Task<Time,TimeRange>(id,power,timeRange,timeStart){}


