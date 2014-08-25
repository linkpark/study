#include <iostream>

using namespace std;

//自定义迭代器
template <class T>
struct MyIter{
    typedef T value_type;
    T *ptr;
    MyIter(T* p = 0):ptr(p){}
    T& operator*() const{ return *ptr;}
};

//Traits编程技法
template <class T>
class Traits{
public:
    typedef typename T::value_type value_type;
};

template <class T>
class Traits<T*>{
public:
    typedef T value_type;
};

template <class T>
class Traits<const T*>{
public:
    typedef T value_type;
};

template <class I>
typename Traits<I>::value_type
func(I iter){
    return *iter;
}


int main(){
    MyIter< int > p(new int(8));
    const char *ptr = "abce";
    int *a = new int(9);
    cout << func(p) <<endl;
    cout << func(a) <<endl;
    cout << func(ptr) << endl;

    return 0;
}

