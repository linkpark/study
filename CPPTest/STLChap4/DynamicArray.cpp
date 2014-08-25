#include <iostream>

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
};

int main(){
    DynamicArray< int > a(20);
    cout << a.size() <<endl;

    return 0;
}
