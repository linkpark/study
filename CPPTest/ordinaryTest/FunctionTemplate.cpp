#include <iostream>

using namespace std;

template <class I,class T>
void func_impl(I iter,T t){
    //T tmp;
    cout << *iter << endl;
}

template <class I>
inline void func(I iter){
    func_impl(iter,*iter);
}

int main(){
    int i = 1;
    func_impl(&i,i);
    func(&i);

    return 0;
}
