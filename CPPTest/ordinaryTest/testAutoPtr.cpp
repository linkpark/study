#include <iostream>
#include <memory>

using namespace std;

class Investment{
public:
    Investment(){
        cout << "create an object" <<endl;
    }

    virtual ~Investment(){
        cout << "delete this object" << endl;
    }
    
    void printInfo(){
        cout << "This is the function of print" <<endl; 
    }

};

Investment* createInvestment(){
    return new Investment();
}

int main(){
    auto_ptr< Investment > pInv( createInvestment() );
    pInv->printInfo();
    pInv.get()->printInfo();
     
    return 0; 
}

