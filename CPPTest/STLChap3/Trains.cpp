#include <iostream>
using namespace std;

template <class T>
class MyIter{
public:
    typedef T value_type;
    T *ptr;
    MyIter(T *p = 0):ptr(p){}
    T& operator*()const{return *ptr;}
};

template <class I>
typename I::value_type
func(I iter){
    return *iter;
}

int main(){
    MyIter<int> myIter(new int(4));
    cout << func(myIter) <<endl;

    return 0;
}

