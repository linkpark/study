#include <iostream>
#include <string>

using namespace std;

//这道题的要点在于在遍历树的过程中，子树长度无论是在先序遍历还是中序遍历中都是一致的
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
    //string pre_order("ABDEGHCFIJ");
    //string in_order("DBGEHACIJF");
    string pre_order;
    string in_order;

    cin >> pre_order;
    cin >> in_order;

    PostOrder(pre_order.c_str(), in_order.c_str(), pre_order.size() );
    cout << endl;
}

