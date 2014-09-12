#include<iostream>
using namespace std;
class test{
public:
    int a;
public:
    test(int c):a(c){}
    int& getA(){
        return a;
    }
};

int main(){
    test b(1);
    int c = b.getA();
    c=2;
    cout << b.a <<endl;

   return 0; 
}
