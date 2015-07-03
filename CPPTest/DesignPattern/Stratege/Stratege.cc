#include <iostream>

using namespace std;

class GameCharacter {
public:
    //non virtual interface
    int healthValue() {
        
        //doing something before calling the fucntion
        int retVal = doHealthValue();
        //doing something after calling the function

        return retVal;
    }

private:
    virtual int doHealthValue() const {
        return 3;
    }
};

class DeriveGameCharacter:public GameCharacter {
public:
    DeriveGameCharacter() {};
    ~DeriveGameCharacter() {};

private:
    virtual int doHealthValue() const {
        return 4;
    }
};

int main(){
    GameCharacter *b_class = new DeriveGameCharacter();

    cout << b_class->healthValue() <<endl;

    return 0;
}


