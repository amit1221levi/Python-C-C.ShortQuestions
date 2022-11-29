#include <iostream>
#include <map>
#include <vector>



    int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
template<class Iterator,class T>
int count(Iterator it,T t){
    T counter;
    for(;it!=t.end();){
    counter+=it;
    }
    return counter;
}

template<typename Iterator>
Iterator max_element(Iterator begin,Iterator end){
    if(begin==end){
        return end;
    }
    Iterator maximum=begin;
    for(Iterator i=++begin;i!=end;++i){
        if(*i>*maximum){
            maximum=i;
        }
    }
    return maximum;
}
template<class Iterator,class Condition >
bool any_of(Iterator end,Iterator start ,Condition con){
    for(Iterator it=++start;it!=end;it++){
        if(con(*it)){
            return true;
        }
    }
}



