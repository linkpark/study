#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

template<class T>
class DynamicArray{

public:
    typedef T ValueType;
    typedef ValueType* iterator;
    typedef ValueType* pointer;
    typedef ValueType& reference;

private:
    iterator start;
    iterator finish;
    iterator endOfStorage;

protected:
    iterator allocNewRoom(size_t n){
        return new T(n); 
    }

    void fillInitialize(size_t n){
        start = allocNewRoom(n);
        finish = start + n;
        endOfStorage = finish;
    }

    void growRoom(){
        size_t size = finish - start;
        size_t byteSize = size * sizeof(T);
        
        iterator newStart = allocNewRoom(size * 2);
        memcpy(newStart,start,byteSize);
        delete start;
        start = newStart;
        endOfStorage = start + size*2; 
    }
    
public:
    DynamicArray(size_t n){
        fillInitialize(n);        
    }
    
    ~DynamicArray(){
        delete start;
    }

    iterator begin(){
        return start;
    };

    iterator end(){
        return finish;
    };

    size_t size()const{
        return (finish - start);
    } 
    
    size_t length()const{
        return (endOfStorage - start);
    }
    
    void push_back(const T& x){
        if(finish == endOfStorage){
            growRoom();
        }

        *finish = x;
        finish++;
    }

    reference operator [](size_t n){
        return *(start + n);
    }
};

int main(){
    DynamicArray< int > a(1);
    a[0] = 1;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    cout << a[0] << endl;
    cout << a.length() <<endl;

    return 0;
}

