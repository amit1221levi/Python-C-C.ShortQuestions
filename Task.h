//
// Created by amit levi on 24/09/2022.
//
#ifndef TASKMANAGER_TASK_H
#define TASKMANAGER_TASK_H
#endif //TASKMANAGER_TASK_H
#include <string>
#include <iostream>
#include <ctime>
#include <chrono>


//Task
template<class Time,class TimeRange>
class Task{
protected:
    //Task Id
    int const id;
    //Task power calculate needs
    float power;
    //Time Range for complete the task
    TimeRange* timeRange;
    //Time start point
    Time* timeStart;
public:
    Task(int const& id,float power,TimeRange timeRange,Time timeStart=std::chrono::system_clock::now());
    virtual ~Task()=default;
    //Every task type have a different print format
    virtual void print(std::ostream& os) const;
    //Return the id of the task
    int Id() const;
    //Return the complexity calculate of the task
    float Power()const;
    //Return the type of the task
    virtual  std::string getType() const = 0;
    //Return task time range
    TimeRange Time_Range() const;
    //Return task time start
    Time Time_() const;
    //Return the total power task needs
    float totalPower() const;

};











