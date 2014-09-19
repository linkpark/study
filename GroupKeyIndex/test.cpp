#include <iostream>
#include <vector>
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
   vector <int> a(4,3);
   vector <int> b(5,4);
    
   cout << a[2] <<endl;
   a = b;
   cout << a[2] << endl;
   
   return 0; 
}
