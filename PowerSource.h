//
// Created by amit levi on 24/09/2022.
//

#ifndef TASKMANAGER_POWERSOURCE_H
#define TASKMANAGER_POWERSOURCE_H
#endif //TASKMANAGER_POWERSOURCE_H
#include "string"
#include "Task.h"

enum EnergyType{Sustainable,PowerHouse}EnergyType;

template <template<class Power> class TimeLine>
class PowerSource{
private:
    enum EnergyType energyType;
    TimeLine<class Power> PreTimeLine;
    TimeLine<class Power> PostTimeLine;
public:
    PowerSource(TimeLine<class Power> &PostTimeLine,TimeLine<class Power> &PreTimeLine,enum EnergyType energyType);
    void use(Task<class Time,class TimeRange>& task);
    void print();
};

template <template<class Power> class TimeLine>
PowerSource<TimeLine>::PowerSource(TimeLine<class Power> &postTimeLine,TimeLine<class Power> &preTimeLine, enum EnergyType energyType):
        PostTimeLine(PostTimeLine),PreTimeLine(PreTimeLine),energyType(energyType){}

template <template<class Power> class TimeLine>
void PowerSource<TimeLine>::use(Task<class Time,class TimeRange>& task) {
    PreTimeLine-task.
}