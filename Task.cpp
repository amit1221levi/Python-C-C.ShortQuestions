//
// Created by amit levi on 24/09/2022.
//
#include "Task.h"
#include <ostream>

template<class Time,class TimeRange>
Task<Time,TimeRange>::Task(const int &id,float power, TimeRange timeRange,Time timeStart):
id(id),power(power),timeRange(timeRange),timeStart(timeStart){}

template<class Time,class TimeRange>
std::string Task<Time, TimeRange>::getType() const {

}

template<class Time,class TimeRange>
float Task<Time, TimeRange>::totalPower() const {
    return timeRange*power;
}

template<class Time,class TimeRange>
int Task<Time, TimeRange>::Id() const {
    return id;
}

template<class Time,class TimeRange>
void Task<Time, TimeRange>::print(std::ostream &os) const {
    os<<getType()<<" task\n"<<"Id: "<<id<<"\nStart time: "<<timeStart<<"\nTime range: "
    <<timeRange<<"\nTotal power: "<<Power()<<"\n"<<std::endl;
}

template<class Time,class TimeRange>
Time Task<Time, TimeRange>::Time_() const {
    return timeStart;
}

template<class Time,class TimeRange>
TimeRange Task<Time, TimeRange>::Time_Range() const {
    return timeRange;
}

