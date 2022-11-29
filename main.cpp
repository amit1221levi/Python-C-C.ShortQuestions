#include <iostream>
#include <string>
#include <fstream>

/*

int main() {

//הקצאת זיכרון דינאמית
    int *n = new int(7);
    delete n;
    int *array = new int[5];
    delete[] array;

//const אם הוא ראשון מתייחס לביטוי שאחריו ולא לשמאלו
    const int e = 5;

//reference כמו מצביע קבוע תמיד לאותו ערך חיי לאתחל בהתחלה
    int a = 9;
    int &r = a;
    return 0;
}
//ערך ברירת מחדל   אם לא הוגדר מספר אחר הבסיס שווה ל10 ערסי בררית מחדל חייבים להיות האחרונים בשליחה לפונקציה
    void print(int n, int base = 10) {
        std::cout << n << base;
    }


//struct
    struct Date {
    private://קוד אשר כתוב מחוץ למבנה לא יכול לגשת לפרייבט
        int day;
        char *month;
        int year;
    public:
        int howManyYearsPass(const Date &date) {
            if (date.year > 2022) {
                std::cout << "this an future date";
                return 0;
            }
            return 2022 - date.year;
        };

        void set(int day,char *month,int year);
    };

    void Date::set(int day,char *month,int year) {
        this->year=year;
        this->month=month;
        this->day=day;
    }
/*
    int main(){
        Date date;
        date.set(12,"kmk",2);
        Date date2={12,"ded",3};
        return 0;
    }
*/
/*
//class
    class Point {
        double x, y;
    public:

        double distance() const{
            return (this->y)*(this->y)+(this->x)*(this->x);
        };

        double operator()(double distance) const;// operator

        Point operator=(const Point& point){//copy operator
            x=point.x;
            y=point.y;
        }

        Point(const Point& point) {
            x = point.x;
            y = point.y;
        }


        Point(double y = 0, double x = 0) {//from here Point.cpp// in main() look like   Point R(4,4);
            this->y = y;
            this->x = x;
        };

        ~Point() {
            delete &x;
            delete &y;
        };
    };




    double Point::operator()(double distanceIncrase) const { // operator
        return this->distance()*distanceIncrase;
    }



//static variable
    int Counter(int n){
        static int counter;//counter=0 utomaticly
        return counter+n;
    }
    int getCounter(int* arr){
        for(arr-2;arr++;)
            Counter(*arr);
        return Counter(*arr++);
    }


//stack.h
template<class T>
class Stack{
        T* data;
        int maxSize;
        int nextIndex;
public:
        Stack(int maxSize);
        ~Stack();
        int getSize() const;
        Stack& operator=(const Stack&);
        void push(T n);
        void pop();
        T& top();
        bool isFull()const;
        bool isEmpty()const;
        class InvalidSize{};
        class IsEmpty{};
        class IsFull{};
    };

//stack.cpp
template <class T>
Stack<T>::Stack(int maxSize) :maxSize(maxSize),nextIndex(0){
    if(maxSize<0)
        throw InvalidSize();
    data = new T[maxSize];
}
template<class T>
Stack<T>::~Stack() {
    delete[] data;
}
template<class T>
void Stack<T>::push(T n) {
    if(this->isFull()){
        throw isFull();
    }
    data[nextIndex++]=n;
}

template <class T>
int Stack<T>::getSize() const {
    return  nextIndex;
}
template <class T>
void Stack<T>::pop() {
    if(this->isEmpty()){
        throw IsEmpty();
    }
    nextIndex--;
}
template <class T>
T& Stack<T>::top() {
    if(this->isEmpty()){
        throw IsEmpty();
    }
    return data[nextIndex-1];
}

template<class T>
bool Stack<T>::isEmpty() const {
    return nextIndex==0;
}

template<class T>
bool Stack<T>::isFull() const {
    return this->getSize()>=maxSize;
}

/*
void copyFile(const char* sourceFileName,const char* targaetFileName){//function to copy file to other file
    std::ifstream  source(sourceFileName);//reading the file
    if(!source){
        std::cerr<<"cannot open the file"<<sourceFileName<<std::endl;
        return;
    }
    std::ofstream target(targaetFileName);
    if(!target){
        std::cerr<<"cannot open the file"<<targaetFileName<<std::endl;
        return;
    }
    while(!source.eof()){
        char c;
        source.get(c);//give a c a value
        target.put(c);//write the value of c inside the file
    }
}


// expectation
class Array{
    int* array;
    int firstValue();
    bool isEmpty(){
       return sizeof (this->array)==0;
    }
    class Empty{};
    class Full{};
    void push(int n);
    void add(int n);
};

int Array::firstValue() {
    if(this->isEmpty())
        throw Empty();
}

void Array::push(int n) {
    if(array+1){
        *array=n;
        array++;
    } else throw Full();
}
void Array::add(int n) {
    try{
        this->push(n);
    }catch (Full){
        std::cerr<<"not enough space on your fucking suck stack";
    }
}

//template
template<class T> // get the max from any array type
T max(const T* array,int size){
    for (int i = 0,max=array[0]; i < size; ++i) {
        if(array[i]>max)
            max=array[i];
    }
    return max;
}
*/

// STL

