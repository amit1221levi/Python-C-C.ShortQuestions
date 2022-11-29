#include <iostream>
#include <list>



int SumEvenElements(std::list<int> ls){
    std::list<int>::const_iterator Cur=ls.begin();
    int sum=0;
    for(;Cur!=ls.end();Cur++){
        sum+=*Cur;
        if (Cur==ls.end())
            break;
        Cur++;
    }
    return sum;
}