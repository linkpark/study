#include "BridgeStrategy.h"

class Sample::Impl {
public:
    void print(){
        cout << "impl print" <<endl;
    }
};

Sample::Sample():p_(new Impl()){

}

void Sample::print() {
    p_->print();
}

int main(){
    Sample s;
    s.print();    

    return 0;
}

