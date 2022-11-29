//
// Created by amit levi on 24/09/2022.
//
#include "FlexibleTask.h"
template<class Time,class TimeRange>
std::string FlexibleTask<Time,TimeRange>::getType() const {
    return "Immediate";
}

template<class Time,class TimeRange>
FlexibleTask<Time, TimeRange>::FlexibleTask
        (Time* end,const int &id, float power, TimeRange timeRange,Time timeStart):
        Task<Time,TimeRange>(id,power,timeRange,timeStart){
            try {
                if(timeStart+timeRange>end){
                    throw "Mismatch time range";
                }
                end(end);
            } catch (char* alert){
            std::cout<<alert<<"\n"<<std::endl;
            }
        }


template<class Time,class TimeRange>
Time *FlexibleTask<Time, TimeRange>::End() {
    return end;
}