#include <vector>
int notmain(){
    std::vector<int> vec={2,3};//vec={2,3}
    vec.push_back(5);//vec={2,3,5}
    vec[0];//=3
    std::vector<int> vecCopy=vec;
    vec.pop_back();//vec ={2,3}
    vec.resize(2,4);//vec ={2,3}vec.end()=1 //default->/4,4}
    int counter=0;
    std::vector<int>::iterator iteratorName =vec.begin();// how to brimng an iterator into this bitiful world ;)[--=

    for(std::vector<int>::iterator it =vec.begin(); it!=vec.end();++it){
        static int i=0;
        counter+=vec[i++];//in the end equal to 5
    }

//unique_ptr yuck
    std::unique_ptr<int> pointerName(new int/*the name of the class*/ (3/*constructor*/));
return 0;

}
/*
//inheritence or what ever
#define  MAX 100
class Amit{
public:
    int levl;
    Amit(): levl(MAX), money(MAX) {
        std::cout<<"new Amit\n";
    };
    ~Amit(){
        std::cout<<"the Amit is gone\n";
    }
private:
    int const  money;
};


class King:public Amit{
public:
    King():Amit::Amit(){
        this->levl=4;
        std::cout<<"new king\n";
    }
    ~King(){
        std::cout<<"the king is gone\n";
    }
};

class Slave: public King{
public:
    int money;
    Slave(){
        this->levl=1;
        this->money=3;
        std::cout<<"new slave\n";
    };
    ~Slave(){
        std::cout<<"the slave is gone\n";
    }
};

int main(){
    Slave slave;
    std::cout<<"slave level is "<<slave.levl<<"\n";
    return 0;
}

output:
new Amit
new king
new slave
slave level is 1
the slave is gone
the king is gone
the Amit is gone
 */

/*
//virtual function
class Student{
public:
    Student(){};
    virtual ~Student(){}; ///______________must!______
    void virtual printSkill(){
        std::cout<<"Student skill\n";
    };
    void  printFaculty(){
        std::cout<<"None faculty\n";
    };
};
class CsStudent:public Student{
public:
    char* const skill;
    CsStudent():skill("keyboard killer"){};
    ~CsStudent(){};
    void printSkill(){
        std::cout<<"CS skill "<< this->skill<<"\n";
    }
    void  printFaculty(){
        std::cout<<"Cs faculty\n";
    };
};

int main(){
    CsStudent csStudent;
    Student* student=&csStudent;
    student->printSkill();
    student->printFaculty();
    return 0;
}
*/
/*output:
CS skill keyboard killer
None faculty
*/


// casting
/*
int main(){
    int n=1;
    float f=3.45;
    n=static_cast<int>(f);
    std::cout<<n;
}
//output 3
*/







template <class T>
class TwoWayStack{
private:
    class Node{
    private:
        T data;
         Node* next;
         Node* prev;
    public:
        Node(const T& data);
        Node(const Node& other);
        virtual ~Node();
        friend class TwoWayStack<T>;
        Node& operator=(const Node& other);
    };
    Node* topN;
    Node* bottomN;
public:
   T bottom() const;
   T top() const;
   TwoWayStack(const T& data_head);
   TwoWayStack(const TwoWayStack& towStack);
   void pushTop(const T& node);
   void pushBottom(const T& node);
   void popTop();
   void popBottom();
   size_t size()const;
   friend std::ostream operator<<(std::ostream& sream,const TwoWayStack<T>& stack);
   friend bool operator<(const TwoWayStack& stack1,const TwoWayStack& stack2);
};
template<class  T>
 bool operator<(const TwoWayStack<T> stack1,const TwoWayStack<T> stack2);
template<class  T>
bool operator>=(const TwoWayStack<T> stack1,const TwoWayStack<T> stack2);
template<class T>
std::ostream operator<<(std::ostream& sream,const TwoWayStack<T>& stack);


template<class T>
size_t TwoWayStack<T>::size() const {
    size_t counter =0;
    for (Node node = this->bottomN; node!= this->bottom  ; node=node.next,counter++) ;
    return counter;
}

class TowStackWayEmpty:public std::exception{};
template<class T>
void TwoWayStack<T>::popBottom() {
    if(this->bottom==nullptr){
        throw TowStackWayEmpty();
        return;
    }
    if(this->bottom->prev== nullptr){
        this->bottom= nullptr;
        this->top= nullptr;
        return;
    }
    Node* temp= this->bottom;
    this->bottom= this->bottom->prev;
    delete temp;
}

class Fruit{
public:
        virtual Fruit* clone() const =0;
        virtual ~Fruit()=default;
        virtual bool CheckQuality() const =0;

    };
class factory{
         TwoWayStack<std::shared_ptr<Fruit>> track;
public:
class FruitBadExpectation:public std::exception{};
        void AddFruit(Fruit* pFruit){
            if(!pFruit){
                throw FruitBadExpectation();
            }
            track.pushTop(std::shared_ptr<Fruit>(pFruit->clone()));
        }
        void CheckFruit(){
            try{
                std::shared_ptr<Fruit> f=track.bottom();
                track.popBottom();
            }catch(std::exception& e) {return;}
            std::shared_ptr<Fruit> f*=track.bottom();
            if(f.CheckQuality())
        };

        void AddToGoodFruit(Fruit* f);
        void AddToBadFruit(Fruit* f);



    };