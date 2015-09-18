#include <iostream>
#include <string>

using namespace std;

void PostOrder( const char* pre_order, const char* in_order, int length ) {
    int mid_pos = 0;
    if(length < 1)
        return;

    while( pre_order[0] != in_order[mid_pos] )
        mid_pos++;

    PostOrder( pre_order+1, in_order, mid_pos );
    PostOrder( pre_order+1+mid_pos, in_order+mid_pos+1, length-mid_pos-1);

    cout << pre_order[0];
}

int main(){
    string pre_order;
    string in_order;
    
    cin >> pre_order;
    cin >> in_order;
    
    PostOrder(pre_order.c_str(), in_order.c_str(), pre_order.size() );
    cout << endl;
}

