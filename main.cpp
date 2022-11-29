/* localtime example */
#include <iostream>    /* puts, printf */
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <chrono>
#include <thread>

int main ()
{

}

class Divides{
protected:
    int k;

public:
    class ZERO:public std::exception{
    public:
        ZERO(){
            std::cout<<"Cannot divide by 0!"<<std::endl;
        }
    };
    Divides(int k):k(k){
        if(k==0)std::runtime_error("Ca");
    };
    ~Divides()=default;
    bool operator()(int x){
        return (x%k==0);
    }
};

template<class T>
class Cond{
private:
    T k;
public:
    Cond()=default;
    virtual ~Cond()= default;
    virtual bool operator()(T x) const {
        return true;
    };

};
template <class T>
class CondAnd:public Cond<T>{
protected:
    const Cond<T> t;
    const Cond<T> t2;
public:
    CondAnd(const Cond<T> t,const Cond<T> t2):t(t),t2(t2){}
    bool operator()(T x){
        return t(x)&&t2(x);
    }


};
template <class T>
CondAnd<T> operator&&(const Cond<T>& c1, const Cond<T>& c2) {
    return CondAnd<T>(c1,c2);
}