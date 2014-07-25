#include <iostream>

using namespace std;

int main(){
    int *a = (int *)operator new( sizeof(int) );
    
    *a = 4;
    cout << *a <<endl;

    return 0;
}
